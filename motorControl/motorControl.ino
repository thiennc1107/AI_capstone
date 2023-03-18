#include <stdio.h>
#include <stdlib.h>
/*  
Modified on Nov 16, 2020
Modified by MehranMaleki from Arduino Examples
Home
*/

/*                                                                                                                                 
 * For this example, connect your X9C103P (or the like) as follows:
 * 1 - INC - Arduino pin 24 , 25
 * 2 - U/D - Arduino pin 26 , 27
 * 3 - VH  - 5V
 * 4 - VSS - GND
 * 5 - VW  - Output: Arduino pin A0 for analogRead
 * 6 - VL  - GND
 * 7 - CS  - Arduino pin 22 , 23
 * 8 - VCC - 5V
 */


#include <DigiPotX9Cxxx.h>

DigiPot pot1(24,26,22);
DigiPot pot2(25,27,23);


String data;
int photoElectric1 = 32;
int photoElectric2 = 33;

int brake1 = 30;
int brake2 = 31;


void setup() {
  Serial.begin(9600);
  pot1.reset();
  pot2.reset();
  pot1.set(30);
  pot2.set(30*2);

  pinMode(photoElectric1, INPUT);
  pinMode(photoElectric2, INPUT);

  pinMode(brake1, OUTPUT);
  pinMode(brake2, OUTPUT);
  
  pinMode(A0, INPUT);

}

void loop() {
  //SpeedControl();
   
  //Serial.write(speed1);
  
  //Serial.write(50);
  // SensorStopEngine();
  //analogReadVoltage();
}

void SpeedControl(){
  //while(Serial.available()==0) {SensorStopEngine();} 
  if (Serial.available()==1){
    data = Serial.readString();// read the incoming data as string
    char dataChar[50];
    data.toCharArray(dataChar, 50);
    char *speedchar = strtok(dataChar, " ");
    int speed1 = atoi(speedchar);
    speedchar = strtok(NULL, " ");
    //Serial.println(speedchar);
    int speed2 = atoi(speedchar);
    Serial.println(speed1);
    //Serial.println(speed2);

    // Serial.write(speed1);
    //Serial.write(speed2);

    //pot1.set(speed1);  
    //pot2.set(speed2*1.6); 
  }
   
}

void SensorStopEngine(){
  int sensorState1 = digitalRead(photoElectric1);
  int sensorState2 = digitalRead(photoElectric2);
  //Serial.println(sensorState1);
  //Serial.println(sensorState2);
  
  if (sensorState1 == 0 || sensorState2 == 0){
    digitalWrite(brake1,HIGH);
    digitalWrite(brake2,HIGH);    
  } 
  if (sensorState1 == 1 && sensorState2 == 1){
    digitalWrite(brake1,LOW);
    digitalWrite(brake2,LOW);  
    pot1.set(10);
    pot2.set(18);  
  } 

  delay(1);
}

void analogReadVoltage(){
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  //delay(1000);
}
