#include <QTRSensors.h>
QTRSensors qtr;// intializing thee instance of the class
const uint8_t SensorCount = 8;
uint16_t sensorValues[SensorCount];

float Kp = 0; //set up the constants value
float Ki = 0;
float Kd = 0;
int P;
int I;
int D;

int lastError = 0;
bool onoff = false;

//Increasing the maxspeed can damage the motors - at a value of 255 the 6V motors will receive 7,4 V
const uint8_t maxspeeda = 150;
const uint8_t maxspeedb = 150;
const uint8_t basespeeda = 100;
const uint8_t basespeedb = 100;

//Set up the buttons pins
int buttoncalibrate = 17;
//pin A3
int buttonstart = A3;

// function declaration
void calibration();
void PID();
