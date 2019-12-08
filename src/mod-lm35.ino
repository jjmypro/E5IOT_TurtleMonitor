// Author JH
// this code is used for testing the LM35 temperature sensor with the Particle Photon

int sensorPin = A1; 
int sensorValue;

int temperature;


void setup() {
  pinMode(sensorPin, INPUT);
  
 // Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  
  // calculate temperature for LM35
  temperature = (sensorValue/10)-6;
  
  Particle.publish("Voltage mV at pin A0 is: ", String(sensorValue));
  
  Particle.publish("Temperature Celcius is: ", String(temperature));

delay(3000);
}