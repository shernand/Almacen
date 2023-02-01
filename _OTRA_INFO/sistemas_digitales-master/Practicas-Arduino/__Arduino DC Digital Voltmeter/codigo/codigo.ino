//******************************************************************************
// Digital Timer using 4-Digit 7-segment Display
//     www.circuits4you.com
//------------------------------------------------------------------------------
#include <TimerOne.h>
//Define 74HC595 Connections with arduino
const int Data = 7;
const int Clock = 8;
const int Latch = 6;

const int SEG0 = 5;
const int SEG1 = 4;
const int SEG2 = 3;
const int SEG3 = 2;

const int Buzzer = 13;        //Buzzer

//Up down keys connection
const int Min_key = 10;
const int Sec_key = 9;
int cc = 0;
char Value[4];
const char SegData[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int MIN = 0, SEC = 0, count = 10;
//==============================================================================
void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  pinMode(Data, OUTPUT);
  pinMode(Clock, OUTPUT);
  pinMode(Latch, OUTPUT);
  pinMode(SEG0, OUTPUT);
  pinMode(SEG1, OUTPUT);
  pinMode(SEG2, OUTPUT);
  pinMode(SEG3, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  digitalWrite(Buzzer, LOW);    // Turn off buzzer

  pinMode(Min_key, INPUT);      // Keys or proximity sensor
  pinMode(Sec_key, INPUT);

  digitalWrite(Min_key, HIGH);  // Pull up for keys
  digitalWrite(Sec_key, HIGH);

  //Initialize Display Scanner
  cc = 0;
  Timer1.initialize(10000);           // Timer...
  //------  Timer1.attachInterrupt(timerIsr);   //

}
//==============================================================================
void loop() {
  char cMIN[4], cSEC[4];
  if (count == 0)
  {
    count = 10; //1 Second as we have loop delay of 100mSec
    if (MIN > 0)    //if Minutes are greater than zero
    {
      if (SEC == 0)
      {
        MIN--;
        SEC = 60;
      }
    }
    SEC--;
    //Check that timer is zero
    if (MIN == 0 && SEC == 1)  //Second is kept one to avoid beeping at normal zero
    {
      digitalWrite(Buzzer, HIGH);   //Turn on Buzzer
    }
  }
}
if (MIN > 0 || SEC > 0)
{
  count--;
}
}
if (digitalRead(Min_key) == LOW)
{
  //******************************************************************************
