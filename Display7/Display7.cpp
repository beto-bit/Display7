#include "Arduino.h"
#include "Display7.h"

/**
 * Receives the pins to use.
 */
Display7::Display7(int a, int b, int c, int d, int e, int f, int g) 
{
    int _pins[7] = {a, b, c, d, e, f, g};

    for (int i = 0; i < 7; i++) {
        this -> pins[i] = _pins[i];
        pinMode(pins[i], OUTPUT);
    }
}

/**
 * Receives an array of integers, and a second optional argument for
 * handling Common Anode Displays.
 */
Display7::Display7(int _pins[], bool _commonAnode=false)
{
    this -> commonAnode = _commonAnode;

    for (int i = 0; i < 7; i++) {
        this -> pins[i] = _pins[i];
        pinMode(pins[i], OUTPUT);
    }
}


/**
 * Show a number between 0 to 15 (HEX).
 */
void Display7::number(int num) {
    displayRaw(NUMS[num]);
}

/**
 * Shows a number for a given amount of time, then clears the Display.
 */
void Display7::showAndHide(int num, int tim) {
    displayRaw(NUMS[num]);
    delay(tim);
    clear();
}

/**
 * Receives the states of the Display as separate arguments.
 */
void Display7::custom(int a, int b, int c, int d, int e, int f, int g) {
    displayRaw(a, b, c, d, e, f, g);
}

/**
 * Receives the state of the Display as an array.
 */
void Display7::custom(int displaySet[]) {
    displayRaw(displaySet);
}


/**
 * Executes a test, showing numbers from 0 to 15.
 */
void Display7::test() {
    for (int i = 0; i < 16; i++) {
        displayRaw(NUMS[i]);
        delay(1000);
    }
}

/**
 * It clears the Display.
 */
void Display7::clear() {
    displayRaw(0, 0, 0, 0, 0, 0, 0);
}

// Utility functions to turn on/off individual segments of the display.

void Display7::displayRaw(int a, int b, int c, int d, int e, int f, int g) {
    int states[7] = {a, b, c, d, e, f, g};
    displayRaw(states);
}

void Display7::displayRaw(int states[]) {
    for (int i = 0; i < 7; i++)
    {
        int stat = (commonAnode) ? !states[i] : states[i];
        digitalWrite(pins[i], stat);
    }
}
