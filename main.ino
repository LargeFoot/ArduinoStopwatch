//(C) Liam Letters, 2021

#include <LiquidCrystal.h>

//Creates a LiquidCrystal object and specifies the pins on the Arduino board being used
LiquidCrystal lcd(2,3,4,5,6,7);
//These variables have to be created outside of the voids in order to avoid errors
int counter=0;
int mins=0;
int hrs=0;

void setup() {
  //Lays out the dimensions of the LCD (varies by LCD display)
  lcd.begin(16,2);
  //Cursor goes to the top-left corner before writing "Stopwatch:"
  lcd.setCursor(0,0);
  lcd.print("Stopwatch:");
}

void loop() {
  //Goes to bottom line of display
  lcd.setCursor(0,1);
  //If the counter (the number of seconds) passes 59 seconds, the minute counter is created and initially set to 1
  if(counter>59){
    mins=counter/60;
    int sec=counter-(mins*60);
    //This whole section is a mess. I was extremely tired while creating this and I'll get round to cleaning it up at some point
    if(counter>(60*60)-1){
      int hrs=counter/60/60;
      mins=(counter/60)%60;
      lcd.print(hrs);
      lcd.print("hr ");
    }
    lcd.print(mins);
    lcd.print("m ");
    lcd.print(sec);
  }else{
    lcd.print(counter);
  }
  lcd.print("s");
  //Waits a second before adding another second to the stopwatch counter
  delay(1000);
  counter++;
}
