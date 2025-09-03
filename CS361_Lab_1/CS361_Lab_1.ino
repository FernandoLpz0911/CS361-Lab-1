const unsigned long period = 1000; // number of milliseconds

const byte twoPin = 2;
const byte twelvePin = 12;
const byte thirteenPin = 13;

unsigned long time1 = 0;

void setup() {
  pinMode(twoPin, OUTPUT);
  pinMode(twelvePin, OUTPUT);
  pinMode(thirteenPin, OUTPUT);
}
 
void loop() {
  
  // check if the 1 second time period passed or not
  if (millis() >= period + time1) {
    if (digitalRead(thirteenPin) == HIGH) {
       digitalWrite(thirteenPin, !digitalRead(thirteenPin));
       digitalWrite(twelvePin, !digitalRead(twelvePin));
    }
    else if (digitalRead(twelvePin) == HIGH) {
      digitalWrite(twelvePin, !digitalRead(twelvePin));
      digitalWrite(twoPin, !digitalRead(twoPin));
    }
    else if (digitalRead(twoPin) == HIGH){
      digitalWrite(twoPin, !digitalRead(twoPin));
      digitalWrite(thirteenPin, !digitalRead(thirteenPin));
    }
    else {
      digitalWrite(thirteenPin, !digitalRead(thirteenPin));
    }
    time1 += period;
  }
  

}
