// QUICK STARTUP: THIS CONTAINS MULTIPLE CODE OPTIONS
// PLEASE DON'T COPY PASTE AS IS :) and you're good to go

//Make Neopixel increment and then final state is strip.Color(0,0,255)

#include <neopixel.h>

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 7
#define PIXEL_TYPE WS2812
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
    
strip.begin();
strip.show(); // Initialize all pixels to 'off'
}

void loop() {
   uint16_t i;
   uint32_t c = strip.Color(0, 0, 255); // Blue
    
   for( int i = 0; i < strip.numPixels(); i++ ){
   strip.setPixelColor(i, c); // set a color 
   strip.show();
   delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
   }
   delay( 100 );
  
   
 /*________________________________________________________________________________*/  
 
//Modify the code to light up pixel by pixel then reverse the sequence turning each pixel off one by one
// there are 2 ways to do this, basically it is a difference in the for loop application. 
// METHOD 1 

// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 7
#define PIXEL_TYPE WS2812
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
    
strip.begin();
strip.show(); // Initialize all pixels to 'off'
}

void loop() {
   uint16_t i;
   uint32_t c = strip.Color(0, 0, 255); // Blue
    
   for( int i = 0; i < strip.numPixels(); i++ ){
   strip.setPixelColor(i, c); // set a color 
   strip.show();
   delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
   }
   delay( 100 );
   
   c = strip.Color(0, 0, 0); // White
   for( int i = strip.numPixels()-1; i >= 0 ; i-- ){
   strip.setPixelColor(i, c); // set a color 
   strip.show();
   delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
   }
   delay( 100 );
}

// METHOD 2
//MODIFY THE SECOND FOR LOOP

void loop() {
   uint16_t i;
   uint32_t c = strip.Color(0, 0, 255); // Blue
    
   for( int i = 0; i < strip.numPixels(); i++ ){
   strip.setPixelColor(i, c); // set a color 
   strip.show();
   delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
   }
   delay( 100 );
   
   for( int i = strip.numPixels()-1; i >= 0 ; i-- ){
   strip.setPixelColor(i, !c); // set to not a color 
   strip.show();
   delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
   }
   delay( 100 );
}

/*________________________________________________________________________________*/  
 
// Modify the code to light up blue, then red, then green then white in sequence
// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 7
#define PIXEL_TYPE WS2812
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
    
strip.begin();
strip.show(); // Initialize all pixels to 'off'
}

void loop() {
   uint32_t c;
   
   c = strip.Color(0, 0, 255); // Blue
   rainbow(c);
   c = strip.Color(255, 0, 0);
   rainbow(c);
   c = strip.Color(0, 255, 0);
   rainbow(c);
   c = strip.Color(255, 255, 255);
   rainbow(c);
}

void rainbow(uint32_t c){
    
    for( int i = 0; i < strip.numPixels(); i++ ){
     strip.setPixelColor(i, c); // i= which led to light up, c= set a color 
     strip.show();
     delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
     }
   delay( 100 );
   
   
   for( int i = strip.numPixels()-1; i >= 0 ; i-- ){
     c = strip.Color(0, 0, 0); // White
     strip.setPixelColor(i, c); // set a color 
     strip.show();
     delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
   }
   delay( 100 );
}
 
// special thanks to Parag Gangil
