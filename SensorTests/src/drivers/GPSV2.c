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
	int bufferSize = 83;

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
		NMEA[82] = '\0';
}
	//char* cpOutput =(char *)malloc(sizeof(char)*83);
	cpOutput = NMEA;
  //nmeaParse(cpOutput);
	printf("Raw Output:\n%s\n",NMEA);

}

void interruptTest(){

	printf("Interrupt Triggered\n");

}

void getCoord(){

	//Sets up wiringPi
  if(wiringPiSetup() < 0)
    fprintf(stderr, "Failed to setup wiringPi.%s",strerror(errno) );

		//Sets up function interrupt
    if( wiringPiISR(PPS,INT_EDGE_RISING, &interruptTest()) > 0){
      fprintf(stderr, "Unable To setup ISR: %s\n",strerror(errno));
    }
}
