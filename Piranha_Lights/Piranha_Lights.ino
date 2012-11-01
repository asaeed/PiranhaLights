int REDPin = 4;    // RED pin of the LED to PWM pin 4
int GREENPin = 5;  // GREEN pin of the LED to PWM pin 5
int BLUEPin = 6;   // BLUE pin of the LED to PWM pin 6
int brightness = 0; // LED brightness
int increment = 5;  // brightness increment

const int pinArraySize = 12;
int pinArray[pinArraySize] = {2,3,4,5,6,7,8,9,10,11,12,13};

void setup()
{
  for (int thisPin = 0; thisPin <= pinArraySize-1; thisPin++){
    pinMode(pinArray[thisPin], OUTPUT); 
  }
  Serial.begin(9600);
}

void loop()
{
  brightness = brightness + increment;  // increment brightness for next loop iteration

  if (brightness <= 0 || brightness >= 255)    // reverse the direction of the fading
  {
    increment = -increment;
    if (brightness >= 255){
      //delay(1000);
       
    }
  }
  brightness = constrain(brightness, 0, 255);
  for (int thisPin = 0; thisPin <= pinArraySize-1; thisPin++){
    analogWrite(pinArray[thisPin], (brightness - thisPin * 75) % 255); 
  }
  delay(20);  // wait for 20 milliseconds to see the dimming effect
}
