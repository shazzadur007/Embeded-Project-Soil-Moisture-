#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0;
int sensorValue = 0;
int percentValue = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop() {

  sensorValue = analogRead(sensorPin);
  Serial.print("\n\nAnalog Value: ");
  Serial.print(sensorValue);
  
  percentValue = map(sensorValue, 1023, 200, 0, 100);
  Serial.print("\nPercentValue: ");
  Serial.print(percentValue);
  Serial.print("%");
  if(percentValue >= 30)
  {
    digitalWrite(13,HIGH);
     digitalWrite(8,LOW);
    lcd.setCursor(0, 0);  
    lcd.print("Moisture Percent: ");
    lcd.setCursor(0, 1);  
    lcd.print(percentValue);
    lcd.print("%");
    delay(2000);
    lcd.clear();
    lcd.print("WOW!!");
    lcd.setCursor(0, 1);  
    lcd.print("I'm Happy now!");
    delay(2000);
    lcd.clear();
    
  }
  else
  {
    digitalWrite(8,HIGH);
     digitalWrite(13,LOW);
     tone(7,1000);
     delay(1000); 
     noTone(7); 
     delay(1000);     
   
    lcd.setCursor(0, 0);
    lcd.print("Water Me Please!");
    delay(1000);
    lcd.clear();
  }
  
  
  
  
  
}
