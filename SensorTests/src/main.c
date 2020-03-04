#include<stdio.h>
#include<stdlib.h>
#include"MPU6050Test.h"
#include"/home/pi/C_Files/KRR/SensorTests/src/drivers/GPS.h"
#define MPUADDR 0x68;

int main(){

	int mpuAddr = MPUADDR;	
	setup(mpuAddr);
	int baudRate = 9600;
	for(int i = 0; i < 1; i++){
		
		NMEA_STRING(baudRate);
		//printf("Accel: %f\n", read_word_2c(0x3B)/16384.0); 
		
	}
	return 0;
}
