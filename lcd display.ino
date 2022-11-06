#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}

void loop()
{
  // when characters arrive over the serial port...
  if (THRESHOLD > 100){
    lcd.setCursor(0,0);
    lcd.print("Water Level");
    delay(1000);
    
    lcd.setCursor(0,1);
    lcd.print("SOIL IS WET");
    delay(8000);
    lcd.clear()
  }
  else{
    lcd.setCursor(0,0);
    lcd.print("Water Level");
    delay(1000);
    
    lcd.setCursor(0,1);
    lcd.print("SOIL IS DRY");
    delay(8000);
    lcd.clear();
  }
    lcd.setCursor(0,0);
    lcd.print("Temperature C");
    delay(1000);
    
    lcd.setCursor(0,1);
    lcd.print(DHT.temperature);
    delay(8000);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("humidity");
    delay(1000);
    
    lcd.setCursor(0,1);
    lcd.print(DHT.humidity);
    delay(8000);
    lcd.clear();
    
    lcd.setCursor(0,0);
    lcd.print("Date");
    delay(1000);

    lcd.setCursor(0,1);
    lcd.print("11/6/2022");
    delay(8000);
    lcd.clear();
    
    }
  }
}
