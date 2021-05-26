#include "Arduino.h"
#include "Display7.h"

/**
 * Construtor que recibe los números de pines a utilizar para el control del
 * Display.
 */
Display7::Display7(int a, int b, int c, int d, int e, int f, int g) 
{
    int Ipins[a, b, c, d, e, f, g];

    for (int i = 0; i < 7; i++) {
        this -> pins[i] = Ipins[i];
        pinMode(pins[i], OUTPUT);
    }
}

/**
 * Constructor que recibe un array de enteros y un segundo argumento 
 * opcional que indica si se está usando un Display de ánodo común.
 */
Display7::Display7(int Ipins[], bool IcommonAnode)
{
    this -> commonAnode = IcommonAnode;

    for (int i = 0; i < 7; i++) {
        this -> pins[i] = Ipins[i];
        pinMode(pins[i], OUTPUT);
    }
}


/**
 * Muestra un número del 0 al 15 (HEX). 
 */
void Display7::number(int num) {
    displayRaw(NUMS[num]);
}

/**
 * Muestra un número durante una cantidad de tiempo dada y luego apaga el
 * Display.
 */
void Display7::showAndHide(int num, int tim) {
    displayRaw(NUMS[num]);
    delay(tim);
    clear();
}

/**
 * Recibe los estados como argumentos separados. Muestra un caracter
 * personalizado.
 */
void Display7::custom(int a, int b, int c, int d, int e, int f, int g) {
    displayRaw(a, b, c, d, e, f, g);
}

/**
 * Recibe un Array de int. Muestra un caracter personalizado.
 */
void Display7::custom(int displaySet[]) {
    displayRaw(displaySet);
}


/**
 * Ejecuta un programa de prueba. Muestra los números del 0 al 15 (HEX).
 */
void Display7::test() {
    for (int i = 0; i < 16; i++) {
        displayRaw(NUMS[i]);
        delay(1000);
    }
}

/**
 * Limpia el Display.
 */
void Display7::clear() {
    displayRaw(0, 0, 0, 0, 0, 0, 0);
}

/**
 * Muestra un caracter personalizado en el Display, a partir de los estados
 * por separado.
 */
void Display7::displayRaw(int a, int b, int c, int d, int e, int f, int g) {
    int states[7] = {a, b, c, d, e, f, g};
    displayRaw(states);
}

/**
 * Muestra en el Display los datos dados a partir de un array de int.
 */
void Display7::displayRaw(int states[]) {
    for (int i = 0; i < 7; i++) {
        int stat;
        if (commonAnode) stat = (states[i] == 1) ? LOW : HIGH;
        else stat = (states[i] == 1) ? HIGH : LOW; 
        digitalWrite(pins[i], stat);
    }
}
