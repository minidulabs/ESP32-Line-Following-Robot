# ESP32 4-Wheel Line Following Robot

A simple 4-wheel line-following robot built using ESP32, IR sensors, and a motor driver. It uses a Li-ion battery pack with BMS protection. Ideal for learning embedded systems, robotics, and IoT basics.

---

##  Components Used

| Component               | Quantity |
|------------------------|----------|
| ESP32 Dev Kit          | 1        |
| IR Sensor Module       | 2        |
| DC Motors + Wheels     | 4        |
| Motor Driver (L298N)   | 1        |
| 18650 Li-ion Battery   | 3        |
| BMS Module             | 1        |
| Switches, Wires, Base  | As needed |

---

##  How It Works

- IR sensors detect black line on white surface
- ESP32 reads sensor values and controls motor driver
- If both sensors see white → go forward  
- If left sensor sees black → turn right  
- If right sensor sees black → turn left  
- If both sensors see black → stop

---

## ESP32 Code

The main code file is `esp32_line_follower.ino`, written in Arduino IDE format. It handles sensor reading and motor control logic.


[Uploading esp32_line_follow// ESP32 4-Wheel Line Follower Robot
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
er.ino.ino…]()


