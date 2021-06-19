#include <QTRSensors.h>

#define SETPOINT    3500  // The goal for readLine (center)
#define KP          0.2   // The P value in PID
#define KD          1     // The D value in PID
#define L_MOTOR1     6     // Left motor pin
#define L_MOTOR2     5     // Left motor pin
#define R_MOTOR1     11    // Right motor pin
#define R_MOTOR2     10    // Right motor pin
#define MAX_SPEED   150   // The max speed to set motors to
#define SET_SPEED   150   // The goal speed to set motors to
#define MIN_SPEED   0     // The min speed to set motors to
#define NUM_SENSORS 8     // The number of QTR sensors
#define TIMEOUT     2500  // Timeout for the QTR sensors to go low
#define EMITTER_PIN 2     // Emitter pin for QTR sensor emitters

// PID **************************************
int lastError = 0;  // For storing PID error
QTRSensors qtr;

const uint8_t SensorCount = NUM_SENSORS;
uint16_t sensorValues[NUM_SENSORS];
