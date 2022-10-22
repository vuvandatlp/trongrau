#include <Wire.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2); 
void setup() {
  // put your setup code here, to run once:
lcd.begin (16, 2);
lcd.init(); 
lcd.backlight(); 
lcd.setCursor(6,0); 
lcd.print("DO AN");
lcd.setCursor(0,1); 
lcd.print("THIET KE HT CDT");
}

void loop() {
  // put your main code here, to run repeatedly:
 

}
