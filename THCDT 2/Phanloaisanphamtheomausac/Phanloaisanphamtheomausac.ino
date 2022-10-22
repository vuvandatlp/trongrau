#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);
#define nutchay 0
#define nutdung 1
#define chaydung 4
#define dkxilanh1 2
#define dkxilanh2 3
#define S0 6
#define S1 7
#define S2 8
#define S3 9
#define out 10
#define sensor1 11
#define sensor2 12
int R=0;
int G=0;
int B=0;
int color = 0;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(nutchay,INPUT_PULLUP);
pinMode(nutdung,INPUT_PULLUP);
pinMode(chaydung,OUTPUT);
  pinMode(0,INPUT);
pinMode(1,INPUT);
pinMode(5,INPUT);
pinMode(S0,OUTPUT);
pinMode(S1,OUTPUT);
pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);
pinMode(out,INPUT);
pinMode(dkxilanh1,OUTPUT);
pinMode(dkxilanh2,OUTPUT);
lcd.init(); 
lcd.backlight(); 
lcd.setCursor(6,0); 
lcd.print("DO AN");
lcd.setCursor(0,1); 
lcd.print("THIET KE HT CDT");
lcd.clear(); 
lcd.setCursor(0,0); 
lcd.print("Vu Van Dat"); 
lcd.setCursor(0,1); 
lcd.print("Doan Quoc Cuong"); 
delay (5000); 
}

void loop() {
  int buttonStatus = digitalRead(nutchay);
  if (buttonStatus == LOW) {
   digitalWrite(chaydung,HIGH);
  }
  int buttonStatu = digitalRead(nutdung);
  if (buttonStatu == LOW) {
   digitalWrite(chaydung,LOW);
  }
 digitalWrite(S0, LOW);// tần số của tín hiệu đầu ra là 20%
digitalWrite(S1, HIGH);//// tần số của tín hiệu đầu ra là 20%
 color = readColor();
if (color == 1) 
{
  while (digitalRead(sensor1) == 0) 
  {
  color = 0;
  digitalWrite(dkxilanh1,HIGH);
  delay(1000);
  digitalWrite(dkxilanh1,LOW);
  }
}
if (color == 3) 
{
  while (digitalRead(sensor2) == 0) 
  {
  color = 0;
  digitalWrite(dkxilanh2,HIGH);
  delay(1000);
  digitalWrite(dkxilanh2,LOW);
  }
}
if (color == 2) 
{
  if (digitalRead(sensor2) == 0) 
  {
    }
    
}
}

int readColor() {
//------------------------------------------------------------------- Đoc tần số màu đỏ
digitalWrite(S2, LOW);
digitalWrite(S3, LOW);
R = pulseIn(out, LOW);
Serial.print(" R = ");
Serial.print( R  );
//-------------------------------------------------------------------- Đoc tần số màu xanh lá
digitalWrite(S2, HIGH);
digitalWrite(S3, HIGH);
G = pulseIn(out, LOW);
Serial.print(" G = ");
Serial.print( G );
// ------------------------------------------------------------------ Đoc tần số màu xanh dương
digitalWrite(S2, LOW);
digitalWrite(S3, HIGH);
B = pulseIn(out, LOW);
Serial.print(" B = ");
Serial.println( B );

if (R < 170 && R > 160 && G < 450 && G > 430 && B < 320 && B > 300 ) {
color = 1; // Do
lcd.setCursor(5,0);
lcd.print("MAU DO");
lcd.setCursor(0,1);
lcd.print("R=");
lcd.setCursor(2,1);
lcd.print(R);
lcd.setCursor(5,1);
lcd.print("G=");
lcd.setCursor(7,1);
lcd.print(G);
lcd.setCursor(10,1);
lcd.print("B=");
lcd.setCursor(12,1);
lcd.print(B);
}
if ( R < 160 && R > 140 && G < 190 && G > 170 && B < 280 && B > 260 ) {
color = 2; // Vang
lcd.setCursor(5,0);
lcd.print("MAU VANG");
lcd.setCursor(0,1);
lcd.print("R=");
lcd.setCursor(2,1);
lcd.print(R);
lcd.setCursor(5,1);
lcd.print("G=");
lcd.setCursor(7,1);
lcd.print(G);
lcd.setCursor(10,1);
lcd.print("B=");
lcd.setCursor(12,1);
lcd.print(B);

}
if (R < 420 && R > 400 && G < 310 && G > 290 && B < 310 && B > 290 ) {
color = 3; // Xanh luc
lcd.setCursor(2,0);
lcd.print("MAU XANH LUC");
lcd.setCursor(0,1);
lcd.print("R=");
lcd.setCursor(2,1);
lcd.print(R);
lcd.setCursor(5,1);
lcd.print("G=");
lcd.setCursor(7,1);
lcd.print(G);
lcd.setCursor(10,1);
lcd.print("B=");
lcd.setCursor(12,1);
lcd.print(B);

}
return color;
}
