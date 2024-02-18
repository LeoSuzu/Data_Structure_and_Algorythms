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
            // If the first character is a digit or a negative sign followed by a digit, convert to double.
            double value = std::stod(token);
            stack.push(value);
        } else if (token == "x") {
            // Jos syöte on 'x', vaihda pinon kahden päällimmäisen alkion paikkaa.
            exchangeTopTwo();
        } else if (isOperator(token)) {
            // Muussa tapauksessa kyseessä on operaatio, suorita se.
            performOperation(token[0]);
        } else {
            std::cout << "Virhe: Tuntematon operaatio '" << token << "'." << std::endl;
        }
    }
}

void Calc::performOperation(char operation) {
    // Suorittaa annetun operaation.
    switch (operation) {
        case '+': {
            // Yhteenlaskuoperaatio.
            if (stack.getCount() >= 2) {
                double secondOperand = stack.pop();
                double firstOperand = stack.pop();
                double result = firstOperand + secondOperand;
                stack.push(result);
            } else {
                std::cout << "Virhe: Liian vähän alkioita pinossa yhteenlaskuun." << std::endl;
            }
            break;
        }

        case '-': {
            // Vähennyslaskuoperaatio.
            if (stack.getCount() >= 2) {
                double secondOperand = stack.pop();
                double firstOperand = stack.pop();
                double result = firstOperand - secondOperand;
                stack.push(result);
            } else {
                std::cout << "Virhe: Liian vähän alkioita pinossa yhteenlaskuun." << std::endl;
            }
            break;
        }

        case '*': {
            // Kertolaskuoperaatio.
            if (stack.getCount() >= 2) {
                double secondOperand = stack.pop();
                double firstOperand = stack.pop();
                double result = firstOperand * secondOperand;
                stack.push(result);
            } else {
                std::cout << "Virhe: Liian vähän alkioita pinossa kertolaskuun." << std::endl;
            }
            break;
        }

        case '/': {
            // Jakolaskuoperaatio.
            if (stack.getCount() >= 2) {
                double denominator = stack.pop();
                double numerator = stack.pop();
                if (denominator != 0.0) {
                    double result = numerator / denominator;
                    stack.push(result);
                } else {
                    std::cout << "Virhe: Nollalla jakaminen." << std::endl;
                    return;  // Lisää return tähän poistuaksesi funktiosta virhetilanteessa
                }
            } else {
                std::cout << "Virhe: Liian vähän alkioita pinossa jakolaskuun." << std::endl;
                return;  // Lisää return tähän poistuaksesi funktiosta virhetilanteessa
            }
            break;
        }

        case 'e': {
            // Eksponenttioperaatio.
            if (stack.getCount() >= 2) {
                double exponent = stack.pop();
                double base = stack.pop();
                double result = pow(base, exponent);
                stack.push(result);
            } else {
                std::cout << "Virhe: Liian vähän alkioita pinossa eksponenttioperaatioon." << std::endl;
            }
            break;
        }

        case 'r': {
            // Neliöjuurioperaatio.
            if (stack.getCount() >= 1) {
                double value = stack.pop();
                if (value >= 0) {
                    double result = sqrt(value);
                    stack.push(result);
                } else {
                    std::cout << "Virhe: Neliöjuuri negatiivisesta luvusta." << std::endl;
                }
            } else {
                std::cout << "Virhe: Liian vähän alkioita pinossa neliöjuurioperaatioon." << std::endl;
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
                double average = sum / count;
                stack.push(average);  // Push the average back to the stack
            } else {
                std::cout << "Virhe: Keskiarvon laskeminen tyhjästä pinosta." << std::endl;
            }
            break;
        }

        case 's': {
            // Summa-operaatio.
            double sum = 0.0;
            while (stack.getTop() > 0) {
                sum += stack.pop();
            }
            stack.push(sum);
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
        int top = static_cast<int>(stack.pop());       // Poista päällimmäinen alkio
        int second = static_cast<int>(stack.pop());    // Poista toiseksi päällimmäinen alkio

        // Lisää alkiot takaisin samaan järjestykseen
        stack.push(top);
        stack.push(second);
    } else {
        std::cout << "Virhe: Liian vähän alkioita pinossa vaihtamiseen." << std::endl;
    }
}

void Calc::printResult() {

    if (stack.getCount() == 1) {
        std::cout << std::fixed << std::setprecision(2) << stack.pop() << std::endl;
    } else {
        std::cout << "Virhe: Epätäydellinen laskutoimitus tai liian monta alkiota pinossa." << std::endl;
    }
}

bool Calc::isOperator(const std::string& token) {
    // Tarkistaa, onko merkkijono operaattori (+, -, *, /, e, r, a, %, x, s).
    return token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'
    || token[0] == 'e' || token[0] == 'r' || token[0] == 'a' || token[0] == '%' || token[0] == 'x' || token[0] == 's');
}

