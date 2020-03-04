#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<wiringSerial.h>
#include<string.h>
#include<wiringPi.h>
void  NMEA_STRING(int BAUD)
{


//	char NMEA [83];
	int fd;
	fd = serialOpen("/dev/serial0" , 9600);
	
	if(fd < 0){printf("fd not valid\n");}	
	if(wiringPiSetup() < 0) {printf("setup failed\n");}
	
	for(int i = 0; i < 10; i++){
	
		printf("\nOut: %d",i);
		
		fflush(stdout);
		serialPutchar(fd,i);
	}
	/*
	if(serialDataAvail(fd) != -1)
	{
		for(int i=0; i<82; i++)
		{
			int val = serialGetchar(fd);
			NMEA[i] = (char)val;
		}
		NMEA[82] = '\0';

	}
	
	*/
//	char* cpOutput =(char *)malloc(sizeof(char)*83);
//	cpOutput = NMEA;
	
	
//	return cpOutput;
	
	

}







