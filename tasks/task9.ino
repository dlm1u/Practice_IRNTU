#define greenLedPin 5       // зелёный светодиод — двери открыты
#define redLedPin 9         // красный светодиод — двери закрыты
#define sensorPin A0        // фоторезистор

// Время, на которое двери остаются открытыми.
const unsigned long openDuration = 3000;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  Serial.begin(9600);

  // По умолчанию двери закрыты (горит красный)
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Значение с фоторезистора: ");
  Serial.println(sensorValue);

  // Если освещённость низкая (человек рядом) — открыть дверь
  if (sensorValue < 512) {
    // открыть двери (зелёный)
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    Serial.println("Человек подошёл — двери открываются");

    delay(openDuration);  // подождать

    sensorValue = analogRead(sensorPin); // проверить снова
    if (sensorValue < 512) {
      Serial.println("Человек всё ещё рядом — двери остаются открытыми");
    } else {
      // закрыть двери (красный)
      digitalWrite(redLedPin, HIGH);
      digitalWrite(greenLedPin, LOW);
      Serial.println("Человек ушёл — двери закрываются");
    }
  } else {
    // человек далеко — двери закрыты
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    Serial.println("Человек далеко — двери закрыты");
  }

  delay(500);
}