// reading the serial port coming from raspberry pi
String readSerialData() {
  String value = "";
  if (Serial.available()) {
    delay(10);
    while (Serial.available() > 0) {
      value += (char)Serial.read();
    }
    Serial.flush();
  }
  return value;
}

void sendSerialData(String value) {
  Serial.print("Arduino");
  Serial.print(" received : ");
  Serial.print(value);
}
