#include <ESP32Servo.h>

int Switch = 18;

int vertical, horizontal;
int x, y;
const int controllerVert = 12;

const int servoPin_1 = 5;

Servo servo_1;

void setup() {
  vertical=analogRead(controllerVert);
  Serial.println(vertical);

  servo_1.attach(servoPin_1);

  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello, ESP32!");
  pinMode(Switch, INPUT_PULLUP);

  x = 90;
  servo_1.write(x);
}

void loop() {
  vertical = analogRead(controllerVert);
  Serial.println(vertical);
  if(vertical == 4095 && x > 0){
    x -= 1;
    delay(15);
    servo_1.write(x);
  }
  else if (vertical == 1743 && x <= 90 && x >= 0){
    x += 1;
    delay(15);
    servo_1.write(x);
  }
  else if (vertical == 1743 && x <= 180 && x >= 90){
    x -= 1;
    delay(15);
    servo_1.write(x);
  }
  else if(vertical == 0 && x < 180 && x >= 90){
    delay(15);
    x += 1;
    servo_1.write(x);
  }
  else {
    x = x;
  }
  
}
