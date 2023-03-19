// Mega & IOE SR-05
 uint8_t trig1 = 22; // Digital        
 uint8_t echo1 = 15; //RX Serial3
 uint8_t trig2 = 23;
 uint8_t echo2 = 17;
 unsigned long duration1 = 0;
 unsigned long duration2 = 0;
 long unsigned distance1 = 0;
 long unsigned distance2 = 0;

 uint8_t distanceValue[4] = {0,0,0,0};
 
 void setup()
 {
   Serial.begin(9600);
   Serial3.begin(9600);
   Serial2.begin(9600);

   pinMode(trig1, OUTPUT);
   pinMode(trig2, OUTPUT);

   digitalWrite(trig1, HIGH);
   digitalWrite(trig2, HIGH);

   //echo receive serial data from sensor
   pinMode(echo1, INPUT);
   pinMode(echo2, INPUT);

    pinMode(13, OUTPUT);
 }
 void loop()
 {
   Distance1();
  //  delay(500);
   Distance2();
 }

 void Distance1(void)
 {
   while ( Serial3.read() >= 0 );        
   digitalWrite(trig1, 0);     
   while (Serial3.available() <= 4)     
   {
   }
   distanceValue[0] = Serial3.read();    
   if ( distanceValue[0] == 0xFF )      
   {
     for (uint8_t i = 1; i <= 3; i ++)
     {
       distanceValue[i] = Serial3.read();
     }
   }
 digitalWrite(trig1, 1);      
 distance1 = distanceValue[1] * 256 + distanceValue[2];                  
   if ((distanceValue[3] == distanceValue[1] + distanceValue[2] - 1))
   {
     Serial.print("The distance 1 is : ");
     Serial.print(distance1);
     Serial.println(" mm");
    if (distance1 < 400) digitalWrite(13, 1);     
     delay(1000);
     digitalWrite(13,0);
   }
 }
 void Distance2(void)
 {
   while ( Serial2.read() >= 0 );        
   digitalWrite(trig2, 0);     
   while (Serial2.available() <= 4)     
   {
   }
   distanceValue[0] = Serial2.read();    
   if ( distanceValue[0] == 0xFF )      
   {
     for (uint8_t i = 1; i <= 3; i ++)
     {
       distanceValue[i] = Serial2.read();
     }
   }
 digitalWrite(trig2, 1);      
 distance2 = distanceValue[1] * 256 + distanceValue[2];                  
   if ((distanceValue[3] == distanceValue[1] + distanceValue[2] - 1))
   {
     Serial.print("The distance 2 is : ");
     Serial.print(distance2);
     if (distance2 < 400) digitalWrite(13, 1);     
     delay(1000);
     digitalWrite(13,0);

     Serial.println(" mm");
   }
 }

void StopMotorAtDistance(int StopDistance){
  
}
