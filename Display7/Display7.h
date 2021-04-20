#include "Arduino.h"

class Display7
{
private:
    /* data */
    const int NUMS[16][7] = {
        {1,1,1,1,1,1,0}, // 0
        {0,1,1,0,0,0,0}, // 1
        {1,1,0,1,1,0,1}, // 2
        {1,1,1,1,0,0,1}, // 3
        {0,1,1,0,0,1,1}, // 4
        {1,0,1,1,0,1,1}, // 5
        {1,0,1,1,1,1,1}, // 6 
        {1,1,1,0,0,0,0}, // 7
        {1,1,1,1,1,1,1}, // 8
        {1,1,1,1,0,1,1}, // 9
        {1,1,1,0,1,1,1}, // A
        {0,0,1,1,1,1,1}, // B
        {1,0,0,1,1,1,0}, // C
        {0,1,1,1,1,0,1}, // D
        {1,0,0,1,1,1,1}, // E
        {1,0,0,0,1,1,1}  // F
    };

    // Methods
    void displayRaw(int states[]);

public:
    // Fields
    int pins[7];
    bool commonAnode;
    int empty[7] = {0,0,0,0,0,0,0};

    // Methods
    Display7(int pins[], bool commonAnode = false);
    void displayNumber(int num);
    void displayTime(int num, int tim);
    void displayCustom(int displaySet[]);
    void displayTest();
    void clearDisplay();
    
};
