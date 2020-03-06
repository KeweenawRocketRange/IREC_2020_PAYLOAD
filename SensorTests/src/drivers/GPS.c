#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<wiringSerial.h>
#include<string.h>
#include<wiringPi.h>
#include<errno.h>
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







