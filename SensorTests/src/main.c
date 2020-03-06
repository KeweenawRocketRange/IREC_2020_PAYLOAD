#include<stdio.h>
#include<stdlib.h>
#include"MPU6050Test.h"
#include"/home/pi/C_Files/KRR/SensorTests/src/drivers/GPS.h"
#define MPUADDR 0x68;

int main(){

	int mpuAddr = MPUADDR;	
	setup(mpuAddr);

	char* cpOut = ((char*)malloc(sizeof(char)*83));
	for(int i = 0; i < 1; i++){
		
		printf("%s\n", NMEA_STRING(cpOut));
		//printf("Accel: %f\n", read_word_2c(0x3B)/16384.0); 
		
	}
	return 0;
}
