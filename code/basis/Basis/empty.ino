#include "Arduino.h"
#include "SerialCommand.h"
#include "EEPROMAnything.h"
#include <SoftwareSerial.h>

const byte rxPin = 9;
const byte txPin = 8;
#define Baudrate 9600

const byte interruptPin = 2;
const byte ledPin = 3;

SoftwareSerial BTSerial(rxPin, txPin);
SerialCommand sCmd(BTSerial);

bool debug;
bool run;

unsigned long previous;

struct param_t {
  unsigned long cycleTime;
  int p1;
  float p2;
} params;

void IRAM_ATTR toggleRun() {
  run = !run;
}

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), toggleRun, FALLING);

  BTSerial.begin(Baudrate);

  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.addCommand("run", onRun);
  sCmd.setDefaultHandler(onUnknownCommand);

  EEPROM_readAnything(0, params);

  BTSerial.println("ready");
}

void loop() {
  sCmd.readSerial();

  unsigned long current = micros();
  if (current - previous >= params.cycleTime) {
    previous = current;

    if (run) digitalWrite(ledPin, !digitalRead(ledPin));
  }
}

void onSet() {
  char* parameter = sCmd.next();
  char* value = sCmd.next();

  if (strcmp(parameter, "cycle") == 0) params.cycleTime = atol(value);
  else if (strcmp(parameter, "p1") == 0) params.p1 = atol(value);
  else if (strcmp(parameter, "p2") == 0) params.p2 = atof(value);
  else return;

  EEPROM_writeAnything(0, params);
}

void onDebug() {
  char* mode = sCmd.next();
  if (strcmp(mode, "on") == 0) debug = true;
  else debug = false;

  BTSerial.println(debug ? "debug on" : "debug off");
}

void onRun() {
  char* value = sCmd.next();
  if (strcmp(value, "on") == 0) run = true;
  else run = false;

  BTSerial.println(run ? "run on" : "run off");
}

void onUnknownCommand(char* command) {
  BTSerial.print("Unknown Command: ");
  BTSerial.println(command);
}
