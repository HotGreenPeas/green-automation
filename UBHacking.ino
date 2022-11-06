#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include <dht.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#ifdef __AVR__
#include <avr/power.h>
#endif

#define WATER_LEVEL A0    // Arduino pin that connects to AOUT pin of moisture sensor
#define THRESHOLD 230  // CHANGE YOUR THRESHOLD HERE

#define PIXEL_PIN  2
#define PIXEL_COUNT 8

#define dht_apin A4 // Analog Pin sensor is connected to

/*Global variables space*/
const int photoResistor1 = A2;
const int photoResistor2 = A1;
const int motorPin1 = 9;  // Pin  7 of L293
const int motorPin2 = 8;  // Pin  2 of L293
const int motionPin = 3;
const int fan = 5;
const int relay = 7;
String serialOut;

dht DHT;
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Servo myservo;
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);
  myservo.attach(13);  //attachs the servo on pin 13 to servo object
  myservo.write(0);    //back to 0 degrees
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motionPin, INPUT);    // initialize sensor as an input
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'    
  pinMode(fan, OUTPUT);
  pinMode(relay, OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  delay(500);  //wait for a second
}

void loop() {
  
  fanloop();
  pumploop();
  sensorPinloop();
  motionloop();
  Serial.println(serialOut);
  delay(1000);
  serialOut = "";
}

void pumploop() {
  int value = analogRead(WATER_LEVEL);  // read the analog value from sensor
  serialOut=serialOut + value + ",";
  if (value < THRESHOLD) {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    //delay(500);
  }

  else {
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    //delay(500);
    

      //delay(15);  //delay 15ms
    
    //Serial.print("The soil is WET (");

   // Serial.print(value);
    //Serial.println(")");
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);

    //delay(500);
  }
}


void sensorPinloop() {
  int sensorValue1 = analogRead(photoResistor1);
  int sensorValue2 = analogRead(photoResistor2);
  int sum = 0;
  int sum2 = 0;
  for (int i = 0; i <= 10; i++) {
    sensorValue1 = analogRead(photoResistor1);
    sum += sensorValue1;
    delay(5);
  }
  for (int i = 0; i <= 10; i++) {
    sensorValue2 = analogRead(photoResistor2);
    sum2 += sensorValue2;
    delay(5);
  }
 // Serial.print("sensor 1 :");
  int avg1 = (sum / 10);
  int avg2 = (sum2 / 10);
  serialOut=serialOut + avg1 + ",";
  serialOut=serialOut + avg2 ;
 // Serial.println(avg1);
//  Serial.print("sensor 2 :");
//  Serial.println(avg2);
  //delay(1000);

  if (avg1 < avg2+100) {
    myservo.write(0);  //write the i angle to the servo
    delay(15);         //delay 15ms
  } else {
    myservo.write(180);  //write the i angle to the servo
    delay(15);           //delay 15ms
  }
}


void motionloop() {
  int val = digitalRead(motionPin);   // read sensor value
  //Serial.println(val);
  if (val > 0) {   //  Set pixels' color to white
  strip.setPixelColor(0, strip.Color(255,255,255));
  strip.setPixelColor(1, strip.Color(255,255,255));
  strip.setPixelColor(2, strip.Color(255,255,255));
  strip.setPixelColor(3, strip.Color(255,255,255));
  strip.setPixelColor(4, strip.Color(255,255,255));
  strip.setPixelColor(5, strip.Color(255,255,255));
  strip.setPixelColor(6, strip.Color(255,255,255));
  strip.setPixelColor(7, strip.Color(255,255,255));
  strip.show();

  } else { 
  strip.setPixelColor(0, strip.Color(128,0,128));       //  Set pixels' color to purple
  strip.setPixelColor(1, strip.Color(128,0,128));
  strip.setPixelColor(2, strip.Color(128,0,128));
  strip.setPixelColor(3, strip.Color(128,0,128));
  strip.setPixelColor(4, strip.Color(128,0,128));
  strip.setPixelColor(5, strip.Color(128,0,128));
  strip.setPixelColor(6, strip.Color(128,0,128));
  strip.setPixelColor(7, strip.Color(128,0,128));
  strip.show();  //  Update strip to match        
            // check if the sensor is HIGH
    //digitalWrite(led, HIGH); //CHANGE THIS
    //delay(10000);  // turn LED ON
  
  }
  
 }

void fanloop(){
  //Start of Program 
  DHT.read11(dht_apin);
  float temp = DHT.temperature + (random(0,99)/100.0);
  float hum = DHT.humidity + (random(0,99)/100.0);
  serialOut=serialOut + temp + ",";
  serialOut=serialOut + hum + ",";
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.setCursor(6,0);
  lcd.print(temp);
  lcd.setCursor(11,0);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.setCursor(5,1);
  lcd.print(hum);
  lcd.setCursor(10,1);
  lcd.print("%");
    delay(1000);
    if (temp > 23) {
      digitalWrite(fan,HIGH);
      digitalWrite(relay, LOW);
    }
    else{
      digitalWrite(fan,LOW);
      delay(500);
      if(temp < 15){
      digitalWrite(relay, HIGH);
      }
    }
    
  //Fastest should be once every two seconds.
 
}


