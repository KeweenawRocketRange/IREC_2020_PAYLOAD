/***********************************************
* MPU6050 Driver
* Author - Erik Van Horn
* Keweenaw Rocket Range - IREC_2020_Payload
***********************************************/

#include<stdio.h>
#include<wiringPiI2C.h>
#include<wiringPi.h>
#include<math.h>

#include"/home/pi/C_Files/KRR/IREC_2020_Payload/SensorTests/src/drivers/MPU6050.h"
int fd;
int acclX;

MPU6050 mpu6050;

int setup(int  MPUADDR){

	fd = wiringPiI2CSetup (MPUADDR);
	wiringPiI2CWriteReg8 (fd, 0x6B, 0x00);

	return 0;

}

MPU6050 read_word_2c(int addr){

	int val;
	val = wiringPiI2CReadReg8(fd, addr);
	val = val << 8;
	val += wiringPiI2CReadReg8(fd, addr+1);
	mpu6050.acX = val/16384.0;

	//if(val >= 0x8000)
	//	val = -(65536 - val);

	return mpu6050;

}
