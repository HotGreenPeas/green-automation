
#define AOUT_PIN A0 // Arduino pin that connects to AOUT pin of moisture sensor
#define THRESHOLD 100 // CHANGE YOUR THRESHOLD HERE


const int motorPin1  = 9; // Pin  7 of L293
const int motorPin2  = 8;  // Pin  2 of L293


void setup() {
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
}

void loop() {
  int value = analogRead(AOUT_PIN); // read the analog value from sensor

  if (value < THRESHOLD){
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    delay(500); 
  }
    Serial.print("The soil is DRY (");
  else{
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    delay(500);    
  {
  
    delay(15); //delay 15ms
  }
    Serial.print("The soil is WET (");

  Serial.print(value);
  Serial.println(")");
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);

  delay(500);
}





