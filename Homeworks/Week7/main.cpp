#include <iostream>
#include <string>    // Kirjasto merkkijono
#include <queue>     // Kirjasto jono

// Funktiodeklaraatio. Tämä funktio ottaa merkkijonon ja palauttaa merkin.
char compareParts(const std::string& input);

int main() {
    bool continueRunning = true;  // Luodaan totuusarvo 'continueRunning' ja asetetaan se arvoon 'true'
    do {
        std::string input;  // Luodaan merkkijono 'input'
        std::cout << "Enter input: ";  // Tulostetaan kehote syöttää tietoja
        std::getline(std::cin, input);  // Luetaan käyttäjän syöte merkkijonoon 'input'

        char result = compareParts(input);  // Kutsutaan funktiota 'compareParts' ja tallennetaan tulos muuttujaan 'result'

        std::cout << "Output: " << result << std::endl;  // Tulostetaan tulos

        std::string continueInput;  // Luodaan merkkijono 'continueInput'
        std::cout << "Do you want to continue? (yes/no): ";  // Tulostetaan kehote syöttää tietoja
        std::getline(std::cin, continueInput);  // Luetaan käyttäjän syöte merkkijonoon 'continueInput'

        if (continueInput == "no") {  // Tarkistetaan, jos käyttäjä syötti 'no'
            continueRunning = false;  // Asetetaan 'continueRunning' arvoon 'false'
        }
    } while (continueRunning);  // Toistetaan niin kauan kuin 'continueRunning' on 'true'

    return 0;  // Ohjelma päättyy ja palauttaa 0
}

// Funktio, joka vertailee merkkijonon kahta osaa, jotka on erotettu kaksoispisteellä
char compareParts(const std::string& input) {
    std::queue<char> leftPart;  // Luodaan jono 'leftPart'

    size_t i = 0;
    // Käydään läpi merkkijono kunnes löydetään kaksoispiste tai merkkijono loppuu
    while (i < input.size() && input[i] != ':') {
        leftPart.push(input[i]);  // Lisätään merkki jonoon 'leftPart'
        i++;
    }

    // Tarkistetaan, jos merkkijonossa ei ole kaksoispistettä
    if (i == input.size()) {
        return 'N';  // Palautetaan 'N'
    }

    // Ohitetaan kaksoispiste
    i++;

    // Luetaan merkkijonon oikea osa ja lasketaan sen pituus
    size_t rightLength = 0;
    while (i < input.size()) {
        rightLength++;
        i++;
    }

    // Tarkistetaan ehdot ja palautetaan tulos
    if (leftPart.size() > rightLength) {
        return 'L';  // Vasen osa on pidempi, palautetaan 'L'
    } else if (leftPart.size() < rightLength) {
        return 'R';  // Oikea osa on pidempi, palautetaan 'R'
    } else {
        std::string leftPartString;
        // Muutetaan jono merkkijonoksi
        while (!leftPart.empty()) {
            leftPartString.push_back(leftPart.front());
            leftPart.pop();
        }

        // Haetaan merkkijonon oikea osa
        std::string rightPart = input.substr(input.find(':') + 1);

        // Vertaillaan vasenta ja oikeaa osaa
        if (leftPartString == rightPart) {
            return 'S';  // Jos osat ovat samat, palautetaan 'S'
        } else {
            return 'D';  // Jos osat ovat erilaiset, palautetaan 'D'
        }
    }
}