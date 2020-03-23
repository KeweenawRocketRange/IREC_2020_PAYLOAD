//Header file for MPU6050
//
int setup(int MPUADDR);
int read_word_2c(int addr);

#define ACCEL_X 0x3B
#define ACCEL_Y 0x3D
#define ACCEL_Z 0x3F
#define GYRO_X  0x43
#define GYRO_Y  0x45
#define GYRO_Z  0x47


typedef struct{

  float acX;
  float acY;
  float acZ;
  float gyX;
  float gyY;
  float gyZ;

}MPU6050;
