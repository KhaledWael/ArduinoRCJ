extern "C"{
#include "serial_communication.h"
  }
void setup() {
  Serial.begin(9600);
}

void loop() {
  String value;
  value = readSerialData();

  if (value != "") {
    sendSerialData(value);
  }
  delay(500);
}
