#include <dht.h>


#define dht_apin A4 // Analog Pin sensor is connected to
const int fan = 14;
dht DHT;
 
void setup(){
  pinMode(fan, OUTPUT);;
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
/// fan and temp loop


void loop(){
  //Start of Program 
    
    DHT.read11(dht_apin);
    if (DHT.temperature > 20{
      digitalWrite(fan,HIGH)
    }
    else{
      digitalWrite(fan,LOW)
    }
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop(