/***********************************************
* MPU6050 Driver
* Author - Erik Van Horn
* Keweenaw Rocket Range - IREC_2020_Payload
***********************************************/

#include<stdio.h>
#include<wiringPiI2C.h>
#include<wiringPi.h>
#include<math.h>

int fd;
int acclX;

int setup(int  MPUADDR){

	fd = wiringPiI2CSetup (MPUADDR);
	wiringPiI2CWriteReg8 (fd, 0x6B, 0x00);

	return 0;

}

int read_word_2c(int addr){
	int val;
	val = wiringPiI2CReadReg8(fd, addr);
	val = val << 8;
	val += wiringPiI2CReadReg8(fd, addr+1);

	//if(val >= 0x8000)
	//	val = -(65536 - val);

	return val;

}
