#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Address
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
const int eastLDR = 2;
const int westLDR = 3;
const int motor1 = 4;
const int motor2 = 5;

void setup()
{
  pinMode(eastLDR, INPUT);
  pinMode(westLDR, INPUT);

  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);

  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("SOLAR TRACKING");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM");
  delay(2000);

  lcd.clear();
}

void loop()
{
  int east = digitalRead(eastLDR);
  int west = digitalRead(westLDR);

  Serial.print("East = ");
  Serial.print(east);
  Serial.print("  West = ");
  Serial.println(west);

  lcd.setCursor(0, 0);
  lcd.print("E:");
  lcd.print(east);
  lcd.print(" W:");
  lcd.print(west);
  lcd.print("  ");

  if (east == 0 && west == 1)
  {
    lcd.setCursor(0, 1);
    lcd.print("Turning EAST ");

    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
  }
  else if (east == 1 && west == 0)
  {
    lcd.setCursor(0, 1);
    lcd.print("Turning WEST ");

    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Panel Stable ");

    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
  }

  delay(200);
}