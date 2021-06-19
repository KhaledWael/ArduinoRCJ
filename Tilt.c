// If tilt sensor is moved it will return 1 and vice versa
int tiltSensor() {
  if (digitalRead(tilt_pin) == 1)
  {
    return 1;
  }
  if (digitalRead(tilt_pin) == 0)
  {
    return 0;
  }
}
