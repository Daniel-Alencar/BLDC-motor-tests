#include "Arduino.h"

#include <math.h>

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Servo.h>

#define MPU_ADRESS 0x68
#define ENABLE_SERIAL_BEGIN true
#define CONTROL_PIN 9
#define POTENCIOMETRO_PIN A0

Adafruit_MPU6050 mpu;
Servo ESC;
float portValue;

float It = 0, wheel_angular_acceleration = 0, torque = 0;

void setup() {
  
  if(ENABLE_SERIAL_BEGIN) {
    Serial.begin(115200);
  }



  if (!mpu.begin(MPU_ADRESS)) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
  
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);


  
  ESC.attach(CONTROL_PIN, 1000, 2000);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  // Aceleração linear
  /*
  Serial.print(a.acceleration.x);
  Serial.print(",");
  Serial.print(a.acceleration.y);
  Serial.print(",");
  Serial.print(a.acceleration.z);
  Serial.println("");
  */
  
  
  // Velocidade angular
  /*
  Serial.print(g.gyro.x);
  Serial.print(",");
  Serial.print(g.gyro.y);
  Serial.print(",");
  Serial.print(g.gyro.z);
  Serial.println("");
  */

  // Valores
  float angular_acceleration = 7;
  float minimum = 0 - 10;
  float maximum = 0 + 10;
  
  float I1 = 12;
  float I2 = 10;
  float l1 = 0.8;
  float l2 = 1.2;
  float m1 = 0.02;
  float m2 = 0.15;
  float gravity_constant = 9.81;

  float theta_angle = 1;

  // Equações
  /*
  It = m1*pow(l1, 2) + m2*pow(l2, 2) + I1 + I2;
  wheel_angular_acceleration = ((m1*l1 + m2*l2) * gravity_constant * sin(theta_angle) - It * angular_acceleration) / I2;
  torque = I2*angular_acceleration + I2*wheel_angular_acceleration;
  */
  
  portValue = map(wheel_angular_acceleration, minimum, maximum, -180, +180);
  
  ESC.write(portValue);
  delay(100);
}
