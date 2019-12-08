// Author JH
// this code is used for testing a LED to simulate a signal to a 5V 2-channel relay module with the Particle Photon



int redLED = D2;

void setup() {


  pinMode(redLED, OUTPUT);

}


void loop() {
 // turn led on
  digitalWrite(redLED, HIGH);

  // leave on for 1 second
  delay(1000);

  // turn led off
  digitalWrite(redLED, LOW);
 
  // Wait 1 second
  delay(1000);

}

