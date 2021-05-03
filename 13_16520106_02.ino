#include <LiquidCrystal.h>
LiquidCrystal lcd (7,6,5,4,3,2);
const int ping_Pin = A1;
long dur, cm;

long microsecondsToCentimeters(long microseconds){
  return microseconds/29/2;
}

long read_sensor_ultrasonic(){
  long durasi,jarak;
  
  pinMode(ping_Pin,OUTPUT);
  digitalWrite(ping_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(ping_Pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ping_Pin, LOW);
  
  pinMode(ping_Pin, INPUT);
  durasi = pulseIn(ping_Pin, HIGH);
  jarak = microsecondsToCentimeters(durasi);
  delay(100);
  return jarak;
}

void print_cm(long cm){
  if(cm>100){
     lcd.print("cm");
  }else{
  	 lcd.print("cm ");
  }
}

void setup()
{
  lcd.begin(16,2);
  lcd.print("PING Sensor");
}

void loop()
{
  cm = read_sensor_ultrasonic();
  
  lcd.setCursor(0,1);
  lcd.print("Jarak ");
  lcd.setCursor(6,1);
  lcd.print(cm);
  print_cm(cm);

}






