
int led = 3;
int sensor = 8;

int val = 0;
void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);

}

void loop() {
  val = digitalRead(sensor);   // read sensor value
  if (val > 0 ) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH); 
    delay(10000)  // turn LED ON
  
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
                // delay 200 milliseconds 
      
  
 }
}
