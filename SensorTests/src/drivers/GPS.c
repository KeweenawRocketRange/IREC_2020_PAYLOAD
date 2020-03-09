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

    double lati;
    double longi;
    char lat[2];
    char lon[2];
    

    if(strlen(nmea) >=82){
        if(gpsCo != 0)
        {
            return 0;
        }
        
        for(int j = 0;j<3;j++)
        {
            token = strtok(nmea, parse);
        }
        lati = atof(token);

        lati = Latitude(lati);
        token = strtok(nmea, parse);
        lat = token;
        token = strtok(nmea, parse);
        
        longi = atof(token);
        longi = Longitude(longi);
        token = strtok(nmea, parse);
        long = token;
        printf("%ld %s %ld %s\n", lati,lat,longi,lon);


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







