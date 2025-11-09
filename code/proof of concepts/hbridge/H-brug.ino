/*
// H-brug pinnen (DRV8833)
const int motor1Pin1 = 14;  // IN1 voor Motor 1
const int motor1Pin2 = 27;  // IN2 voor Motor 1
const int motor2Pin1 = 5;   // BIN1 voor Motor 2
const int motor2Pin2 = 18;  // BIN2 voor Motor 2

void setup() {
  Serial.begin(115200);

  // Zet motorpinnen als output en standaard LOW
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

  Serial.println("START");
}

void loop() {
  Serial.println("Motoren vooruit");

  // Motoren vooruit
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(2000);

  // Alles even uitzetten (pauze)
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(2000); // korte pauze van 0,5 sec

  Serial.println("Motoren achteruit");

  // Motoren achteruit
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(2000);

  // Alles uitzetten na actie
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(2000); // korte pauze van 0,5 sec
}
*/

// H-brug pinnen (DRV8833)
const int motor1Pin1 = 14;  // IN1 voor Motor 1
const int motor1Pin2 = 27;  // IN2 voor Motor 1
const int motor2Pin1 = 5;   // BIN1 voor Motor 2
const int motor2Pin2 = 18;  // BIN2 voor Motor 2
const int STBY = 17;        // STBY pin op DRV8833

// Knop pin
const int buttonPin = 19;   // Monostabiele knop

void setup() {
  Serial.begin(115200);

  // Zet motorpinnen als output en standaard LOW
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);

  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);

  // Zet STBY LOW bij boot → motoren uit
  pinMode(STBY, OUTPUT);
  digitalWrite(STBY, LOW);

  // Knop als input met interne pull-up
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.println("START - Wacht op knopdruk");
}

void loop() {
  int buttonState = digitalRead(buttonPin); // LOW = ingedrukt

  if (buttonState == LOW) {
    Serial.println("Knop ingedrukt - motoren draaien");

    // Activeer STBY
    digitalWrite(STBY, HIGH);

    // Motoren vooruit
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    delay(2000);

    // Motoren even uitzetten (pauze)
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    delay(500);

    // Motoren achteruit
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    delay(2000);

    // Alles uitzetten na actie
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    digitalWrite(STBY, LOW); // motoren uit

    Serial.println("Actie klaar - wacht op volgende knopdruk");

    // Wacht tot knop losgelaten wordt om herhaalde triggers te voorkomen
    while(digitalRead(buttonPin) == LOW) {
      delay(10);
    }
  }
}

