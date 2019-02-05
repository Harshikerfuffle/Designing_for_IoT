//HARSHIKA JAIN
//built on arduino uno 
#define aref_voltage 3.3 // we tie 3.3V to ARef and measure it with a multimeter!


  int TempSensor = A1;
  int LED_Red = 2;
  int LED_Yellow = 3;
  int LED_White = 4;
  int LED_Green = 5;
  int LED_Blue = 6;
  int TempReading;

void setup()
{
  pinMode(A2, INPUT);
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
  pinMode(LED_White, OUTPUT);
  pinMode(LED_Green, OUTPUT);
  pinMode(LED_Blue, OUTPUT);
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop()
{
  TempReading = analogRead(TempSensor);
  
  // converting that reading to voltage, which is based off the reference voltage
  
  float voltage = TempReading * aref_voltage;
  voltage /= 1024.0; 


  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                               //to degrees ((volatge - 500mV) times 100)
  Serial.print(temperatureC); Serial.println(" degrees C");
  Serial.println(TempReading);
  delay(1000);

  if(temperatureC>=-10 && temperatureC<-7)
  {
    digitalWrite(LED_Blue, HIGH);
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_White, LOW);
    digitalWrite(LED_Yellow, LOW);
    digitalWrite(LED_Red, LOW);
  }
  
  else if(temperatureC>=-7 && temperatureC<-4)
  {
    digitalWrite(LED_Blue, LOW);
    digitalWrite(LED_Green, HIGH);
    digitalWrite(LED_White, LOW);
    digitalWrite(LED_Yellow, LOW);
    digitalWrite(LED_Red, LOW); 
  }

  else if(temperatureC>=-4 && temperatureC<-1)
  {
    digitalWrite(LED_Blue, LOW);
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_White, HIGH);
    digitalWrite(LED_Yellow, LOW);
    digitalWrite(LED_Red, LOW); 
  }

//    else if(temperatureC>=-1 && temperatureC<2)
    else if(temperatureC>=20.8 && temperatureC<23)
  {
    digitalWrite(LED_Blue, LOW);
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_White, LOW);
    digitalWrite(LED_Yellow, HIGH);
    digitalWrite(LED_Red, LOW); 
  }

//    else if(temperatureC>=2 && temperatureC<5)
   else if(temperatureC>=15 && temperatureC<20.8)
  {
    digitalWrite(LED_Blue, LOW);
    digitalWrite(LED_Green, LOW);
    digitalWrite(LED_White, LOW);
    digitalWrite(LED_Yellow, LOW);
    digitalWrite(LED_Red, HIGH); 
  }

  else{
    digitalWrite(LED_Blue, HIGH);
    digitalWrite(LED_Green, HIGH);
    digitalWrite(LED_White, HIGH);
    digitalWrite(LED_Yellow, HIGH);
    digitalWrite(LED_Red, HIGH); 
  } 
}

//CODE CREDITS: https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
