int led1 = D2;
int led2 = D3; 
int led3 = D4;

void setup() {
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 
 digitalWrite(led1, LOW);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 
 Particle.function("led1", ledControl1); //Register our Particle function here
 Particle.function("led2", ledControl2);
 Particle.function("led3", ledControl3);
}

void loop() 
{
}

//--------------------------------   
int ledControl1(String command){
   int state = LOW;
	
   if(command == "HIGH")
   { state = HIGH;}// find out the state of the led
	
   else if(command == "LOW")
   { state = LOW;}
	
   else
   { return -1;}
   
   digitalWrite(led1, state); // write to the appropriate pin
   return 1;
}
//--------------------------------   
int ledControl2(String command){
  int state = LOW;
   
  if(command == "HIGH")
  { state = HIGH;}// find out the state of the led
   
  else if(command == "LOW")
  { state = LOW;}
   
  else
  { return -1;}
   
  digitalWrite(led2, state);
  return 1;
 }
 
//--------------------------------      
int ledControl3(String command){
  int state = LOW;
   
  if(command == "HIGH")
  { state = HIGH;}// find out the state of the led
   
  else if(command == "LOW")
  { state = LOW;}
   
  else
  { return -1;}

  digitalWrite(led3, state);
  return 1;
}
