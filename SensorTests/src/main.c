/***********************************************
*
*
*
*
*
***********************************************/

#include<stdio.h>
#include<stdlib.h>
#include"/home/pi/C_Files/KRR/IREC_2020_Payload/SensorTests/src/drivers/MPU6050.h"
#include"/home/pi/C_Files/KRR/IREC_2020_Payload/SensorTests/src/drivers/GPSV2.h"
#define MPUADDR 0x68;

int main(){

		float accel = 0;
		getCoord();
		setup(MPUADDR);


while(1){

	accel = read_word_2c(ACCEL_X);

	printf("ACCEL_X: %f\n",accel);
	
}

	return 0;
}
