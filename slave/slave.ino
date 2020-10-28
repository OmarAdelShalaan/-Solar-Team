int serial;
static int c = 1;
static int value = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("hello,world!");
  delay(100);
  Serial.println("choose:(t:temperture)(h:hight)");

}
void loop() {
  if (Serial.available() > 0)
  {
    serial = Serial.read();

    if (serial == 116)
    {
      Serial.print("temperture = ");
      delay(5);
      value = Serial.read();
      Serial.println(value);
      c = 0;
    }
    if (serial == 104)
    {
      Serial.print("hight = ");
      delay(5);
      value = Serial.read();
      Serial.println(value);
      c = 0;
    }
  }
  if (c == 0)
  { Serial.println("choose:(t:temperture)(h:hight)");
    c = 1;
  }
}