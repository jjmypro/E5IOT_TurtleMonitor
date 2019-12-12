// Author JH
// this is the code I use for my IOT-TurtleMonitor project

int sensorPinLm35 = A1; 
int sensorValueLm35;
int sensorPinLdr = A0; 
int sensorValueLdr;
int temperature;

// used with weather API
int redLED = D2;
int outsideTemp;


// defines pins numbers for HC-SR04
const int trigPin = D0;
const int echoPin = D1;
// defines variables for HC-SR04
long duration;
int distance;


void setup() {
  pinMode(sensorPinLm35, INPUT);
  pinMode(sensorPinLdr, INPUT);
  // pin modes for HC-SR04
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  // used with weather API
  pinMode(redLED, OUTPUT);
  // Subscribe to the integration response event
  Particle.subscribe("hook-response/weatherapi/0", myHandler, MY_DEVICES);
 // Serial.begin(9600);
}
// used with weather API
void myHandler(const char *event, const char *data) {
  // Handle the integration response
  outsideTemp = atoi(data);
}

void loop() {
  sensorValueLm35 = analogRead(sensorPinLm35);
  
  
  // calculate temperature for LM35
  temperature = (sensorValueLm35/10)-6;
  
  Particle.publish("Voltage mV at pin A1 is: ", String(sensorValueLm35)); // for debugging
  
  Particle.publish("Temperature Celcius is: ", String(temperature)); // for debugging
  
  Particle.publish("lm35", String(temperature), PRIVATE); // for use with webhook
 // Particle.publish({"lm35":String(temperature),"ldr":String(sensorValueLdr)}, PRIVATE); // for use with webhook
  
  delay(3000);
  
  sensorValueLdr = analogRead(sensorPinLdr);
  
  // checking LDR sensor value to know if light is on or off
 
 if (sensorValueLdr < 2000){
  Particle.publish("Speedy light is ok", String(sensorValueLdr)); // for debugging
  }
  else {
  Particle.publish("Check Speedy light!", String(sensorValueLdr)); // for debugging
  }
  
  Particle.publish("ldr", String(sensorValueLdr), PRIVATE); // for use with webhook


delay(3000);

// Clears the trigPin on HC-SR04
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin on HC-SR04, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
//Particle.publish("Temperature Celcius is: ", String(temperature)); // for debugging
//Serial.print("Distance: ");
//Serial.println(distance);

Particle.publish("Distance is: ", String(distance)); // for debugging

Particle.publish("hcsr04", String(distance), PRIVATE); // for use with webhook

delay(3000);


// used with weather API
Particle.publish("weatherapi", PRIVATE);
  
  
  // turn led on
  digitalWrite(redLED, HIGH);

  // leave on for 5 second
  delay(5000);

  if (outsideTemp < 10)
  
  // turn led off
  digitalWrite(redLED, LOW);
 
  // Wait 10 seconds
  delay(10000);

}