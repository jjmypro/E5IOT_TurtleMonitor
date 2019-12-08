int sensorPin = A0; 
int sensorValue;


void setup() {
  pinMode(sensorPin, INPUT);
  
 // Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  
  if (sensorValue < 2000)
  Particle.publish("Speedy light is ok", String(sensorValue));
  if (sensorValue > 2000)
  Particle.publish("Check Speedy light!", String(sensorValue));


delay(2000);
}