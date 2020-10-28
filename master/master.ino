//***********
int Ultra_sonic();
const int trigPin = 10;
const int echoPin = 9;
long duration;
int distance;
static int ultraSonic;
//**************
int temp();
const int sensorPin = A0;
int reading;
float voltage;
float temperatureC;
static int temp_m;
//*********
static char serial;
void setup() {
  //*********
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  //*********
  Serial.begin(9600);
  //**********

}
void loop() {
  if (Serial.available() > 0)
  {
    serial = Serial.read();
    if (serial != 104 or serial != 116)
      loop();
    if (serial == 104) {
      Serial.write(serial);
      ultraSonic = Ultra_sonic();
      Serial.write(ultraSonic);
    }
    else if (serial == 116) {
      Serial.write(serial);
      temp_m = temp();
      Serial.write(temp_m);
    }
  }
}
int Ultra_sonic() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
int temp() {
  reading = analogRead(sensorPin) ;
  reading = constrain(reading, 840, 970);
  temperatureC = map(reading , 840, 970, -40, 125);
  return temperatureC;
  //return reading;
}
