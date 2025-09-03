/*
Lab Title and Number: Three Blinking Lights, Lab 1
Name: Fernando Lopez
UIN: 672 257 146
Description: Blinks 4 LED's in total. One event begins with the onboard LED, then red
             LED, then green LED every second. The second event is for the blue lED,
             it blinks every 1.5 seconds a total of 3 times. This lab introduces the
             student to Arduino programming and basic circuitry including the use of
             resistors, negative and positive terminals, and arduino pins.
Assumptions: Use of an Arduino R4, breadboard, 3 220ohm resistors, 1 blue LED,
             1 red LED, 1 green LED, and wires to connect between the arduino
             and the breadboard

References:
https://forum.arduino.cc/t/using-millis-for-timing-a-beginners-guide/483573
https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay/
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

/* dictates state from 0,1,2,0,1,2,etc with board LED,
 * red LED, green LED, board LED, red LED, green LED,etc    */
int currState = 0;

void setup() {

  // sets that we're using pins 2, 10, 12, and 13
  pinMode(twoPin, OUTPUT);
  pinMode(tenPin, OUTPUT);
  pinMode(twelvePin, OUTPUT);
  pinMode(thirteenPin, OUTPUT);

  // starts off almost all of the pins on LOW voltage, practically off.
  digitalWrite(twoPin, LOW);
  digitalWrite(tenPin, LOW);
  digitalWrite(twelvePin, LOW);

  // start the sequence by flipping the onboard LED on
  digitalWrite(thirteenPin, HIGH);
  currState++;

}
 
void loop() {
  
  // check if the 1 second time period passed
  if (millis() >= period + time1) {
    
    // 
    if (currState == 1) {

      // flip onboard off and flip red LED on
       digitalWrite(thirteenPin, !digitalRead(thirteenPin));
       digitalWrite(twelvePin, !digitalRead(twelvePin));
       currState++;
    }
    
    // if red LED on
    else if (currState == 2) {

      // flip red LED off, flip green LED on
      digitalWrite(twelvePin, !digitalRead(twelvePin));
      digitalWrite(tenPin, !digitalRead(tenPin));
      currState++;
    }

    // if green LED on
    else if (currState == 3){

      // flip green LED off, onboard LED on
      digitalWrite(tenPin, !digitalRead(tenPin));
      digitalWrite(thirteenPin, !digitalRead(thirteenPin));
      currState = 1;
    }

    // reset the timer
    time1 = millis();
    
  }

  // 2ND EVENT: check if we passed the 3 second interval
  if (millis() >= period2 + time2) {

    // if the LED hasn't blinked 3 times total
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
