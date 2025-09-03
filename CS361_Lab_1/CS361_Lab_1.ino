/*
Lab Number: 1
Name: Fernando Lopez
UIN: 672 257 146
Description: Blinks 4 LED's in total. One event begins with the onboard LED, then red
             LED, then green LED every second. The second event is for the blue lED,
             it blinks

This lab introduces the student to Arduino programming and basic circuitry
             including the use of resistors, negative and positive terminals, and pins.
Assumptions:
References:
*/


// Time interval between the events in milliseconds
const unsigned long period = 1000;

 // variable times for changing states, specifically for alternating LED
unsigned long period2 = 3000;

// the two periods in which the LED will alternate regarding timers
const unsigned long rapidPeriod = 300;
const unsigned long slowPeriod = 1500;

int switchCount = 0; // count the switching of the led

// Named the pins for more intuitive reference
const byte twoPin = 2; // BLUE LED
const byte tenPin = 10; // GREEN LED
const byte twelvePin = 12; // RED LED
const byte thirteenPin = 13; // ONBOARD LED

// timers for the two events
unsigned long time1 = 0;
unsigned long time2 = 0;
unsigned long time3 = 0;

void setup() {

  // sets that we're using pins 2, 10, 12, and 13
  pinMode(twoPin, OUTPUT);
  pinMode(tenPin, OUTPUT);
  pinMode(twelvePin, OUTPUT);
  pinMode(thirteenPin, OUTPUT);

  // starts off all the pins on LOW voltage, practically off.
  digitalWrite(twoPin, LOW);
  digitalWrite(tenPin, LOW);
  digitalWrite(twelvePin, LOW);
  digitalWrite(thirteenPin, LOW);

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

  // 2ND EVENT: check if we passed the 3 second interval
  if (millis() >= period2 + time2) {

    // if the LED hasn't been switched 5 times or blinking 3 times total ie.on,off,on,off,on
    if (switchCount < 5) {

      /*
       * flip the switch to the next the sequence, incremenet the switching count,
        and change it to the faster timer   */
      digitalWrite(twoPin, !digitalRead(twoPin));
      switchCount++;  
      period2 = rapidPeriod;
    }

    // otherwise
    else {
      
      // turn off the LED, reset the switchCount to 0, and make it go slow again
      digitalWrite(twoPin, LOW);
      switchCount = 0;
      period2 = slowPeriod;
      
    }

    // set the time2 as the current time to reset the timer
    time2 = millis();
  }
  

}
