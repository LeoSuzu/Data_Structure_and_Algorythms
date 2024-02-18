//
// Created by Leo Suzuki on 7.2.2024.
//

// main.cpp
// Tiedosto: main.cpp
// Pääohjelma postfix-laskimen käyttöön

#include <iostream>
#include "Calc.h"

int main(int argc, char* argv[]) {
    bool promptMode = true;

    // Tarkista komentoriviparametrit
    if (argc > 1 && std::string(argv[1]) != "-p") {
        promptMode = false;

        // Tarkista, onko annettu muita parametrejä suorittamiseen
        if (argc > 1) {
            std::string input;
            for (int i = 1; i < argc; ++i) {
                input += std::string(argv[i]) + " ";
            }

            // Suorita laskutoimitus
            Calc calculator;
            calculator.processInput(input);
            calculator.printResult();
            return 0;
        }
    }

    std::string input;
    char valinta;

    do {
        // Tulosta ohjeet, jos ohjelmaa ajetaan komentoriviltä
        if (promptMode) {
            std::cout << "Syötä numerot välilyönnillä ja operaatio lopussa:" << std::endl;
            std::cout << "(+, -, *, /, e(exp), r(sqrt), a(avg), %(modulo), s(sum) tai x (vaihda kaksi ensimmäistä objektia pinossa)): " << std::endl;
            std::cout << "'esim 1. '2 1 x -' tai esim 2. '5 3 2 + '" << std::endl;
            std::cout << "'q' lopeta ohjelma." << std::endl;
        }

        std::getline(std::cin, input);

        if (input == "q" || input == "Q" || !std::cin) {
            // Lopeta ohjelma, jos käyttäjä syöttää 'q'
            break;
        }

        Calc calculator;
        calculator.processInput(input);
        calculator.printResult();

        if (promptMode) {
            std::cout << "Haluatko suorittaa toisen laskun? (y/e): ";
            std::cin >> valinta;
            std::cin.ignore(); // Jätä huomiotta rivinvaihto, joka jää syötteeseen
        } else {
            // Jos ohjelmaa ajetaan komentoriviltä tai -q on annettu, lopeta ohjelma
            break;
        }

    } while (valinta == 'y' || valinta == 'Y');

    return 0;
}