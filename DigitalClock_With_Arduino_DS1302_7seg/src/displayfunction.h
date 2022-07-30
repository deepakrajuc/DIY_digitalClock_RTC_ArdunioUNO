#include "Arduino.h"

/**************************************/ 
void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();

void clearLEDs();
void add();

void pickDigit(int x);
void pickNumber(int y);

void set_time_state();
 

void pickDigit(int x) //light up a 7-segment display
{
  //The 7-segment LED display is a common-cathode one. So also use digitalWrite to  set d1 as high and the LED will go out
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);

  switch(x)
  {
    case 0: 
    digitalWrite(d1, HIGH);//Light d1 up 
    break;
    case 1: 
    digitalWrite(d2, HIGH); //Light d2 up 
    break;
    case 2: 
    digitalWrite(d3, HIGH); //Light d3 up 
    break;
    default: 
    digitalWrite(d4, HIGH); //Light d4 up 
    break;
  }
}
//The function is to control the 7-segment LED display to display numbers. Here x is the number to be displayed. It is an integer from 0 to 9 
void pickNumber(int y)
{
  switch(x)
  {
    default: 
    zero(); 
    break;
    case 1: 
    one(); 
    break;
    case 2: 
    two(); 
    break;
    case 3: 
    three(); 
    break;
    case 4: 
    four(); 
    break;
    case 5: 
    five(); 
    break;
    case 6: 
    six(); 
    break;
    case 7: 
    seven(); 
    break;
    case 8: 
    eight(); 
    break;
    case 9: 
    nine(); 
    break;
  }
} 
void clearLEDs() //clear the 7-segment display screen
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  digitalWrite(p, LOW);
}

void zero() //the 7-segment led display 0
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void one() //the 7-segment led display 1
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void two() //the 7-segment led display 2
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
void three() //the 7-segment led display 3
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void four() //the 7-segment led display 4
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void five() //the 7-segment led display 5
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void six() //the 7-segment led display 6
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void seven() //the 7-segment led display 7
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void eight() //the 7-segment led display 8
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void nine() //the 7-segment led display 9
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
/*******************************************/
void add()
{
  // Toggle LED
  count ++;
  if(state == LOW)
  {
  digitalWrite(s,LOW);
  }
  if(count == 10)
  {
    count = 0;
    digitalWrite(s,HIGH);
    n++;
    if(n == 10000)
    {
      n = 0;
    }
  }
}

void set_time()
{
 int minBT_state = digitalRead(min_set);
 int hrBT_state = digitalRead(hr_set);

    if(minBT_state == HIGH)
    {
      minu ++;
    delay(100);
      if(minu == 60)
      {
        minu = 0;
      }
    }

    if(hrBT_state == HIGH)
    {
      hours ++;
    delay(100);
      if(hours == 25)
      {
        hours = 0;
      }

    }
       clearLEDs();//clear the 7-segment display screen
      pickDigit(0);//Light up 7-segment display d1
      pickNumber(minu%10);// get the value of thousand
      delay(del);//delay 5ms
    
      clearLEDs();//clear the 7-segment display screen
      pickDigit(1);//Light up 7-segment display d2
      pickNumber((minu/10)%10);// get the value of hundred
      delay(del);//delay 5ms
    
      clearLEDs();//clear the 7-segment display screen
      pickDigit(2);//Light up 7-segment display d3
      pickNumber(hours%10);//get the value of ten
      delay(del);//delay 5ms
    
      clearLEDs();//clear the 7-segment display screen
      pickDigit(3);//Light up 7-segment display d4
      pickNumber((hours/10)%10);//Get the value of single digit
      delay(del);//delay 5ms
  }

 void set_time_state()
 {
  state =!state;
 }