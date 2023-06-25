
#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);  

void setup() {
  // put your setup code here, to run once:
 lcd.begin(16,2);
 // print
 lcd.setCursor(1,0);
 lcd.print("LDR. OUT=");
 lcd.setCursor(1,1);
 lcd.print("Light Intensity");
}

void loop() {
  // put your main code here, to run repeatedly:
 int ldr = analogRead(A0);
 lcd.setCursor(10,0);
 lcd.print(ldr); 
}
