#include <LiquidCrystal.h>
#include <Servo.h>

Servo servo;  // create servo object to control a servo. twelve servo objects can be created on most boards
int buttonPin = 7;
const int servoPin = 9;
int pos = 0;    // variable to store the servo position

int duration = 2 * 1000;
unsigned long tStartedAt = 0;
bool timerRunning = false;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 =2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  servo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  // myservo.write(90);  // set servo to mid-point
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  lcd.begin(16, 2);
//  lcd.display();
}

void loop() {
  
  int buttonReading = digitalRead(buttonPin);

  if (buttonReading == LOW && timerRunning == false) {
    tStartedAt = millis();
    timerRunning = true;
  }

  if (tStartedAt + duration <= millis() && timerRunning == true) {
    servo.write(pos * 22);
    tStartedAt = millis();
    pos = pos + 1;

    if (pos == 2) {
      Serial.println("please replace the water 2");
      lcd.setCursor(0,0);
      lcd.print("replace water");
      
    } 

    if (pos == 3) {
      lcd.clear();
    }

    if (pos == 4) {
      Serial.println("please replace the water 4");
      lcd.setCursor(0,0);
      lcd.print("replace water");
    }
    
    if (pos == 5) {
      lcd.clear();
    }
    
    if (pos == 6) {
      Serial.println("please replace the water 6");
      lcd.setCursor(0,0);
      lcd.print("replace water");
    }
  
    if (pos == 7) {
      lcd.clear();
    }

    if (pos >= 8) {
      servo.write(0);
      pos = 0;
      timerRunning = false;
      
      Serial.println("please replace the water 8");
      Serial.println("please refill the fish food");
      
      lcd.setCursor(0,0);
      lcd.print("replace water");
      
      lcd.setCursor(0,1);
      lcd.print("refill fish food");
    }
  }
}

special thanks to Robert Zacharias for helping me out with this piece of code
