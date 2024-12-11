#include <LiquidCrystal.h>

// Define pins for the LCD
const int RS = 7;  // Register Select pin
const int EN = 6;  // Enable pin
const int D4 = 5;  // Data pin D4
const int D5 = 4;  // Data pin D5
const int D6 = 3;  // Data pin D6
const int D7 = 2;  // Data pin D7

// Initialize the LiquidCrystal object
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

// Define ultrasonic sensor pins
#define TRIG_PIN 8
#define ECHO_PIN 9

// Define LEDs and buzzer
#define COOL_LED 10
#define NORMAL_LED 11
#define HOT_LED 12
#define ERROR_LED 13
#define BUZZER A3

// Define potentiometer pins (simulating temperature and humidity)
#define TEMP_SENSOR A0
#define HUMID_SENSOR A1

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);  // Set up LCD size (16 columns, 2 rows)

  // Initialize ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Initialize LEDs and buzzer
  pinMode(COOL_LED, OUTPUT);
  pinMode(NORMAL_LED, OUTPUT);
  pinMode(HOT_LED, OUTPUT);
  pinMode(ERROR_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Water Dispenser");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);  // Delay for initialization
}

void loop() {
  // Get distance from ultrasonic sensor
  float distance = getDistance();

  // Read temperature and humidity values from potentiometers
  int temperature = analogRead(TEMP_SENSOR) / 10;  // Scale for simulation
  int humidity = analogRead(HUMID_SENSOR) / 10;

  // Update LCD display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");

  delay(500);  // Delay for stability

  // Check for errors based on distance or temperature
  if (distance > 50 || temperature > 40) {
    // Error state: tank empty or temperature high
    digitalWrite(ERROR_LED, HIGH);
    digitalWrite(COOL_LED, LOW);
    digitalWrite(NORMAL_LED, LOW);
    digitalWrite(HOT_LED, LOW);

    // Display error message on LCD
    lcd.clear();
    if (distance > 50) {
      lcd.setCursor(0, 0);
      lcd.print("Error: Tank Empty");
    } else if (temperature > 40) {
      lcd.setCursor(0, 0);
      lcd.print("Error: Temp High");
    }

    // Activate buzzer with beeping effect
    for (int i = 0; i < 3; i++) {  // Beep 3 times
      tone(BUZZER, 1000);  // Play tone at 1000 Hz
      delay(200);          // Keep the tone for 200 ms
      noTone(BUZZER);      // Stop the tone
      delay(200);          // Wait for 200 ms
    }
  } else {
    // Normal operation: choose LEDs based on temperature
    digitalWrite(ERROR_LED, LOW);
    noTone(BUZZER);

    if (temperature < 25) {
      digitalWrite(COOL_LED, HIGH);
      digitalWrite(NORMAL_LED, LOW);
      digitalWrite(HOT_LED, LOW);
    } else if (temperature >= 25 && temperature <= 40) {
      digitalWrite(COOL_LED, LOW);
      digitalWrite(NORMAL_LED, HIGH);
      digitalWrite(HOT_LED, LOW);
    } else {
      digitalWrite(COOL_LED, LOW);
      digitalWrite(NORMAL_LED, LOW);
      digitalWrite(HOT_LED, HIGH);
    }
  }

  delay(1000);  // Loop delay
}

float getDistance() {
  // Send a pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo pulse duration
  long duration = pulseIn(ECHO_PIN, HIGH);

  // Convert duration to distance in cm
  float distance = (duration * 0.034) / 2;
  return distance;
}
