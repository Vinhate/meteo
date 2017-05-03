#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3F, 16, 2);
byte therm[8] { B00100, B01010, B01010, B01010, B01010, B10001, B10001, B01110 };
byte tear[8] { B00100, B01010, B01010, B10001, B10001, B10001, B10001, B01110 };
byte temp [8] { B00011, B00011};
void setup()
{
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.createChar(1, therm);
  lcd.createChar(2, tear);
  lcd.createChar(3, temp);
}
void loop()
{
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  if (isnan(t) || isnan(h)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error read from DHT");
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("\1 Temp.: ");
    lcd.print(t);
    lcd.print("\3C");
    lcd.setCursor(0, 1);
    lcd.print("\2 Hum.: ");
    lcd.print(h);
    lcd.print(" %");
  }
}
