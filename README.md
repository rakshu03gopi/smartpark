# smartpark
# 🚗 ESP-NOW Smart Parking Management System

An ESP32-based smart parking system that monitors parking occupancy using ultrasonic sensors, controls an automatic entry gate, and communicates parking availability wirelessly using ESP-NOW. Real-time parking status is displayed on OLED screens to guide drivers efficiently.

## 🚀 Features

- Automatic vehicle detection using ultrasonic sensors
- Servo-controlled entry/exit gate
- Real-time parking slot monitoring
- OLED display for parking availability
- Wireless communication using ESP-NOW
- LED indicators for occupied parking slots
- Automatic vehicle count management

---

## 🛠️ Hardware Used

- 2 × ESP32 Development Boards
- HC-SR04 Ultrasonic Sensors
- SG90 Servo Motor
- 0.96" OLED Display (SSD1306)
- LEDs
- Jumper Wires
- Breadboard
- Power Supply

---

## ⚙️ System Overview

### Entry Gate Unit
- Detects vehicles at entry and exit.
- Opens and closes the gate automatically using a servo motor.
- Maintains total vehicle count.
- Displays parking capacity and FULL status on the OLED.
- Sends parking information wirelessly via ESP-NOW.

### Parking Slot Unit
- Monitors individual parking slots using ultrasonic sensors.
- Indicates occupied slots using LEDs.
- Displays available parking slots (F1, F2, F3) or FULL on the OLED.
- Receives parking updates through ESP-NOW.

---

## 📡 Communication

The two ESP32 boards communicate using **ESP-NOW**, enabling fast, low-latency, Wi-Fi-free wireless data exchange between the gate controller and parking slot monitor.

---

## 💻 Technologies

- ESP32
- Arduino C++
- ESP-NOW Wireless Communication
- Ultrasonic Sensors
- OLED Display (SSD1306)
- Servo Motor Control
- Embedded Systems

---

## 📈 Future Improvements

- Mobile application integration
- Cloud-based parking monitoring
- RFID-based vehicle authentication
- License plate recognition
- Reservation system for parking slots

---

## 📜 License

This project is intended for educational and research purposes.
