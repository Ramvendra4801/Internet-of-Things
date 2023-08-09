//Air pollution monitoring system
//Using Arduino uno,LCD,MQ135,Buzzer,LED
#include <LiquidCrystal.h>

const int lcdRs = 12, lcdEn = 11, lcdD4 = 5, lcdD5 = 4, lcdD6 = 3, lcdD7 = 2;
LiquidCrystal lcd(lcdRs, lcdEn, lcdD4, lcdD5, lcdD6, lcdD7);

int buzzerPin = 8; // Pin for the buzzer
int ledPin = 9; // Pin for the LED
const int airSensorPin = A0; // Pin for the air quality sensor
int threshold = 250; // Threshold level for air quality

void setup() {
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  pinMode(airSensorPin, INPUT); // Set air quality sensor pin as input
  
  Serial.begin(9600); // Initialize serial communication
  
  lcd.clear(); // Clear the LCD display
  lcd.begin(16, 2); // Set the LCD display size (columns, rows)
}

void loop() {
  int airQuality = analogRead(airSensorPin); // Read air quality sensor value
  
  Serial.print("Air Quality: "); // Message print in the serial monitor
  Serial.println(airQuality); // Air quality value print in the serial monitor
  
  lcd.setCursor(0, 0); // Set the cursor position on the LCD (column 0, row 0)
  lcd.print("Air Quality: "); // Message print on the LCD
  lcd.print(airQuality); // Air quality value print on the LCD
  
  if (airQuality > threshold) { // Check if air quality exceeds the threshold
    lcd.setCursor(1, 1); // Set the cursor position on the LCD (column 1, row 1)
    lcd.print("AQ Level HIGH"); // Message print on the LCD
    Serial.println("AQ Level HIGH"); // Message print in the serial monitor
    tone(ledPin, 1000, 200); // Generate tone on the LED pin
    digitalWrite(buzzerPin, HIGH); // The buzzer turn on
  }
  else {
    digitalWrite(ledPin, LOW); // The led turn off
    digitalWrite(buzzerPin, LOW); // The buzzer turn off
    lcd.setCursor(1, 1); // Set the cursor position on the LCD (column 1, row 1)
    lcd.print("AQ Level Good");
    Serial.println("AQ Level Good");
  }
  
  delay(700);
}