#include <Servo.h>

#define MOTOR_PIN 9

Servo motor;

#include <avr/io.h>

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x07; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}

void setup() {
  Serial.begin(115200);
  // Set the PWM frequency to 50 Hz
  /*
  setPwmFrequency(MOTOR_PIN, 1);
  */

  // Attach the motor to the PWM pin
  motor.attach(MOTOR_PIN);
}

void loop() {
  // Stop the motor
  motor.writeMicroseconds(1000);
  delay(5000);
  
  // Rotate the motor counterclockwise (at minimum speed)
  motor.writeMicroseconds(1040);
  Serial.println("Rodando...");
  delay(2000);
}
