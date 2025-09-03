// Time interval between the events in milliseconds
const unsigned long period = 1000;
const unsigned long period2 = 2000; 

// Named the pins for more intuitive reference
const byte twoPin = 2; // BLUE LED
const byte tenPin = 10; // GREEN LED
const byte twelvePin = 12; // RED LED
const byte thirteenPin = 13; // ONBOARD LED

// timers for the two independent events
unsigned long time1 = 0;
unsigned long time2 = 0;

void setup() {

  // sets that we're using pins 2, 10, 12, and 13
  pinMode(twoPin, OUTPUT);
  pinMode(tenPin, OUTPUT);
  pinMode(twelvePin, OUTPUT);
  pinMode(thirteenPin, OUTPUT);
}
 
void loop() {
  
  // check if the 1 second time period passed
  if (millis() >= period + time1) {
    // if the onboard LED is on
    if (digitalRead(thirteenPin) == HIGH) {

      // flip onboard off and flip red LED on
       digitalWrite(thirteenPin, !digitalRead(thirteenPin));
       digitalWrite(twelvePin, !digitalRead(twelvePin));
    }
    
    // if red LED on
    else if (digitalRead(twelvePin) == HIGH) {

      // flip red LED off, flip green LED on
      digitalWrite(twelvePin, !digitalRead(twelvePin));
      digitalWrite(tenPin, !digitalRead(tenPin));
    }

    // if green LED on
    else if (digitalRead(tenPin) == HIGH){

      // flip green LED off, onboard LED on
      digitalWrite(tenPin, !digitalRead(tenPin));
      digitalWrite(thirteenPin, !digitalRead(thirteenPin));
    }

    // start the sequence by flipping the onboard LED on
    else {
      digitalWrite(thirteenPin, !digitalRead(thirteenPin));
    }

    // reset the timer
    time1 = millis();
    
  }

  // check if we passed the 2 second interval
  if (millis() >= period2 + time2) {
    
    // flip the BLUE LED to the opposite of what it is currently.
    digitalWrite(twoPin, !digitalRead(twoPin));

    // set the time2 as the current time to reset the timer
    time2 = millis();
  }
  

}
