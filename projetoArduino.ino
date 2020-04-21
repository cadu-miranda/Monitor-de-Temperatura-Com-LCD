#include <LiquidCrystal.h>

#define rs 12
#define en 11
#define db4 5
#define db5 4
#define db6 3
#define db7 2

LiquidCrystal lcd(rs, en, db4, db5, db6, db7);    

byte cSymbol[8] = {
  B00000,
  B01110,
  B01010,
  B01110,
  B00000,
  B00000,
  B00000,
};
 
void setup(){ 
  
   lcd.createChar(0, cSymbol);
  
   pinMode(10, OUTPUT);
   pinMode(7, OUTPUT);
   
   lcd.begin(16, 2);  
     
   lcd.print("Alarme sonoro"); 
  
   lcd.setCursor(4,1);
   lcd.print("& visual..."); 
  
   delay(2500);
   lcd.clear();
   tone(10,550,100);
                   
}  
 
void loop(){
  
   unsigned int sensorTemp;
   float _sensorTemp;   
  
   sensorTemp = analogRead(A0);
   
   _sensorTemp = ((float) sensorTemp * 5 / 1023) - 0.5; 
   _sensorTemp *= 100;
  
  lcd.setCursor(2,0);
  lcd.print("Temp. atual:");
  lcd.setCursor(0,1);
  lcd.print(_sensorTemp);
  lcd.setCursor(7,1);
  lcd.write(byte(0));
  lcd.setCursor(8,1);
  lcd.print("C");

  if(_sensorTemp >= 30){
    
    lcd.setCursor(9, 1);
    lcd.print(" - PRG!");
    tone(10,2000,250);
    digitalWrite(7, HIGH);   
    }
  
  else {
    
    lcd.setCursor(9, 1);
    lcd.print(" - NRM!");
    digitalWrite(7, LOW);
  }
}
