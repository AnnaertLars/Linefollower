#include "BluetoothSerial.h"  // Voor Bluetooth-functionaliteit

BluetoothSerial BTSerial;     // Bluetooth-instantie

// GPIO's voor de QTR-8A (maar je gebruikt er 7)
const int sensorPins[6] = {36, 39, 34, 35, 32, 33};
int sensorValues[6];          // Opslag voor sensorwaarden

bool debugMode = false;       // Variabele om te controleren of debug aanstaat

void setup() {
  // Start seriële en Bluetooth-communicatie
  Serial.begin(115200);
  BTSerial.begin("ESP32_LineFollower");  // Naam van je ESP32 voor Bluetooth
  Serial.println("Bluetooth gestart! Koppel met 'ESP32_LineFollower'.");
}

void loop() {
  // Controleer op binnenkomende Bluetooth-commando's
  if (BTSerial.available()) {
    String command = BTSerial.readStringUntil('\n'); // Lees het Bluetooth-commando
    command.trim(); // Verwijder spaties en nieuwe regels

    if (command == "debug") {
      debugMode = !debugMode; // Wissel debugmodus aan/uit
      BTSerial.println(debugMode ? "Debugmodus AAN" : "Debugmodus UIT");
    } else {
      BTSerial.println("Onbekend commando. Gebruik 'debug' om sensoren te lezen.");
    }
  }

  // Lees sensorgegevens als debugmodus aanstaat
  if (debugMode) {
    for (int i = 0; i < 6; i++) {
      sensorValues[i] = analogRead(sensorPins[i]);
    }

    // Stuur sensorgegevens via Bluetooth
    BTSerial.print("Sensorwaarden: ");
    for (int i = 0; i < 6; i++) {
      BTSerial.print("S");
      BTSerial.print(i);
      BTSerial.print("=");
      BTSerial.print(sensorValues[i]);
      if (i < 5) BTSerial.print(" | "); // Komma/pipe tussen waarden
    }
    BTSerial.println(); // Nieuwe regel
    delay(500);         // Wacht 500 ms tussen uitlezingen    
  }
}