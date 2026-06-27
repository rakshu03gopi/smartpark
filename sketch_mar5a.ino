#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Ultrasonic Sensor Pins
#define TRIG1 15
#define ECHO1 2
#define TRIG2 0
#define ECHO2 4
#define TRIG3 16
#define ECHO3 17

// LED Pins
#define LED1 18
#define LED2 19
#define LED3 23

// Function to Measure Distance
long measureDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  return pulseIn(echoPin, HIGH) * 0.034 / 2;
}

void setup() {
  Serial.begin(115200);

  // Initialize Ultrasonic Sensors
  pinMode(TRIG1, OUTPUT); pinMode(ECHO1, INPUT);
  pinMode(TRIG2, OUTPUT); pinMode(ECHO2, INPUT);
  pinMode(TRIG3, OUTPUT); pinMode(ECHO3, INPUT);

  // Initialize LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  // Initialize OLED Display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
}

void loop() {
  // Measure Distance for Each Parking Slot
  int distance1 = measureDistance(TRIG1, ECHO1);
  int distance2 = measureDistance(TRIG2, ECHO2);
  int distance3 = measureDistance(TRIG3, ECHO3);

  // Define Parking Status
  bool occupied1 = (distance1 < 20);
  bool occupied2 = (distance2 < 20);
  bool occupied3 = (distance3 < 20);

  // LED Control: Turn ON if car is within 5 cm
  digitalWrite(LED1, (distance1 < 5) ? HIGH : LOW);
  digitalWrite(LED2, (distance2 < 5) ? HIGH : LOW);
  digitalWrite(LED3, (distance3 < 5) ? HIGH : LOW);

  // Determine Available Slots
  int freeCount = (!occupied1) + (!occupied2) + (!occupied3);

  // Print Status in Serial Monitor
  Serial.print("Slot 1: "); Serial.print(occupied1 ? "OCCUPIED" : "AVAILABLE");
  Serial.print(" | Slot 2: "); Serial.print(occupied2 ? "OCCUPIED" : "AVAILABLE");
  Serial.print(" | Slot 3: "); Serial.println(occupied3 ? "OCCUPIED" : "AVAILABLE");

  display.clearDisplay();
  display.setTextSize(3);  // **Even Bigger Font for Full Screen**
  display.setTextColor(WHITE);
  display.setCursor(25, 20);  // **Center Text**

  if (freeCount == 0) {
    // All slots are full
    display.println("FULL");
  } else {
    // Show available slots in a cycling manner
    if (!occupied1) {
      display.clearDisplay();
      display.setCursor(35, 20);
      display.println("F1");
      display.display();
      delay(500);
    }

    if (!occupied2) {
      display.clearDisplay();
      display.setCursor(35, 20);
      display.println("F2");
      display.display();
      delay(500);
    }

    if (!occupied3) {
      display.clearDisplay();
      display.setCursor(35, 20);
      display.println("F3");
      display.display();
      delay(500);
    }
  }

  display.display();
  delay(1000);  // Update every second
}


