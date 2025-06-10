#include <Servo.h>
#include <LCD_I2C.h>
#include <Wire.h>
//#include<avr/wdt.h>

Servo s1;
Servo s2;
Servo s3;
unsigned long presentime;
const long duration = 400;
unsigned long prevtime = 0;
unsigned long prevtime1 = 0;

LCD_I2C lcd(0x27, 16, 2);

const int redlight = 3;
const int greenlight = 4;
const int servopin1 = 5;
const int servopin2 = 6;
const int servopin3 = 10;
bool train_arrived = false;
bool previousstate=1;
bool red_led_state=0;
bool green_led_state=1;
void setup()
{ 
 

  
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(redlight, OUTPUT);
  pinMode(greenlight, OUTPUT);
  s1.attach(servopin1);
  s2.attach(servopin2);
  s3.attach(servopin3);
  Wire.begin();
  lcd.begin(&Wire);
  lcd.backlight();
  s1.write(0);
  s2.write(0);
  digitalWrite(greenlight, HIGH);
  s3.write(0);
 
}

void loop()
{
  presentime = millis();

  bool red = digitalRead(7);
  bool green = digitalRead(8);


  if (red == 0)
  {
    s1.write(90);
    s2.write(90);
  }

  if(red==0||green==0)
  {
     red_led_state=!red_led_state;
     green_led_state=!green_led_state;

     digitalWrite(redlight, red_led_state? HIGH:LOW);
    
     digitalWrite(greenlight, !green_led_state? LOW:HIGH);
      delay(200);
  }
 
  
  if (green == 0)
  {
    train_arrived = true;
    s1.write(0);
    s2.write(0);
    prevtime1 = millis();  
  }


  if (train_arrived)
  {
    lcd.setCursor(15, 0);
    lcd.print(F("PUNE DAUND EXPRESS"));
    lcd.setCursor(15, 1);
    lcd.print(F("PLATFORM NO.3"));

    if (presentime - prevtime >= duration)
    {
      lcd.scrollDisplayLeft();
      prevtime = presentime;
    }

    if (millis() - prevtime1 >= 10000)
    { 
     
      s3.write(140);      
      
    }
     if (millis() - prevtime1 >= 15000)
    { 
     
      s3.write(0); 
      void(* resetFunc) (void) = 0;
      resetFunc(); 
      
    }
  }
}
