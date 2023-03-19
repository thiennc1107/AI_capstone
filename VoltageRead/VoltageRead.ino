#include <stdio.h>
#include <stdlib.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogReadVoltage();
}

void analogReadVoltage(){
  // read the input on analog pin 0:
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
  float voltage1 = sensorValue1 * (5.0 / 1023.0);
  float voltage2 = sensorValue2 * (5.0 / 1023.0);

  // print out the value you read:
  //Serial.println(voltage1);
  Serial.println(voltage2);
  delay(1000);
}
