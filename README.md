# 🕹 Arduino 7 Segment Display
 This Arduino library provides an easy displaying of numbers (HEX) and pretty much anything. It supports common anode displays and common cathode ones.

# 🎈 Porpouse
I needed a library for displaying numbers into a 7 segment display, and now I have it. I hope it helps.

# ⚙ Usage
For binding a Display, you must create an instance of `Display7` class. Like this.
```c++
// Create the Display object
Display7 myDisplay(7, 8, 9, 10, 11, 12, 13);

// Or create it using an Array.
int pins[7] = {7, 8, 9, 10, 11, 12, 13};
Display7 myDisplay(pins);
```
If you want to use a common anode display, put this, you can do it by changing the `commonAnode` property.
```c++
myDisplay.commonAnode = true;
```

* `number()`: 
It displays a given number. Supports number up to 15 (displays numbers in traditional 7 segment display HEX).
```c++
myDisplay.number(6);
```

* `showAndHide()`:
Displays a number for a given time. Then it turns off. 
```c++
myDisplay.showAndHide(2, 2600);
```

* `custom()`:
You feed it with the states of the segments, either it is a common anode display or an common cathode one. It works the same way.
```c++
// It displays an "H".
myDisplay.custom(0, 1, 1, 0, 1, 1, 1);

// Using an array
int mySegments[7] = {0, 1, 1, 0, 1, 1, 1};
myDisplay.custom(mySegments);
```

* `test()`:
It displays a sequence of numbers to test the display.
```c++
myDisplay.test();
```

* `clear()`:
Well, it clears the display.
```c++
myDisplay.clear();
```

# 🎉 It Works 🎉
To use it, copy-paste the [Display7 Folder](https://github.com/beto-bit/Arduino-7-Segment-Display/tree/main/Display7) into your libraries folder. 
Feel free to contribute or use it.
