# Obstacle-Avoiding-Car
Autonomous 4-wheel robot car built with Arduino Uno, HC-SR04 ultrasonic sensor, servo scanning system, and L298N motor driver.
# 🚗 Obstacle Avoiding Robot Car

An Arduino-based autonomous obstacle avoiding robot using ultrasonic sensor and L298N motor driver.

## 🔧 Components Used

- Arduino Uno
- L298N Motor Driver
- 4 DC Motors (connected in parallel pairs)
- HC-SR04 Ultrasonic Sensor
- Servo Motor
- 12V Battery
- Chassis with 4 wheels

## ⚙️ Working Principle

- Ultrasonic sensor measures distance.
- If obstacle detected:
  - Car stops
  - Servo scans left and right
  - Chooses direction with more space
- Moves forward again.

## 🔌 Motor Wiring

- Left Motors (2 in parallel) → OUT1 & OUT2
- Right Motors (2 in parallel) → OUT3 & OUT4

## 🔋 Power Connections

- Battery + → L298N 12V
- Battery – → GND
- L298N 5V → Arduino 5V
- Common GND connected

## 📸 Circuit Diagram

![Circuit Diagram](circuit_diagram.png)

## 🧠 Future Improvements

- Add Bluetooth control
- Add speed control using PWM
- Add line following mode
- Add camera module

---

Made by Shakin Mahmud Tanvir 🚀
