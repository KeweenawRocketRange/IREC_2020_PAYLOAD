
void NMEA_STRING();
void getCoord();
void interruptTest();
double Latitude(double latitude);
double Longitude(double longitude);
void nmeaParse(int length, char nmea[]);

typedef struct{

  double latitude;
  double longitude;
  char lat;
  char lon;

}GPS_COORD;
