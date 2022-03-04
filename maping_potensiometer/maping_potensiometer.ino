

float sensorValueA = 0;
float sensorValueB = 0;
float sensorValueC = 0;
float outputA = 0;
float outputB = 0;
float outputC = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(9600);
}
void loop()
{
  // read the input on analog pin 0:
  sensorValueA = analogRead(A0);
  outputA =  map(sensorValueA, 0, 1023, 0, 25);
  // print out the value you read:
  Serial.print("nilai A = ");Serial.println(outputA);
    // read the input on analog pin 1:
  sensorValueB = analogRead(A1);
  outputB =  map(sensorValueB, 0, 1023, 25, 50);
  // print out the value you read
  Serial.print("nilai B = ");Serial.println(outputB);
    // read the input on analog pin 2:
  sensorValueC = analogRead(A2);
  outputC =  map(sensorValueC, 0, 1023, 50, 75);
  // print out the value you read:
  Serial.print("nilai C = ");Serial.println(outputC);
  delay(2); // Delay a little bit to improve simulation performance
}
