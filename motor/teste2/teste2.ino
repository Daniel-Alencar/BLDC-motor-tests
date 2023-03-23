/*

O código era para funcionar conforme descrito nos comentários, porém, o motor gira somente em um único sentido.
- motor.writeMicroseconds(2000): Faz com que o motor gire em sentido anti-horário com alta velocidade.
- motor.writeMicroseconds(1500): Faz com que o motor gire em sentido anti-horário com baixa velocidade.
- motor.writeMicroseconds(1000): Faz com que o motor pare de girar.

OBS.: Valores < 1000 também foram testados, mas o motor continua parado nesses estados.

*/

#include <Servo.h>

#define MOTOR_PIN 9

Servo motor;

void setup() {
  // Attach the motor to the PWM pin
  motor.attach(MOTOR_PIN);
}

void loop() {
  // Rotate the motor clockwise at full speed
  motor.writeMicroseconds(2000);
  delay(2000);

  // Stop the motor
  motor.writeMicroseconds(1500);
  delay(1000);

  // Rotate the motor counterclockwise at full speed
  motor.writeMicroseconds(1000);
  delay(2000);

  // Stop the motor
  motor.writeMicroseconds(1500);
  delay(1000);
}
