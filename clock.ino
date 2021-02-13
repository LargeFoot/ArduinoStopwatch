//(C) Liam Letters, 2021

#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);
int counter=0;
int mins=0;
int hrs=0;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Stopwatch:");
}

void loop() {
  lcd.setCursor(0,1); 
  if(counter>59){
    mins=counter/60; //1 || 59
    int sec=counter-(mins*60);
    if(counter>(60*60)-1){
      int hrs=counter/60/60;
      mins=(counter/60)%60;
      lcd.print(hrs);
      lcd.print("hr ");
    }
    lcd.print(mins); //1
    lcd.print("m ");
    lcd.print(sec);//0, 1, 2 || 
  }else{
    lcd.print(counter);
  }
  lcd.print("s");
  delay(1000);
  counter++;
}
