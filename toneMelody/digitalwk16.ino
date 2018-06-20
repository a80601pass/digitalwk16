/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"
long currenttime1,previoustime1,currenttime2,previoustime2;
boolean check1,check2;
int buttonState1 = 0;
int buttonState2 = 0;

// notes in the melody:
int melody1[] = {
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4 ,NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_A4,NOTE_A4,NOTE_B4, NOTE_A4, NOTE_G4
};
int melody2[] = {
  NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4,NOTE_B4
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};
int noteDurations2[] = {
  8,8,8,8,8,8,8,8,8,8
};

void setup() {
   pinMode(4, INPUT);
   pinMode(7, INPUT);
   pinMode(13, OUTPUT);
   noTone(8);
}

void loop() {
  buttonState1 = digitalRead(4);
  buttonState2 = digitalRead(7);
    if (buttonState1 == HIGH) {
    for (int thisNote1 = 0; thisNote1 < 27; thisNote1++) {

    int noteDuration1 = 1000 / noteDurations1[thisNote1];
    tone(8, melody1[thisNote1], noteDuration1);
    previoustime1=millis();
     digitalWrite(13,HIGH);
    check1=false;
    while(!check1){
      currenttime1=millis();
      if(currenttime1-previoustime1>500){
        digitalWrite(13,LOW);
      }
      if(currenttime1-previoustime1>550){
        check1=true;
      }
    }

    noTone(8);
  }
  }
  if(buttonState2==HIGH) {
     for (int thisNote2 = 0; thisNote2 < 11; thisNote2++) {

    int noteDuration2 = 1000 / noteDurations2[thisNote2];
    tone(8, melody2[thisNote2], noteDuration2);
    previoustime2=millis();
     digitalWrite(13,HIGH);
    check2=false;
    while(!check2){
      currenttime2=millis();
      if(currenttime2-previoustime2>500){
        digitalWrite(13,LOW);
      }
      if(currenttime2-previoustime2>550){
        check2=true;
      }
    }

    noTone(8);
  }
  }
}
