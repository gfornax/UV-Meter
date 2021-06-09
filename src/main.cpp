#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <SparkFun_VEML6075_Arduino_Library.h>

#define LED_R 11
#define LED_G 10
#define LED_B 9

struct led_level{
  uint8_t r, g, b;
};

led_level led_target = {255,255,255};
led_level led_actual = {255,255,255};

// rs, en, d4, d5, d6, d7
Adafruit_LiquidCrystal lcd(13, 12, 4, 5, 6, 7);
VEML6075 uv;

void approach_led(void);
void set_led(uint8_t index);
void every_1ms(void);
void every_250ms(void);
void setup();
void loop();

void approach_led(void)
{
  if(led_target.r < led_actual.r)
    led_actual.r--;
  else if(led_target.r > led_actual.r)
    led_actual.r++;
  if(led_target.g < led_actual.g)
    led_actual.g--;
  else if(led_target.g > led_actual.g)
    led_actual.g++;  
  if(led_target.b < led_actual.b)
    led_actual.b--;
  else if(led_target.b > led_actual.b)
    led_actual.b++;

  analogWrite(LED_R, led_actual.r);
  analogWrite(LED_G, led_actual.g);
  analogWrite(LED_B, led_actual.b);
}

void set_led(uint8_t index)
{
  switch(index){
    case 0:
        led_target = (led_level){.r = 255, .g = 230, .b = 255};
      break;
    case 1:
      led_target = (led_level){.r = 255, .g = 230, .b = 255};
      break;
    case 2:
      led_target = (led_level){.r = 255, .g = 230, .b = 255};
      break;
    case 3:
      led_target = (led_level){.r = 50, .g = 230, .b = 255};
      break;
    case 4:
      led_target = (led_level){.r = 50, .g = 230, .b = 255};
      break;
    case 5:
      led_target = (led_level){.r = 50, .g = 230, .b = 255};
      break;
    case 6:
      led_target = (led_level){.r = 0, .g = 230, .b = 255};
      break;
    case 7:
      led_target = (led_level){.r = 0, .g = 230, .b = 255};
      break;
    case 8:
      led_target = (led_level){.r = 0, .g = 245, .b = 255};
      break;
    case 9:
      led_target = (led_level){.r = 0, .g = 250, .b = 255};
      break;
    case 10:
      led_target = (led_level){.r = 0, .g = 255, .b = 255};
      break;
    default:
      led_target = (led_level){.r = 0, .g = 255, .b = 230};
      break;
  }
}

void every_1ms(void)
{
  approach_led();
}

void every_250ms(void)
{
  uint8_t index_rounded = uv.index() + 0.5;

  // for debug, taken from the lib example
  Serial.println(String(uv.a()) + ", " + String(uv.b()) + ", " +
                 String(uv.uvComp1()) + ", " + String(uv.uvComp2()) + ", " +
                 String(uv.index()));

  lcd.setCursor(2,0);
  lcd.print("     ");
  lcd.setCursor(2,0);
  lcd.print(uv.a(), 0);
  lcd.setCursor(10,0);
  lcd.print("     ");
  lcd.setCursor(10,0);
  lcd.print(uv.b(), 0);

  lcd.setCursor(10,1);
  lcd.print("    ");
  lcd.setCursor(10,1);
  lcd.print(uv.index(), 1);
  
  set_led(index_rounded);
}

void setup() {
  Serial.begin(115200);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Simple VEML6075");
  lcd.setCursor(0,1);
  lcd.print("UV IDX -- fornax");
  delay(1000);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  analogWrite(LED_R, 0);
  analogWrite(LED_G, 255);
  analogWrite(LED_B, 255);
  Wire.begin();
  Serial.print("Begin init sensor... ");
  if (!uv.begin())
  {
    Serial.println("Unable to communicate with VEML6075.");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("VEML init fail");
    while (1){ ; }
  }
  lcd.clear();
  // initial screen  
  lcd.setCursor(0,0);
  lcd.print("A       B");
  lcd.setCursor(0,1);
  lcd.print("UV-Index:");
  analogWrite(LED_R, 255);
  Serial.println("done");
}

void loop() {
  static unsigned long lastRefreshTime1 = 0;
  static unsigned long lastRefreshTime250 = 0;
  unsigned long currentMillis = millis();
  if (currentMillis - lastRefreshTime1 >= 1)
    lastRefreshTime1 += 1; every_1ms();
  if (currentMillis - lastRefreshTime250 >= 250)
    lastRefreshTime250 += 250; every_250ms();
}