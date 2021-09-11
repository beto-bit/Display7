/**************************************************************************/
/*!
  @file     Display7.h
  Simple, easy to use 7-Segment Display Library.
  Use it as you want :).
*/
/**************************************************************************/

#ifndef Display7_h
#define Display7_h

#include "Arduino.h"


class Display7
{
private:
    int NUMS[16][7] = {
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
    void displayRaw(int a, int b, int c, int d, int e, int f, int g);
    void displayRaw(int states[]);

public:
    // Fields
    int pins[7];
    bool commonAnode;

    // Constructors
    Display7(int a, int b, int c, int d, int e, int f, int g);
    Display7(int pins[], bool commonAnode = false);

    // Methods
    void number(int num);
    void showAndHide(int num, int tim);

    void custom(int a, int b, int c, int d, int e, int f, int g);
    void custom(int displaySet[]);
    
    void test();
    void clear();
    
};


#endif 
