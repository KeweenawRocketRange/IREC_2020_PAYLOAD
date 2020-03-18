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


void getCoord(){

  if(wiringPiSetup() < 0)
    fprintf(stderr, "Failed to setup wiringPi.%s"\n",strerror(errno) );

    if( wiringPiISR)
}
