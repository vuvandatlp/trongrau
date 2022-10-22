#define nutchay 0
#define nutdung 1
#define chaydung 4
void setup() {
  // put your setup code here, to run once:
pinMode(nutchay,INPUT_PULLUP);
pinMode(nutdung,INPUT_PULLUP);
pinMode(chaydung,OUTPUT);
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  int buttonStatus = digitalRead(nutchay);
  if (buttonStatus == LOW) {
   digitalWrite(chaydung,HIGH);
  }
  int buttonStatu = digitalRead(nutdung);
  if (buttonStatu == LOW) {
   digitalWrite(chaydung,LOW);
  }
  }
