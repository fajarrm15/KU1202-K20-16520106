const int pingPin =7;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  long durasi,jarak;
  
  pinMode(pingPin,OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);
  durasi = pulseIn(pingPin, HIGH);
  jarak = microsecondsToCentimeters(durasi);
  Serial.print(jarak);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
