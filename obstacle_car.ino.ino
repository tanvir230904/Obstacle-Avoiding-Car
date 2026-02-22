#include <Servo.h>
#include <NewPing.h>

// -------------------- MOTOR PINS --------------------
const int LeftMotorForward  = 7;  // IN1
const int LeftMotorBackward = 6;  // IN2
const int RightMotorForward = 5;  // IN3
const int RightMotorBackward = 4; // IN4

// -------------------- ULTRASONIC --------------------
#define trig_pin A1
#define echo_pin A2
#define maximum_distance 200

NewPing sonar(trig_pin, echo_pin, maximum_distance);

// -------------------- SERVO --------------------
Servo servo_motor;

// -------------------- VARIABLES --------------------
boolean goesForward = false;
int distance = 100;

// ====================================================
//                    SETUP
// ====================================================
void setup() {

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  servo_motor.attach(10);
  servo_motor.write(115);   // Center position
  delay(1500);

  // Take initial readings
  distance = readPing();
  delay(100);
}

// ====================================================
//                    MAIN LOOP
// ====================================================
void loop() {

  int distanceRight = 0;
  int distanceLeft = 0;

  distance = readPing();

  if (distance <= 40) {   // Obstacle close
    moveStop();
    delay(250);

    moveBackward();
    delay(350);

    moveStop();
    delay(250);

    distanceRight = lookRight();
    delay(250);

    distanceLeft = lookLeft();
    delay(250);

    if (distanceRight > distanceLeft) {
      turnRight();
    } 
    else {
      turnLeft();
    }

  }
  else {
    moveForward();
  }
}

// ====================================================
//                 SENSOR FUNCTIONS
// ====================================================
int lookRight() {
  servo_motor.write(50);
  delay(450);
  int distance = readPing();
  servo_motor.write(115);
  return distance;
}

int lookLeft() {
  servo_motor.write(170);
  delay(450);
  int distance = readPing();
  servo_motor.write(115);
  return distance;
}

int readPing() {
  delay(50);
  int cm = sonar.ping_cm();
  if (cm == 0) cm = 250;  // No reading → treat as no obstacle
  return cm;
}

// ====================================================
//                   MOVEMENT FUNCTIONS
// ====================================================
void moveStop() {
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void moveForward() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}

void moveBackward() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
}

void turnRight() {
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);

  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  delay(300);

  moveForward();
}

void turnLeft() {
  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);

  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  delay(300);

  moveForward();
}

