const unsigned long period = 1000; // number of milliseconds
const unsigned long period2 = 2000; 

const byte twoPin = 2;
const byte tenPin = 10;
const byte twelvePin = 12;
const byte thirteenPin = 13;

unsigned long time1 = 0;
unsigned long time2 = 0;

void setup() {
  pinMode(twoPin, OUTPUT);
  pinMode(tenPin, OUTPUT);
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
      digitalWrite(tenPin, !digitalRead(tenPin));
    }
    else if (digitalRead(tenPin) == HIGH){
      digitalWrite(tenPin, !digitalRead(tenPin));
      digitalWrite(thirteenPin, !digitalRead(thirteenPin));
    }
    else {
      digitalWrite(thirteenPin, !digitalRead(thirteenPin));
    }
    time1 += period;
    
  }
  if (millis() >= period2 + time2) {
    digitalWrite(twoPin, !digitalRead(twoPin));
    time2 += period2;
  }
  

}
