
double Longitude(double longitude);
double Latitude(double latitude);
void NMEA_STRING();
void getCoord();
void interruptTest();
void nmeaParse(char nmea[]);


#define PPS 0

typedef struct{
    double latitude;
    double longitude;

    char* lat;
    char* lon;

}GPS_COORD;
