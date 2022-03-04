
void PID() {
  b = filter();
  Serial.print(b);Serial.println("");  
  float setP = 15;
  float error = setP - b;

//  Serial.print("nilai P + I + D  ");
  float Pvalue = error * kp;
  float Ivalue = toError * ki;
  float Dvalue = (error - priError) * kd;
  //Serial.print(Pvalue);Serial.print(" ");Serial.print(Ivalue);Serial.print(" ");Serial.println(Dvalue);
  float PIDvalue = Pvalue + Ivalue + Dvalue;
  priError = error;
  toError += error;
  //pembatasan nilai total error
  if(toError>=200){
    toError=200;
  } else if(toError<=-200){
    toError=-200;
  }
  //Serial.print("total error = ");Serial.println(toError);
  
  //Serial.println(PIDvalue);
  float Fvalue = PIDvalue;

  Fvalue = map(Fvalue, -14, 14, 100, 72);
  if (Fvalue < 72) {
    Fvalue = 72;
  }
  if (Fvalue > 100) {
    Fvalue = 100;
  }
  Serial.print("nilai Fvalue = ");Serial.println(Fvalue);
  servo.write(Fvalue);
}
