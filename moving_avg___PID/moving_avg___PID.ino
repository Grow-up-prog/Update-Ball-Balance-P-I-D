/*
PROGRAM PEMBACAAN DAN MOVING AVG
Septian Saputra
Pendidikan Teknik Elektro
Universitas Negeri Jakarta
percobaan ke -9
*/

//Pendefinisian servo
#include <Servo.h> //library servo
Servo servo; //variabel nama pada servo
//pendefinisian PIN sensor pada arduino
#define trig 9
#define echo 8
float a;
float b;

//MOVING-AVG
const int numReadings = 10;
int readings [numReadings];//  menyimpan  nilai 
int readIndex = 0; //variabel penyimpan nilai
float total = 0; //variabel penjumlahan nilai

//PID 
float kp = 0.01;  //2.5 better 10   15 //untuk mempercepat respon saat ini
float ki = 0.05; //0.4 better 0.1    0.02 //untuk mengecilkan steady state error
float kd = 30; //10 better 30    20 //untuk meminimalisasi osilasi

float priError = 0;
float toError = 0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  servo.attach(4);
  Serial.begin(9600);
  servo.write(86); //86 titik keseimbangan, 86 > kearah kiri (maks kiri 110), 86< kearah kanan (maks 62)  
}
void loop() {
//    a = jarak();
//    Serial.print(a);Serial.println("");
    PID();
}
