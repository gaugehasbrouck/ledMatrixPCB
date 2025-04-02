#include <Arduino.h>

#define dataPin 0
#define clockPin 2
#define latchPin 1

void matrixWrite(uint8_t colData, uint8_t rowData) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, ~colData); 
  shiftOut(dataPin, clockPin, MSBFIRST, rowData);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  // put your setup code here, to run once:
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  matrixWrite(3, 1);
}
