// Define a pin that we'll place the FSR on
// Remember to add a 10K Ohm pull-down resistor too.
int flexPin = A0;
int flexReading = 0; // Create a variable to hold the FSR reading
int ledPin = D2; // Define a pin we'll place an LED on
int ledBrightness = 0; // Create a variable to store the LED brightness.

int piezoPin = D3;
int piezoPitch = 200; 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); //set ledPin as the output pin
  pinMode(piezoPin, OUTPUT);
  
  Particle.variable("force", &flexReading, INT); // Create a cloud variable of type integer called 'light' mapped to photoCellReading
}

void loop() {
  // Use analogRead to read from the sensor
  // This gives us a value from 0 to 4095
  flexReading = analogRead(flexPin);
  //the max value is 1170 and the min is 1100

  // Map this value into the PWM range (0-255)
  // and store as the led brightness
  ledBrightness = map(flexReading, 0, 4095, 0, 255);
  piezoPitch = map(flexReading, 0, 4095, 120, 1500);
  
  if (flexReading > 1110 || flexReading < 1080)
  { 
      tone(piezoPin, piezoPitch, 100);
  }
  else 
  { 
      tone(piezoPin, 0, 10);
  }
  delay(100); // wait 1/10th of a second and then loop
 
 // i stand on the shoulder of giants
