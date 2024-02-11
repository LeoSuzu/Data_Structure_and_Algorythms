//
// Created by Leo Suzuki on 7.2.2024.
//

// Calc.h
// Tiedosto: Calc.h
// Luokka: Calc
// Luokka, joka määrittelee postfix-laskimen toiminnot

#ifndef POSTFIXCALC_CALC_H
#define POSTFIXCALC_CALC_H

#include "NumStack.h"
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <iomanip>

class Calc {
private:
    NumStack stack;  // Laskimen käyttämä pino

public:
    // Rakentaja
    Calc();

    // Purkaja
    ~Calc();

    // Käsittele annettu syöte
    void processInput(const std::string& input);

    // Suorita laskutoimitus annetulla operaatiolla
    void performOperation(char operation);

    // Vaihda pinossa olevien kahden ylimmän alkion paikkoja
    void exchangeTopTwo();

    // Tulosta laskimen tulos
    void printResult();
};

#endif // POSTFIXCALC_CALC_H