#include "Arduino.h"

int a = A0;                                   //configure the variable for pins
int b = A1;
int c = A2;
int d = A3;
int e = A4;
int f = A5;
int g = 9;
int p = 0;
int s = 5;
int d4 = 10;
int d3 = 11;
int d2 = 12;
int d1 = 13;
int Set = 2;
int min_set = 3;
int hr_set = 4;

volatile byte state = LOW;
long n = 0;// n represents the value displayed on the LED display. For example, when n=0, 0000 is displayed. The maximum value is 9999. 
int x = 100;
int del = 5;//Set del as 5; the value is the degree of fine tuning for the clock
int count = 0;//Set count=0. Here count is a count value that increases by 1 every 0.1 second, which means 1 second is counted when the value is 10
int hours = 0;
int minu = 0;
int set_state = 0;