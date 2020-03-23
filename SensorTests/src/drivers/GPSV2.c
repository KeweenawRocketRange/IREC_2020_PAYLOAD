/*
  This is a revision of GPS.c

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<wiringSerial.h>
#include<string.h>
#include<wiringPi.h>
#include<errno.h>
#include<regex.h>

//GPIO 0, pin 11
#define PPS 0

void NMEA_STRING()
{

	char NMEA [83];
	int fd;

	//Size of typical NMEA message ( 83 characters )
	int bufferSize = 67;

	if((fd = serialOpen("/dev/serial0",38400)) < 0){
		fprintf(stdout, "Could not open file fd.");
	}

	//If char available to be read, returns the # of available characters
	if(serialDataAvail(fd) > 0){

		for(int i=0; i<bufferSize+1; i++)
		{
			int val = serialGetchar(fd);
			NMEA[i] = (char)val;
		}
		NMEA[66] = '\0';
        }


        if(strstr(NMEA,"GNRMC") != NULL){
            printf("coords\n");
						nmeaParse(67,NMEA);
        }
        serialFlush(fd);

	//char* cpOutput =(char *)malloc(sizeof(char)*83);
  //nmeaParse(cpOutput);
	printf("Raw Output:\n%s\n",NMEA);

}


double Latitude(double latitude)
{
        int degrees = (int)(latitude/100);                                                                                                                                                                   latitude = degrees + ((latitude - (degrees * 100)) / 60);                                                                                                                                            return latitude;
}
double Longitude(double longitude)
{
        int degrees = (int)(longitude/100);                                                                                                                                                                  longitude = degrees + ((longitude - (degrees * 100)) / 60);                                                                                                                                          return longitude;
}


// $GNRMC,020140.00,A,4635.03299,N,09053.51484,W,0.053,,230320,,,A,V*01
void nmeaParse(int length, char nmea[])
{
    const char parse[2] = ",";
    char *token;

		GPS_COORD data;

    token = strtok(nmea,parse);
    printf("Token: %s\n",token);
    token = strtok(NULL, parse);
    printf("Token: %s\n",token);
    strtok(NULL, parse);


    data.latitude = Latitude(atof(strtok(NULL,parse)));
    data.lat = strtok(NULL, parse);


    data.longitude = Longitude(atof(strtok(NULL,parse)));
    data.lon = strtok(NULL, parse);
    printf("%f %s %f %s\n", data.latitude,data.lat,data.longitude,data.lon);
    //printf("String compare failed\n");

}







void interruptTest(){

	printf("Interrupt Triggered\n");

}

void getCoord(){

	//Sets up wiringPi
  if(wiringPiSetup() < 0){
    fprintf(stderr, "Failed to setup wiringPi.%s",strerror(errno) );
	}
		//Sets up function interrupt
    if( wiringPiISR(PPS,INT_EDGE_RISING, &NMEA_STRING) > 0){
      fprintf(stderr, "Unable To setup ISR: %s\n",strerror(errno));
    }
}
