//#define BLYNK_TEMPLATE_ID "TMPLYccgpAF2"
//#define BLYNK_DEVICE_NAME "Hệ thống đo"
//#define BLYNK_AUTH_TOKEN "oRcb6DG9EcvUlu-2BVLw-WyDQu040ysu"
#include <Wire.h>
//#define BLYNK_PRINT Serial 
//#include <ESP8266WiFi.h> 
//#include <BlynkSimpleEsp8266.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2); 
//float a,f,d;
//char auth[] = "oRcb6DG9EcvUlu-2BVLw-WyDQu040ysu"; 
//char ssid[] = "Hiiii_Wellcome"; 
//char pass[] = "matkhauocua"; 
#define cambien1 D0
#define cambien2 D1
//BlynkTimer timer; 
void setup() 
{ 
//Serial.begin(9600);
//Blynk.begin(auth, ssid, pass);  
//delay(5000); 
pinMode(cambien1,INPUT);
pinMode(cambien2,INPUT); 
//delay (5000); 
lcd.clear(); 
lcd.setCursor(0,0); 
//lcd.print("Vu Van Dat"); 
//lcd.setCursor(0,1); 
//lcd.print("Doan Quoc Cuong"); 
//delay (5000); 
//lcd.clear(); 
} 
void loop() 
{ 
lcd.init(); 
lcd.backlight(); 
lcd.setCursor(6,0); 
lcd.print("DO AN");
lcd.setCursor(0,1); 
lcd.print("THIET KE HT CDT"); 
  int a;
  a= digitalRead(vao);
  if(a == 0)
  { digitalWrite(ra,HIGH);
   };
   if(a == 1)
  { digitalWrite(ra,LOW);
   };
  //Blynk.virtualWrite(V0, f); 
  //Blynk.virtualWrite(V1, d);
  //Blynk.virtualWrite(V2, a);    
  }
