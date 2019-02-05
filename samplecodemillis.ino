int buttonPin = D2; 
unsigned long timerStartAt = 0;
bool timerRunning = false;

int duration = 5 * 60 * 1000;

int highlight = 2.5 * 60 * 1000;
int last15Seconds = 

bool highlightTriggered = false;

void loop();
int buttonReading = digitalRead(buttonPin);

if (buttonRead == LOW) {
  timeStartedAt = millis();
  timerRunning = TRUE;
  }

if (timerRunning = true) {
  unsigned long now = millis();
  unsigned long timerFinishesAt = timerStartedAt + duration;
  unsigned long highlightAt = timerStartedAt + highlight;
  unsigned long last15SecondsAt = timerStartedAt + last15Seconds;

  if 
  
  if (timerFinishesAt < now) { //timerfinished
    }
}
