//L293D

//Motor B
const int motorPin1  = 9; // Pin  7 of L293
const int motorPin2  = 8;  // Pin  2 of L293

//This will run only one time.
void setup(){
 
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);

}


void loop(){

    //This code will turn Motor B clockwise for 2 sec.
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);

    delay(500); 
    //This code will turn Motor B counter-clockwise for 2 sec.
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);

    delay(500);    
    
    //And this code will stop motors
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  
}
