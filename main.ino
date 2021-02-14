/*(C) Liam Letters 2021
Free use for whatever purpose is permitted, provided this copyright comment/segment remains intact*/
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

void print_time(int hrs, int mins, int sec) {
  if(hrs>0){
    lcd.print(hrs);
    lcd.print("hr ");
  }
  if(mins>0){
    lcd.print(mins);
    lcd.print("m ");
  }
  lcd.print(sec);
  lcd.print("s");
}

void loop() {
  lcd.setCursor(0,1); 
  if(counter>59){
    mins++;
    counter=0;
  }
  if(mins>59){
    hrs++;
    mins=0;
  }
  print_time(hrs, mins, counter);
  delay(1000);
  counter++;
}
