void PID() {
  uint16_t position = qtr.readLineBlack(sensorValues);
  int error = 3500 - position;

  P = error;
  I = I + error;
  D = error - lastError;
  lastError = error;
  int motorspeed = P * Kp + I * Ki + D * Kd;

  int motorspeeda = basespeeda + motorspeed;
  int motorspeedb = basespeedb - motorspeed;

  if (motorspeeda > maxspeeda) {
    motorspeeda = maxspeeda;
  }
  if (motorspeedb > maxspeedb) {
    motorspeedb = maxspeedb;
  }
  if (motorspeeda < 0) {
    motorspeeda = 0;
  }
  if (motorspeedb < 0) {
    motorspeedb = 0;
  }
  //Serial.print(motorspeeda);Serial.print(" ");Serial.println(motorspeedb);
  forward_brake(motorspeeda, motorspeedb);
}

/* The calibration function of the line follower 
 *  for setting up the illumination.
 */
void calibration() {
  digitalWrite(LED_BUILTIN, HIGH);
  for (int i = 0; i < 400; i++)
  {
    qtr.calibrate();
  }
  digitalWrite(LED_BUILTIN, LOW);
}
