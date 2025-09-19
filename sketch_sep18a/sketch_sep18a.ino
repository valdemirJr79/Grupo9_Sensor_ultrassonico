#define TRIGGER_PIN 4  // Conectado ao Trigger do sensor
#define ECHO_PIN 2     // Conectado ao Echo do sensor

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long duration;
  float distance;

  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000); // Timeout para evitar travamento

  // Se não recebeu pulso, duration será 0
  if(duration == 0) {
    Serial.println("Sem eco detectado");
  } else {
    distance = duration * 0.0344 / 2;
    Serial.print("Distância: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  delay(500);
}
