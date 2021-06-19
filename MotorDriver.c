/* This the function of motordriver where the first & third paramters[0,255]
   are for knowing the speed of each motor. The second and fourth(0,1)
   are for Knowing the direction or the movement of the motors.
   for example:
     H_bridge(255,HIGH,0,LOW) // for got to right
     H_bridge(255,LOW,0,HIGH) // for got to left
*/
void H_bridge(int s1, bool d1, int s2, bool d2) {
  analogWrite(MotorIn1, s1 * d1);
  analogWrite(MotorIn2, s1 * !d1);

  analogWrite(MotorIn3, s2 * d2);
  analogWrite(MotorIn4, s2 * !d2);
}



/*void forward_brake(int posa, int posb) {
  //set the appropriate values for aphase and bphase so that the robot goes straight
  digitalWrite(aphase, LOW);
  digitalWrite(bphase, HIGH);
  analogWrite(enbl, posa);
  analogWrite(enbl, posb);
}*/
