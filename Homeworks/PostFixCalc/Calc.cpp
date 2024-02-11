//
// Created by Leo Suzuki on 7.2.2024.
//

// Calc.cpp
// Tiedosto: Calc.cpp
// Luokka: Calc
// Toteutus postfix-laskimen laskutoiminnoille

#include "Calc.h"

Calc::Calc() {
    // Rakentaja (konstruktori) - Asettaa luokan alkutilan.
}

Calc::~Calc() {
    // Purkaja (destruktori) - Suoritetaan, kun luokan instanssi poistetaan.
}

void Calc::processInput(const std::string& input) {
    // Käsittelee käyttäjän syöttämän merkkijonon.
    std::istringstream iss(input);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Jos ensimmäinen merkki on numero tai negatiivisen luvun etumerkki, lisää luku pinoon.
            int value = std::stoi(token);
            stack.push(value);
        } else if (token == "x") {
            // Jos syöte on 'x', vaihda pinon kahden päällimmäisen alkion paikkaa.
            exchangeTopTwo();
        } else {
            // Muussa tapauksessa kyseessä on operaatio, suorita se.
            char operation = token[0];
            performOperation(operation);
        }
    }
}

void Calc::performOperation(char operation) {
    // Suorittaa annetun operaation.
    switch (operation) {
        case '+': {
            // Yhteenlaskuoperaatio.
            int result = 0;
            while (stack.getTop() > 0) {
                result += stack.pop();
            }
            stack.push(result);
            break;
        }

        case '-': {
            // Vähennyslaskuoperaatio.
            if (stack.getCount() == 2) {
                // Normaalitilanteessa vähennyslasku kahdelle operandille
                int operand2 = stack.pop();
                int operand1 = stack.pop();
                int result = operand2 - operand1;
                stack.push(result);
            } else if (stack.getCount() > 2) {
                // Käänteinen järjestys, jos pinossa on enemmän kuin kaksi alkiota
                stack.reverseStack();

                int result = stack.pop();  // Aloita vähennyslasku ensimmäisestä operandista
                while (stack.getCount() >= 1) {
                    int operand = stack.pop();
                    result -= operand;  // Vähennä jokainen operandi tuloksesta
                }
                stack.push(result);
            } else {
                std::cout << "Virhe: Liian vähän alkioita pinossa vähennyslaskuun." << std::endl;
                return;  // Palaa virhetilanteessa
            }
            break;
        }

        case '*': {
            // Kertolaskuoperaatio.
            int result = 1;
            while (stack.getTop() > 0) {
                result *= stack.pop();
            }
            stack.push(result);
            break;
        }

        case '/': {
            // Jakolaskuoperaatio.
            int result = stack.pop();
            while (stack.getTop() > 0) {
                int denominator = stack.pop();
                if (denominator != 0) {
                    result /= denominator;
                } else {
                    std::cout << "Virhe: Nollalla jakaminen." << std::endl;
                    return;
                }
            }
            stack.push(result);
            break;
        }

        case 'e': {
            // Potenssioperaatio.
            int result = 1;
            while (stack.getTop() > 0) {
                result = std::pow(stack.pop(), result);
            }
            stack.push(result);
            break;
        }

        case 'r': {
            // Neliöjuurioperaatio.
            double top = stack.pop();
            if (top >= 0) {
                stack.push(std::sqrt(top));
                std::cout << "Neliöjuuri: " << std::fixed << std::setprecision(2) << std::sqrt(top) << std::endl;
                std::cout << "Neliöjuuri kokonaisukuun pyöristettynä: " << static_cast<int>(std::sqrt(top)) << std::endl;
            } else {
                std::cout << "Virhe: Neliöjuuri negatiivisesta luvusta." << std::endl;
            }
            break;
        }

        case 'a': {
            // Keskiarvo-operaatio.
            double sum = 0.0;
            int count = 0;
            while (stack.getTop() > 0) {
                sum += stack.pop();
                ++count;
            }
            if (count > 0) {
                std::cout << "Keskiarvo: " << std::fixed << std::setprecision(2) << sum / count << std::endl;
                std::cout << "Keskiarvo kokonaislukuun pyöristettynä: ";
                stack.push(static_cast<int>(sum / count));
            } else {
                std::cout << "Virhe: Keskiarvon laskeminen tyhjästä pinosta." << std::endl;
            }
            break;
        }

        case '%': {
            // Modulo-operaatio.
            if (stack.getTop() >= 2) {
                double denominator = stack.pop();
                double numerator = stack.pop();
                if (denominator != 0.0) {
                    double result = fmod(numerator, denominator);
                    stack.push(result);
                } else {
                    std::cout << "Virhe: Nollalla jakaminen modulo-operaatiossa." << std::endl;
                    return;  // Lisää return tähän poistuaksesi funktiosta virhetilanteessa
                }
            } else {
                std::cout << "Virhe: Liian vähän alkioita pinossa modulo-operaatiota varten." << std::endl;
                return;  // Lisää return tähän poistuaksesi funktiosta virhetilanteessa
            }
            break;
        }

        default:
            std::cout << "Virhe: Tuntematon operaatio '" << operation << "'." << std::endl;
            break;
    }
}

void Calc::exchangeTopTwo() {
    // Vaihtaa pinon kahden päällimmäisen alkion paikkaa.
    if (stack.getTop() >= 2) {
        int top = stack.pop();     // Poista päällimmäinen alkio
        int second = stack.pop();  // Poista toiseksi päällimmäinen alkio

        // Lisää alkiot takaisin samaan järjestykseen
        stack.push(second);
        stack.push(top);
    } else {
        std::cout << "Virhe: Liian vähän alkioita pinossa vaihtamiseen." << std::endl;
    }
}

void Calc::printResult() {
    // Tulostaa lopputuloksen.
    if (!stack.isFull()) {
        std::cout << "Tulos: " << stack.getTop() << std::endl;
    } else {
        std::cout << "Virhe: Epätäydellinen laskutoimitus." << std::endl;
    }
}
