//
// Created by Leo Suzuki on 7.2.2024.
//

// NumStack.h
// Tiedosto: NumStack.h
// Luokka: NumStack
// Kuvaus: Määrittelee NumStack-luokan, joka edustaa kokonaislukupinoa.

#ifndef POSTFIXCALC_NUMSTACK_H
#define POSTFIXCALC_NUMSTACK_H

#include <iostream>

class NumStack {
private:
    int max;     // Maksimikoko pinolle
    int top;     // Pinon päällimmäisen alkion indeksi
    int* stack;  // Pinon taulukko

public:
    // Rakentaja, oletusarvona koko 10
    NumStack(int size = 10);

    // Purkaja, vapauttaa pinon taulukon muistin
    ~NumStack();

    // Lisää arvon pinon päälle
    void push(int value);

    // Poista ja palauta pinon päällimmäinen arvo
    int pop();

    // Tyhjennä pino
    void clear();

    // Tarkista, onko pino täynnä
    bool isFull();

    // Tulosta pinon sisältö
    void print();

    // Palauta pinon päällimmäinen arvo
    int getTop();

    // Palauta pinon toiseksi päällimmäinen arvo
    int getSecond();

    // Palauta pinon taulukko
    int* getStack();

    // Aseta uusi taulukko pinoon
    void setStack(int* newStack);

    // Palauta pinon maksimikoko
    int getMax();

    int getCount() const {
        return top;
    }

    void reverseStack();

};

#endif //POSTFIXCALC_NUMSTACK_H
