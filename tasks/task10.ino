#include <Servo.h>

Servo myServo;
int currentAngle = 90; // Стартовое положение
int targetAngle = 90;

void setup() {
  Serial.begin(9600);      // Запуск последовательного порта
  myServo.attach(3);       // Подключение сервопривода к пину
  myServo.write(currentAngle);  // Установка стартовой позиции
  Serial.println("Введите угол от 0 до 180:");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n'); // Считывание строки
    input.trim(); // Удаление пробелов и перевода строки

    if (isNumeric(input)) {
      int angle = input.toInt();

      if (angle >= 0 && angle <= 180) {
        if (angle != currentAngle) {
          moveServoSmooth(currentAngle, angle);
          currentAngle = angle;
        } else {
          Serial.println("Сервопривод уже в этом положении.");
        }
      } else {
        Serial.println("Ошибка: введите число от 0 до 180.");
      }
    } else {
      Serial.println("Ошибка: введите числовое значение.");
    }
  }
}

bool isNumeric(String str) {
  for (byte i = 0; i < str.length(); i++) {
    if (!isDigit(str.charAt(i))) return false;
  }
  return true;
}

void moveServoSmooth(int from, int to) {
  int step = (to > from) ? 1 : -1;
  for (int pos = from; pos != to; pos += step) {
    myServo.write(pos);
    delay(10);
  }
  myServo.write(to);
}