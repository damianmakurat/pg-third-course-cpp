#include "Lew.h"
#include <iostream>

Lew::Lew(Swiat* swiat, int x, int y)
    : Zwierze(swiat, x, y, 11, 7, 'L') {}

Lew* Lew::stworzPotomka(int nowyX, int nowyY) {
    return new Lew(swiat, nowyX, nowyY);
}

bool Lew::czyOdparlAtak(Organizm* atakujacy) {
    if (atakujacy->getSila() < 5) {
        std::cout << "Lew na polu (" << this->getX() << "," << this->getY()
                 << ") odstraszyl organizm " << atakujacy->getSymbol()
                 << " (sila " << atakujacy->getSila()
                 << ") z pola (" << atakujacy->getX() << "," << atakujacy->getY()
                 << ") - zbyt slaby by zaatakowac krola zwierzat!" << std::endl;
        return true;
    }
    return false;
}