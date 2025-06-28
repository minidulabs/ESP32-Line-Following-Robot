// ESP32 4-Wheel Line Follower Robot
// Created by Minidu – Modified from Arduino 2-wheel example

#define IR_LEFT_SENSOR 34     // GPIO34 for Left IR sensor
#define IR_RIGHT_SENSOR 35    // GPIO35 for Right IR sensor

// Motor control pins (Left & Right motors control 2 wheels each)
#define LEFT_MOTOR_FORWARD 27
#define LEFT_MOTOR_BACKWARD 26
#define RIGHT_MOTOR_FORWARD 25
#define RIGHT_MOTOR_BACKWARD 33

int motorSpeed = 180; // Can be mapped for ESP32 PWM if needed

void setup() {
  // Set up IR sensors
  pinMode(IR_LEFT_SENSOR, INPUT);
  pinMode(IR_RIGHT_SENSOR, INPUT);

  // Set up motor pins
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);

  stopMotors();  // Initial state
}

void loop() {
  int leftSensor = digitalRead(IR_LEFT_SENSOR);
  int rightSensor = digitalRead(IR_RIGHT_SENSOR);

  if (leftSensor == LOW && rightSensor == LOW) {
    moveForward();
  } else if (leftSensor == HIGH && rightSensor == LOW) {
    turnRight();
  } else if (leftSensor == LOW && rightSensor == HIGH) {
    turnLeft();
  } else {
    stopMotors();
  }
}

// === Movement Control Functions ===
void moveForward() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void turnLeft() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void turnRight() {
  digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}

void stopMotors() {
  digitalWrite(LEFT_MOTOR_FORWARD, LOW);
  digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
  digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
  digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}
