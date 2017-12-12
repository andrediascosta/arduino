/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  modified 10 Dec 2017
  by Andre Costa

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
// Bobble Bubble
int melody[] = {
  NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, 
  NOTE_B5, NOTE_A5, NOTE_G5, NOTE_F5,
  NOTE_A5, NOTE_G5, NOTE_F5, NOTE_E5,
  NOTE_G5,
  NOTE_E5, NOTE_D5, 
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5,
  NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  6, 6, 4, 8, 
  6, 6, 6, 6,
  6, 6, 8, 4,
  2,
  8, 8, 
  6, 6, 6, 6,
  4, 8, 4, 6, 6
};

void setup() {
  // iterate over the notes of the melody:

  int array_size = sizeof(melody) / sizeof(melody[0]);

  for (int thisNote = 0; thisNote < array_size; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // no need to repeat the melody.
}


