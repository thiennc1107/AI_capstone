
int photoElectric1 = 23;
int photoElectric2 = 25;

int brake1 = 22;
int brake2 = 24;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  pinMode(photoElectric1, INPUT);
  pinMode(photoElectric2, INPUT);

  pinMode(brake1, OUTPUT);
  pinMode(brake2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  StopEngine_PhotoElectric();
}

void StopEngine_PhotoElectric(){
  // read the input pin:
  int sensorState1 = digitalRead(photoElectric1);
  int sensorState2 = digitalRead(photoElectric2);

  // print out the state of the button:
  Serial.println(sensorState1);
  Serial.println(sensorState2);
  
  if (sensorState1 == 0 || sensorState2 == 0){
    digitalWrite(brake1,HIGH);
    digitalWrite(brake2,HIGH);    
  } 
  if (sensorState1 == 1 && sensorState2 == 1){
    digitalWrite(brake1,LOW);
    digitalWrite(brake2,LOW);  
  } 

  delay(1);           // delay in between reads for stability
}
