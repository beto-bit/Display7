# 🕹 Arduino 7 Segment Display
 This Arduino library provides an easy displaying of numbers (HEX) and pretty much anything. It supports common anode displays and common cathode ones.

# 🎈 Porpouse
I needed a library for displaying numbers into a 7 segment display, and no I have it. I hope it helps.

# ⚙ Usage
For binding a Display, you must create an instance of `Display7` class. Like this.
```c++
// Declare the pins you will use.
int pins[7] = {7, 8, 9, 10, 11, 12, 13};

// Create the instance.
Display7 myDisplay(pins);
```
If you want to use a common anode display, put this. Don't change anything else.
```c++
Display7 myDisplay(pins, true);
```

* `displayNumber()`: 
It displays a given number. Supports number up to 15 (displays numbers in traditional 7 segment display HEX).
```c++
myDisplay.displayNumber(6);
```

* `displayTime()`:
Displays a number for a given time. Then it turns off. 
```c++
myDisplay.displayTime(2, 2600);
```

* `displayCustom()`:
You feed it with a list containin the states of the segments, either it is a common anode display or an common cathode one. It works the same way.
```c++
int mySegments[7] = {0, 1, 1, 0, 1, 1, 1};
myDisplay.displayCustom(mySegments);
// It displays an "H".
```

* `displayTest()`:
It displays a sequence of numbers to test the display.
```c++
myDisplay.displayTest();
```

* `clearDisplay()`:
Well, it clears the display.
```c++
myDisplay.clearDisplay();
```

# 🎉 It Works 🎉
To use it, copy-paste the [Display7 Folder](https://github.com/beto-bit/Arduino-7-Segment-Display/tree/main/Display7) into your libraries folder. 
Feel free to contribute or use it.
