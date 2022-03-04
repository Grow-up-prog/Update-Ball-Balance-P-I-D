
float jarak() {
  delay(20);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  float t = pulseIn(echo, HIGH);
  float cm = t*0.034/2;
  return cm;
}
