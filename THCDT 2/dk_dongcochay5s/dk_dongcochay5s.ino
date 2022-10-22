#include <Wire.h>
#include <LiquidCrystal.h>
int DC1=3;
int DC2=5;
int nutan1=12;
int nutan2=13;
int nutan3=7;
int en1=2;
int demxung=0;
int sovong=0;
int t=0;
float tocdo;
const int 
LiquidCrystal lcd(rs, rw, en, d4, d5, d6, d7);
void dem()
{
  demxung++;
  }
void setup() {
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(DC1,OUTPUT);
  pinMode(DC2,OUTPUT);
   pinMode(en1,INPUT);
   attachInterrupt(0,dem,RISING);
   Serial.begin(9600);
  // put your setup code here, to run once:
}
void dieukhiendongco()
{
  if(digitalRead(nutan1)==0)
  {
  digitalWrite(DC1,HIGH);
  digitalWrite(DC2,LOW);}
  if(digitalRead(nutan2)==0)
  {
  digitalWrite(DC2,HIGH);
  digitalWrite(DC1,LOW);}
  if(digitalRead(nutan3)==0)
  {
  digitalWrite(DC1,LOW);
  digitalWrite(DC2,LOW);}
  // put your main code here, to run repeatedly:
  }
void loop() {
  dieukhiendongco();
  //time =millis();
  //static uint32_t tnow=0;
  if (millis() - t >= 1000) {
            tocdo = (demxung/10)*60;          
            demxung=0;
            t += 1000;
  }
  lcd.begin(16, 2);
  //sovong = (demxung/10);
  lcd.setCursor(0,0);
  lcd.print("TOC DO: ");
  lcd.setCursor(11,0);
  lcd.print(tocdo);
  //lcd.setCursor(0,1);
  //lcd.print("SO XUNG: ");
  //lcd.setCursor(11,1);
  //lcd.print(demxung);
}
