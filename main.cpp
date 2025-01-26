#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Swiat.h"

const char KLAWISZ_NASTEPNA_TURA = 'n';
const char KLAWISZ_ZAPISZ = 's';
const char KLAWISZ_WCZYTAJ = 'l';
const char KLAWISZ_WYJSCIE = 'q';

void wyswietlInformacjeOAutorze() {
    std::cout << "----------------------------------------\n";
    std::cout << "Autor: Damian Makurat\n";
    std::cout << "----------------------------------------\n";
}

void wyswietlMenu() {
    std::cout << "\nDostepne akcje:\n";
    std::cout << KLAWISZ_NASTEPNA_TURA << " - Nastepna tura\n";
    //std::cout << KLAWISZ_ZAPISZ << " - Zapisz stan gry\n";
    //std::cout << KLAWISZ_WCZYTAJ << " - Wczytaj stan gry\n";
    std::cout << KLAWISZ_WYJSCIE << " - Wyjscie z gry\n";
    std::cout << "Wybierz akcje: ";
}

void obslugaKomendy(Swiat& swiat) {

    char komenda;
    bool active = true;

    while (active) {

        std::cin >> komenda;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        switch (komenda) {
            case KLAWISZ_NASTEPNA_TURA:
                swiat.wykonajTure();
                active = false;
                break;

            case KLAWISZ_ZAPISZ:
                //TBD
                    active = false;
                    break;

            case KLAWISZ_WCZYTAJ:
                //TBD
                    active = false;
                    break;

            case KLAWISZ_WYJSCIE:
                std::cout << "Koniec gry!\n";
                exit(0);
                active = false;
                break;

            default:
                std::cout << "Nieznana komenda!\n";
                break;
        }
    }
}

int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    try {
        Swiat swiat;

        while (true) {
            swiat.rysujSwiat();
            wyswietlMenu();
            obslugaKomendy(swiat);
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Blad krytyczny: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}