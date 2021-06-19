QTRSensors qtr;

const uint8_t SensorCount = NUM_SENSORS;
uint16_t sensorValues[NUM_SENSORS];

void setup() {
// configure the sensors
 qtr.setTypeRC();
 qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, NUM_SENSORS);
 qtr.setEmitterPin(7);
 delay(500);
 pinMode(LED_BUILTIN, OUTPUT);
 digitalWrite(LED_BUILTIN, HIGH); // turn on Arduino's LED to indicate we are in calibration mode
 // 2.5 ms RC read timeout (default) * 10 reads per calibrate() call
 // = ~25 ms per calibrate() call.
 // Call calibrate() 400 times to make calibration take about 10 seconds.
 for (uint16_t i = 0; i < 400; i++)
 {
   qtr.calibrate();
 }
 digitalWrite(LED_BUILTIN, LOW); // turn off Arduino's LED to indicate we are through with calibration
 // print the calibration minimum values measured when emitters were on
 Serial.begin(9600);
 for (uint8_t i = 0; i < SensorCount; i++)
 {
   Serial.print(qtr.calibrationOn.minimum[i]);
   Serial.print(' ');
 }
 Serial.println();
 // print the calibration maximum values measured when emitters were on
 for (uint8_t i = 0; i < SensorCount; i++)
 {
   Serial.print(qtr.calibrationOn.maximum[i]);
   Serial.print(' ');
 }
 Serial.println();
 Serial.println();
 delay(1000);
 
// Initialize Pins
pinMode(L_MOTOR1, OUTPUT);
 // Initialize Pins
pinMode(L_MOTOR1, OUTPUT);
pinMode(L_MOTOR2, OUTPUT);
pinMode(R_MOTOR1, OUTPUT);
pinMode(R_MOTOR2, OUTPUT);
}

void loop() {
// Take a reading
uint16_t position = qtr.readLineBlack(sensorValues);

// Compute the error
int error = SETPOINT - position;

// Compute the motor adjustment
int adjust = error*KP + KD*(error - lastError);

// Record the current error for the next iteration
lastError = error;

// Adjust motors, one negatively and one positively
analogWrite(L_MOTOR1, constrain(SET_SPEED - adjust, MIN_SPEED, MAX_SPEED));
analogWrite(L_MOTOR2, 0);
analogWrite(R_MOTOR1, constrain(SET_SPEED + adjust, MIN_SPEED, MAX_SPEED));
analogWrite(R_MOTOR2, 0);
}
