#include "DisplayShield.h"

char str[] = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
int count = 0;
long long int bgn; //begin
long long int nd; //end 
int timeDelay;
byte state;

DisplayShield myDisplay(4, 7, 8);

void setup() {
  Serial.begin(9600);
  Serial.println(SEGMENT_MAP[0]);
  bgn = millis();
  timeDelay = 300;
  state = 0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  nd = millis();
  if( (nd - bgn) >= timeDelay ){
    bgn = nd;
    switch (state) {
      case (0): //display the letters
        myDisplay.WriteLetterToSegment(0,str[count]);
        Serial.println(str[count]);
        count++;
        if(count == 25 ){
          count = 0;
          state = 1;
        }
        break;
      case(1): //display the numbers
        myDisplay.WriteNumberToSegment(0,count);
        count++;
        if(count == 10 ){
          count = 0;
          state = 0;
        }
        break;
    }
  }
  
  
}
