#include "Arduino.h"
#include "Display7.h"

Display7::Display7(int Ipins[], bool IcommonAnode = false)
{
    commonAnode = IcommonAnode;

    for (int i = 0; i < 7; i++) {
        pins[i] = Ipins[i];
        pinMode(pins[i], OUTPUT);
    }
}

void Display7::displayNumber(int num) {
    displayRaw(NUMS[num]);
}

void Display7::displayTime(int num, int tim) {
    displayRaw(NUMS[num]);
    delay(tim);
    clearDisplay();
}

void Display7::displayCustom(int displaySet[]) {
    displayRaw(displaySet);
}

void Display7::displayTest() {
    for (int i = 0; i < 16; i++) {
        displayRaw(NUMS[i]);
        delay(1000);
    }
}

void Display7::clearDisplay() {
    displayRaw(empty);
}

void Display7::displayRaw(int states[]) {
    for (int i = 0; i < 7; i++) {
        int stat;
        if (commonAnode) stat = (states[i] == 1) ? LOW : HIGH;
        else stat = (states[i] == 1) ? HIGH : LOW; 
        digitalWrite(pins[i], stat);
    }
}

