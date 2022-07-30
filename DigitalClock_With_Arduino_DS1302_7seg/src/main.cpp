#include <Arduino.h>
#include <TimerOne.h>
#include <virtuabotixRTC.h> 
#include "config.h"
#include "displayfunction.h"
//#include <Wire.h> 

void setime();                             //declaring a function to set the time manually

virtuabotixRTC myRTC(6, 7, 8);             //pin configuration for RTC 6-clk 7-data 8-RST
                                           //the pins of 4-digit 7-segment display attach to pin2-13 respectively 

void setup()
{
  //set all the pins of the LED display as output
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  pinMode(s, OUTPUT);

  pinMode(Set, INPUT);
  pinMode(min_set, INPUT);
  pinMode(hr_set, INPUT);

  //myRTC.setDS1302Time(00, 50, 9, 6, 21,3, 2022); 
  attachInterrupt(digitalPinToInterrupt(Set), set_time_state, RISING);
  Timer1.initialize(100000); // set a timer of length 100000 microseconds (or 0.1 sec - or 10Hz => the led will blink 5 times, 5 cycles of on-and-off, per second)
  Timer1.attachInterrupt( add ); // attach the service routine here
  //Serial.begin(9600);
}
/***************************************/ 
void loop()
{
  if(state == HIGH)
  {
    set_time(); 
    myRTC.setDS1302Time(00, minu, hours, 6, 21,3, 2022);
  }

 else
 { 
  myRTC.updateTime();  
    
   //hours = myRTC.hours;
   //minu = myRTC.minutes;

  //Serial.println(hours);
 // Serial.println(minu);
  
  clearLEDs();//clear the 7-segment display screen
  pickDigit(0);//Light up 7-segment display d1
  pickNumber(myRTC.minutes%10);// get the value of thousand
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(1);//Light up 7-segment display d2
  pickNumber((myRTC.minutes/10)%10);// get the value of hundred
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(2);//Light up 7-segment display d3
  pickNumber(myRTC.hours%10);//get the value of ten
  delay(del);//delay 5ms

  clearLEDs();//clear the 7-segment display screen
  pickDigit(3);//Light up 7-segment display d4
  pickNumber((myRTC.hours/10)%10);//Get the value of single digit
  delay(del);//delay 5ms

  //delay(1000);
 hours = myRTC.hours;
 minu = myRTC.minutes;
 }
 //clearLEDs();
  
}

 