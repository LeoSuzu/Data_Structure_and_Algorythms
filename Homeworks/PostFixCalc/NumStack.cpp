//
// Created by Leo Suzuki on 7.2.2024.
//

// NumStack.cpp
// Tiedosto: NumStack.cpp
// Luokka: NumStack
// Toteutus kokonaislukupinon toiminnoille

#include "NumStack.h"
#include <iostream>

NumStack::NumStack(int size) : top(0) {
    // Rakentaja (konstruktori) - Alustaa NumStack-luokan olion.
    max = (size > 0) ? size : 10;  // Määrittää pinon maksimikoon.
    stack = new double[max];  // Alustaa dynaamisen taulukon pinolle.
}

NumStack::~NumStack() {
    // Purkaja (destruktori) - Suoritetaan, kun NumStack-luokan olio tuhotaan.
    delete[] stack;  // Poistaa dynaamisen taulukon.
}

void NumStack::push(double value) {
    // Lisää arvon pinoon.
    if (!isFull()) {
        stack[top++] = value;
    } else {
        std::cout << "Pino on täynnä. Ei voida lisätä enempää alkioita." << std::endl;
    }
}

double NumStack::pop() {
    // Poistaa ja palauttaa päällimmäisen alkion pinosta.
    if (top > 0) {
        return stack[--top];
    } else {
        std::cout << "Virhe: Pino on tyhjä." << std::endl;
        return -1;  // Palauttaa oletusarvon tyhjälle pinolle.
    }
}

void NumStack::clear() {
    // Tyhjentää pinon.
    top = 0;
}

bool NumStack::isFull() {
    // Tarkistaa, onko pino täynnä.
    return top == max;
}

void NumStack::print() {
    // Tulostaa pinon sisällön.
    std::cout << "Pino: ";
    for (int i = 0; i < top; ++i) {
        std::cout << stack[i] << " ";
    }
    std::cout << std::endl;
}

double NumStack::getTop() {
    // Palauttaa päällimmäisen alkion pinosta tai -1 tyhjälle pinolle.
    return top > 0 ? stack[top - 1] : -1;
}

double NumStack::getSecond() {
    // Palauttaa toiseksi päällimmäisen alkion pinosta tai -1 pinolle, jossa on alle kaksi alkiota.
    return top > 1 ? stack[top - 2] : -1;
}

double* NumStack::getStack() {
    // Palauttaa pinoon liittyvän taulukon.
    return stack;
}

void NumStack::setStack(int* newStack) {
    // Asettaa pinolle uuden taulukon arvot.
    for (int i = 0; i < max; ++i) {
        stack[i] = newStack[i];
    }
}

int NumStack::getMax() {
    // Palauttaa pinon maksimikoon.
    return max;
}
