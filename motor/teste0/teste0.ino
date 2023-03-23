#include <Servo.h>

#define CONTROL_PIN 9
#define POTENCIOMETRO_PIN A0

Servo ESC;
int portValue;

void setup() {
  Serial.begin(115200);
  ESC.attach(CONTROL_PIN, 1000, 2000);
}

void loop() {
  portValue = analogRead(POTENCIOMETRO_PIN);
  portValue = map(portValue, 0, 1023, 0, 180);
  Serial.println(portValue);
  
  ESC.write(portValue);
}
