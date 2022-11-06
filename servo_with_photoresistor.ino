const int sensorPin1 = A2;
const int sensorPin2 = A1;
#include <Servo.h>
Servo myservo;
void setup() {
  Serial.begin(9600);
  myservo.attach(13);//attachs the servo on pin 15 to servo object
  myservo.write(0);//back to 0 degrees
  delay(1000);//wait for a second
}

void loop() {
  int sensorValue1 = analogRead(sensorPin1);
  int sensorValue2 = analogRead(sensorPin2);
  int sum = 0;
  int sum2 = 0;
for (int i=0 ; i <= 10; i++){
  sum += sensorValue1;

}
for (int i=0 ; i <= 10; i++){
  sum2 += sensorValue2;
}

  Serial.print("sensor 1 :");
  int avg1 = (sum/10);
  int avg2 = (sum2/10);
  Serial.println(avg1);
  Serial.print("sensor 2 :");
  Serial.println(avg2);
  delay(5000);

  if (avg1 < avg2){
    myservo.write(0); //write the i angle to the servo
    delay(15); //delay 15ms
  }else{
    myservo.write(180); //write the i angle to the servo
    delay(15); //delay 15ms
  }
}
