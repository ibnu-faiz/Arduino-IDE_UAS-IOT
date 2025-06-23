#define TRIG_PIN 26
#define ECHO_PIN 27
#define BUZZER_PIN 25

#define LED_MERAH 12
#define LED_KUNING 13
#define LED_HIJAU 14

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(LED_MERAH, OUTPUT);
  pinMode(LED_KUNING, OUTPUT);
  pinMode(LED_HIJAU, OUTPUT);
}

void loop() {
  // Kirim sinyal trigger ke HC-SR04
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Baca durasi echo
  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.034 / 2;

  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 10) {
    // Jarak sangat dekat, buzzer nyala full
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_KUNING, LOW);
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(500);  // jeda untuk LED
  }
  else if (distance < 30) {
    // Jarak dekat, buzzer bunyi cepat (berisik sedang)
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_KUNING, LOW);
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  }
  else if (distance < 50) {
    // Jarak agak dekat, buzzer bunyi jarang (ada jeda)
    digitalWrite(LED_MERAH, HIGH);
    digitalWrite(LED_KUNING, LOW);
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(BUZZER_PIN, HIGH);
    delay(200);
    digitalWrite(BUZZER_PIN, LOW);
    delay(300);
  }
  else if (distance <= 100) {
    // Waspada, LED kuning
    digitalWrite(LED_MERAH, LOW);
    digitalWrite(LED_KUNING, HIGH);
    digitalWrite(LED_HIJAU, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }
  else {
    // Aman, LED hijau
    digitalWrite(LED_MERAH, LOW);
    digitalWrite(LED_KUNING, LOW);
    digitalWrite(LED_HIJAU, HIGH);
    digitalWrite(BUZZER_PIN, LOW);
    delay(500);
  }
}
