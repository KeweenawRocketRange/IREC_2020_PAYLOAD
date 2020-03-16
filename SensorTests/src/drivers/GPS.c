#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<wiringSerial.h>
#include<string.h>
#include<wiringPi.h>
#include<errno.h>
#include<regex.h>
double Latitude(double latitude);
double Longitude(double longitude);
void nmeaParse(char* nmea);
char*  NMEA_STRING(char* cpOutput)
{

	char NMEA [83];
	int fd;
	
	if((fd = serialOpen("/dev/serial0",38400)) < 0){

		fprintf(stdout, "Could not open file fd.");

	}

	if(serialDataAvail(fd) != -1)
	{
		for(int i=0; i<82; i++)
		{
			int val = serialGetchar(fd);
			NMEA[i] = (char)val;
		}
		NMEA[82] = '\0';

	}
	
	//char* cpOutput =(char *)malloc(sizeof(char)*83);

        nmeaParse(NMEA);

	cpOutput = NMEA;
	
	return cpOutput;

}
/*
 * checks if the string is propper length and is $GNGGA
 * Lat 18 - 26,28, Long 30 + 40, 42
 * $GNGGA,092750.000,5321.6802,N,00630.3372,W,1,8,1.03,61.7,M,55.2,M,,*76
 *
 */ 
void nmeaParse(char* nmea)
{
    const char parse[2] = ",";
    char *token;

    double lati;
    double longi;
    char *lat;
    char *lon;
    int boolean = 0;
    char check1[6];
    char check[] = "$GNGGA";
    for (int j = 0;j<6;j++){
	    check1[j] = nmea[j];
    }
    for(int i = 0; i<6;i++){
	if(strcmp(check1,check) == 0){
		boolean = 1;
	}
	else
	{
		boolean = 0;
	}
    }
    printf("%d %s\n",boolean,check1);
    if(boolean==1){

        token = strtok(nmea,parse);
        token = strtok(NULL, parse);
        lati = atof(strtok(NULL, parse));

        lati = Latitude(lati);
        lat = strtok(NULL, parse);

        longi = atof(strtok(NULL, parse));
        longi = Longitude(longi);
        lon = strtok(NULL, parse);
        printf("%f %s %f %s\n", lati,lat,longi,lon);
    }else{
	printf("String compare failed\n");
    }
}
double Latitude(double latitude)
{
    int degrees = (int)(latitude/100);
    latitude = degrees + ((latitude - (degrees * 100)) / 60);
    return latitude;
}
double Longitude(double longitude)
{
    int degrees = (int)(longitude/100);
    longitude = degrees + ((longitude - (degrees * 100)) / 60);
    return longitude;
}







