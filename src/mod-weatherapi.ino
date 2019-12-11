int redLED = D2;

int outsideTemp;

void setup() {
    
  pinMode(redLED, OUTPUT);
  // Subscribe to the integration response event
  Particle.subscribe("hook-response/weatherapi/0", myHandler, MY_DEVICES);
  
}

void myHandler(const char *event, const char *data) {
  // Handle the integration response
  outsideTemp = atoi(data);
}
          

void loop() {
  
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