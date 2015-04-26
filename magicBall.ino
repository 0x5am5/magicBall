#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switchPin = 6;
int switchPinState = 0;
int previousSwitchPinState = 0;
int reply;

void setup() {
   pinMode(switchPin, INPUT);
  lcd.begin(16, 2) ;
  
  lcd.print("Ask the");
  lcd.setCursor(0, 1);
  lcd.print("Crystal Ball!");
}

void loop() {
  switchPinState = digitalRead(switchPin);
  
  if(switchPinState!=previousSwitchPinState && switchPinState ==LOW) {
    reply = random(8);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("The ball says:");
    lcd.setCursor(0,1);
    
    for(int i=0; i<8; i++) {
      lcd.print(answer(i));
      lcd.setCursor(0,1);
      delay(100);
      lcd.write("                ");
      lcd.setCursor(0,1);
        
    }
    lcd.print("You're a cunt");
  }
  previousSwitchPinState = switchPinState;
}

char* answer(int reply) {
      char* theAnswer;
      switch(reply) {
        case 0:
        theAnswer = "Yes";
        break;
        case 1:
        theAnswer = "Most Likely";
        break;
        case 2:
         theAnswer = "Certainly";
        break;
        case 3:
         theAnswer = "Unsure";
        break;
        case 4:
         theAnswer = "Outlook good";
        break;
        case 5:
         theAnswer = "Ask again";
        break;
        case 6:
         theAnswer = "Doubtful";
        break;
        case 7:
         theAnswer = "No";
        break;
    }
    
    return theAnswer;
}


