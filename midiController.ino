
  int analogSensorValues[6] = {0, 0, 0, 0, 0,0};
  int lastAnalogSensorValues[6] = {0, 0, 0, 0, 0,0};


void setup()
{
   Serial.begin(9600);       // Set the speed of the midi port to the same as we will be using in the Hairless Midi software 
}
void MIDImessage(byte command, byte data1, byte data2)
{
   Serial.write(command);
   Serial.write(data1);
   Serial.write(data2);
}
void loop()
{
   analogSensorValues[0] = analogRead(5)/8;   // Divide by 8 to get range of 0-127 for midi
    analogSensorValues[1] = analogRead(4)/8;   // Divide by 8 to get range of 0-127 for midi
        analogSensorValues[2] = analogRead(3)/8;   // Divide by 8 to get range of 0-127 for midi
        analogSensorValues[3] = analogRead(1)/8;   // Divide by 8 to get range of 0-127 for midi
        analogSensorValues[4] = analogRead(0)/8;   // Divide by 8 to get range of 0-127 for midi

   if (analogSensorValues[0] != lastAnalogSensorValues[0]) 
   {
     MIDImessage(176,2,analogSensorValues[0]);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
  
   }

     if (analogSensorValues[1] != lastAnalogSensorValues[1]) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
    MIDImessage(176,3,analogSensorValues[1]);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   }

   
     if (analogSensorValues[2] != lastAnalogSensorValues[2]){
 MIDImessage(176,4,analogSensorValues[2]);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   }
     if (analogSensorValues[3] != lastAnalogSensorValues[3]){
   MIDImessage(176,5,analogSensorValues[3]);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   }
if (analogSensorValues[4] != lastAnalogSensorValues[4]){
   //MIDImessage(176,6,analogSensorValues[4]);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   }
 
   lastAnalogSensorValues[0] = analogSensorValues[0];
   lastAnalogSensorValues[1] = analogSensorValues[1];
   lastAnalogSensorValues[2] = analogSensorValues[2];
   lastAnalogSensorValues[3] = analogSensorValues[3];
   lastAnalogSensorValues[4] = analogSensorValues[4];

delay(10); //here we add a short delay to help prevent slight fluctuations, knocks on the pots etc. Adding this helped to prevent my pots from jumpin up or down a value when slightly touched or knocked.
}
