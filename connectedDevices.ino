// This #include statement was automatically added by the Particle IDE.
#include <neopixel.h>

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 7
#define PIXEL_TYPE WS2812

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int buttonPin = D3;

long lastPublishedAt = 0; // This value will store the last time we published an event
int publishAfter = 10000; // this is the time delay before we should publish a new event from this device

void setup() {

  // We'll want to subscribe to an event thats fairly unique
  // From the Particle Docs. A subscription works like a prefix filter.
  // If you subscribe to "foo", you will receive any event whose name begins with "foo", including "foo", "fool",
  // "foobar", and "food/indian/sweet-curry-beans".

  // Basically this will match any event that starts with 'db2018/paired/'. This is a feature we'll useto figure out 
  // if our event comes from this device or another (see publishMyEvent below)
  
  Particle.subscribe(  "diot/2019/paired/sthfoodout/" , handleSharedEvent );
  
  pinMode( buttonPin , INPUT_PULLUP); // sets pin as input
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

}

void loop() { //publish my event you'll want some more complex stuff here
int buttonState = digitalRead( buttonPin );

if( buttonState == LOW ){  // turn the LED ON
    publishMyEvent();
    delay(100); // delay for a bit
    }
}


void publishMyEvent()
{
  // Remember that a device can publish at rate of about 1 event/sec,
  // with bursts of up to 4 allowed in 1 second.
  // Back to back burst of 4 messages will take 4 seconds to recover.
  // So we want to limit the amount of publish events that happen.

  // check that it's been 10 secondds since our last publish
 
     if( lastPublishedAt + publishAfter < millis() ) {
      // Remember our subscribe is matching  "db2018/paired/"
      // We'll append the device id to get more specific
      // about where the event came from

      // System.deviceID() provides an easy way to extract the device
      // ID of your device. It returns a String object of the device ID,
      // which is used to identify your device.

      String eventName = "diot/2019/paired/sthfoodout/" + System.deviceID();

      // now we have something like "diot/2019/paired/0123456789abcdef"
      // and that corresponds to this devices info  then we share it out
      Particle.publish( eventName, "food is available" );

      // And this will get shared out to all devices using this code

      // we just pubished so capture this.
      lastPublishedAt = millis();
   }
}

// Our event handlde requires two bits of information
// This gives us:
// A character array that consists of the event name
// A character array that contains the data published in the event we're responding to.
void handleSharedEvent(const char *event, const char *data)
{
    // Now we're getting ALL events published using "db2018/paired/"
    // This includes events from this device.
    // So we need to ignore any events that we sent.

    // Let's check the event name
    String eventName = String( event ); // convert to a string object
    // This gives us access to a bunch of built in methods
    // Like indexOf()
    // Locates a character or String within another String.
    // By default, searches from the beginning of the String,
    // but can also start from a given index,
    // allowing for the locating of all instances of the character or String.
    // It Returns: The index of val within the String, or -1 if not found.

    // We can use this to check if our event name contains the
    // id of this device

    String deviceID = System.deviceID();

    // device id = 0123456789abcdef
    // event = "diot/2019/paired/0123456789abcdef"

    if( eventName.indexOf( deviceID ) != -1 ){
      // if we get anything other than -1
      // the event came from this device.
      // so stop doing stuff
      return;
    }
    
    uint32_t c;
    c = strip.Color(0, 0, 255); // Blue
    rainbow(c);
    // c = strip.Color(255, 0, 0);
    // rainbow(c);
    // c = strip.Color(0, 255, 0);
    // rainbow(c);
    // c = strip.Color(255, 255, 255);
    // rainbow(c);
    // otherwise do your stuff to respond to
    // the paired device here

    //motorOn = true;
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
