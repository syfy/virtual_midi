int val = 0; //Our initial pot values. We need one for the first value and a second to test if there has been a change made. This needs to be done for all 3 pots.
int lastVal = 0;
int val2 = 0;
int lastVal2 = 0;
int val3 = 0;
int lastVal3 = 0;
int val4 = 0;
int lastVal4 = 0;
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
   val = analogRead(0)/8;   // Divide by 8 to get range of 0-127 for midi
    val2 = analogRead(1)/8;   // Divide by 8 to get range of 0-127 for midi
        val3 = analogRead(2)/8;   // Divide by 8 to get range of 0-127 for midi
          val3 = analogRead(3)/8;   // Divide by 8 to get range of 0-127 for midi

   if (val != lastVal) 
   {
     MIDImessage(176,1,val);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
  
   }

     if (val2 != lastVal2) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
    MIDImessage(176,2,val2);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   }

   
     if (val3 != lastVal3){
   MIDImessage(176,3,val3);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   }

      if (val4 != lastVal4) // If the value does not = the last value the following command is made. This is because the pot has been turned. Otherwise the pot remains the same and no midi message is output.
   {
  //  MIDImessage(176,4,val4);        // 176 = CC command (channel 1 control change), 1 = Which Control, val = value read from Potentionmeter 1 NOTE THIS SAYS VAL not VA1 (lowercase of course)
   }
   lastVal = val;
   lastVal2 = val2;
    lastVal3 = val3;
      lastVal4 = val4;
delay(10); //here we add a short delay to help prevent slight fluctuations, knocks on the pots etc. Adding this helped to prevent my pots from jumpin up or down a value when slightly touched or knocked.
}
