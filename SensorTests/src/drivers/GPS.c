#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<wiringSerial.h>
#include<string.h>
#include<wiringPi.h>
#include<errno.h>
#include<regex.h>
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


	cpOutput = NMEA;
	
	return cpOutput;

}
/*
 * checks if the string is propper length and is $GNGGA
 * Lat 18 - 26,28, Long 30 + 40, 42
 * $GPGGA,092750.000,5321.6802,N,00630.3372,W,1,8,1.03,61.7,M,55.2,M,,*76
 *
 */ 
int nmeaParse(char* nmea)
{
    const char parse[2] = ",";
    char *token;

    regex_t regex; //maybe not needed
    gpsCo = regcomp(&regex,"$GNGGA",0); //maybe not needed
    char Lat[9];
    char Long[10];
    double latitude;
    double longitude;
    char lat = nmea[28];
    char lon = nmea[42];
    

    if(strlen(nmea) >=82){
        if(gpsCo != 0)
        {
            return 0;
        }
        
        for(int j = 0;j<3;j++)
        {
            token = strtok(nmea, parse);
        }
        latitude = atof(token);

        latitude = Latitude(latitude);
        
        for(int k = 0;k<2;k++)
        {
            token = strtok(nmea, parse);
        }
        longitude = atof(token);
        longitude = Longitude(longitude);
        printf("%f %s %f %s\n", Latitude,lat,Longitude,lon);


    }
    else
    {
        return 0;
    }

    return 1;

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







