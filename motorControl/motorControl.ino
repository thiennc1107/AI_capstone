#include <stdio.h>
#include <stdlib.h>
/*  
Modified on Nov 16, 2020
Modified by MehranMaleki from Arduino Examples
Home
*/

/*                                                                                                                                 
 * For this example, connect your X9C103P (or the like) as follows:
 * 1 - INC - Arduino pin 6 , 12
 * 2 - U/D - Arduino pin 5 , 11
 * 3 - VH  - 5V
 * 4 - VSS - GND
 * 5 - VW  - Output: Arduino pin A0 for analogRead
 * 6 - VL  - GND
 * 7 - CS  - Arduino pin 7 , 13
 * 8 - VCC - 5V
 */


#include <DigiPotX9Cxxx.h>
// INC, UD, CS
DigiPot pot1(12,11,13);
DigiPot pot2(3,2,4);


String data;

void setup() {
  Serial.begin(9600);
  pot1.reset();
  pot2.reset();
  pot1.set(0);
  pot2.set(0);

  
  pinMode(A0, INPUT);

}

void loop() {
  SpeedControl();

}
void SpeedControl(){
  //while(Serial.available()==0) {SensorStopEngine();} 
  if (Serial.available()==1){
    data = Serial.readString();// read the incoming data as string
    char dataChar[50];
    data.toCharArray(dataChar, 50);
    //split received string into 2 string and the asign to int
    char *speedchar = strtok(dataChar, " ");
    int speed1 = atoi(speedchar);
    speedchar = strtok(NULL, " ");
    int speed2 = atoi(speedchar);
  
    //print 2 speed 
    Serial.println(speed1);
    Serial.println(speed2);

    pot1.set(speed1);  
    pot2.set(speed2); 
  }
   
}

