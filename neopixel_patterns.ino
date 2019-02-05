// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

// On startup:
   // Fade up all of the LEDS i.e. progressively turn on all of the LEDs, one by one.
 
// When the timer is running it should:
   // Map the time remaining to the number of LEDs illuminated, e.g. after 2.5 minutes half the LEDs should be off.
   // When one minute is remaining change the color of the LEDs to red.
   // When 15 seconds is remaining flash or pulse the LEDs
   // Flash all of the LEDS five times to indicate the time has completely elapsed.

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 7
#define PIXEL_TYPE WS2812
 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int brightness = 0;
int buttonState = LOW;
unsigned long lastFade = 0;
int ledPin = PIXEL_PIN;
int buttonPin = D3;
long clockTime = 12000;

void setup() {

strip.begin();
strip.show(); // Initialize all pixels to 'off'
uint16_t i;

for( int i = 0; i < strip.numPixels(); i++ ){
    uint32_t c = strip.Color(0, 0, 255); // Blue
    strip.setPixelColor(i, c);  // set a color 
    strip.show();
    delay( 100 );  // update each pixel one by one, and wait 100 ms in between each update
    }
delay( 100);
}


void loop() {
  analogWrite( ledPin, brightness );
  unsigned long now;
  now = millis();
       
  while ((clockTime - millis()) >= 10) {
      uint32_t c;
      int lightNumber = (millis() / clockTime) * strip.numPixels();
      for (int i = 0; i<lightNumber; i++){
          c = strip.Color(255, 0, 0); 
          strip.setPixelColor(i,c);
          strip.show();
          delay(100);
          }
      delay(100);
      }
}


//   if( buttonState == LOW ){ // turn the LED On
//   digitalWrite( ledPin, HIGH);
//   uint32_t c;
//   c = strip.Color(0, 255, 0); 
//   strip.setPixelColor(0,c);
//   strip.show();
//   }
  
//   else{
//     // otherwise
//     // turn the LED Off
//     digitalWrite( ledPin, LOW);
//     uint32_t c;
//     c = strip.Color(255, 255, 0); 
//     strip.setPixelColor(0,c);
//     strip.show();

//   }
// }

//   if( buttonState == LOW ) {
//       brightness = 255; // set the brightness to full
//       digitalWrite( ledPin, HIGH); // turn the LED On
// 	}
	
//   else{
//       analogWrite( ledPin, brightness );
//       unsigned long now;
//       now = millis();
       
//       // When the timer is running it should:
//       // Map the time remaining to the number of LEDs illuminated, e.g. after 2.5 minutes half the LEDs should be off.
  
//       if ((now - lastFade) >= 10000) {
//         //   if( brightness > 0 ){ // if we haven't yet reached off or zero... then fade
//         //   brightness = brightness - 1; // take one away from the brightness
//           for (int i = strip.numPixels()-3; i >= 0; i--){
//               c = strip.Color(0, 0, 0); 
//               strip.setPixelColor(i,c);
//               strip.show();
//               delay(100);
//               }
//           delay(100);
       
        
//       if(10000 > (now - lastFade) && (now - lastFade) >= 20000) {   // When one minute is remaining change the color of the LEDs to red.
//             for (int j = 0; j < strip.numPixels(); j++){
//                 c = strip.Color(255, 0, 0); 
//                 strip.setPixelColor(j,c);
//                 strip.show();
//                 delay(100);
//                 }
//             delay(100);
        
//         // When 15 seconds is remaining flash or pulse the LEDs
//         if(20000 > (now - lastFade) && (now - lastFade) >= 35000) {
//             for( int i = 0; i < strip.numPixels(); i++ ){
//                 strip.setPixelColor(i, c); // i= which led to light up, c= set a color 
//                 strip.show();
//                 delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
//                 }
//             delay( 100 );
            
//             for( int i = strip.numPixels()-1; i >= 0 ; i-- ){
//                 c = strip.Color(0, 0, 0); // White
//                 strip.setPixelColor(i, c); // set a color 
//                 strip.show();
//                 delay( 100 ); // update each pixel one by one, and wait 100 ms in between each update
//                 }
//           delay( 100 );
           
//       lastFade = now;
//         }
//     }
// }
// }
// }

   
  
