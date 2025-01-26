#include "Zolw.h"
#include <cstdlib>
#include <iostream>

Zolw::Zolw(Swiat* swiat, int x, int y)
    : Zwierze(swiat, x, y, 2, 1, 'Z') {}

void Zolw::akcja() {

    if (rand() % 100 < 75) {
        std::cout << "Zolw pozostaje w miejscu na polu ("
                 << this->getX() << "," << this->getY() << ")" << std::endl;
        return;
    }

    Zwierze::akcja();
}

bool Zolw::czyOdparlAtak(Organizm* atakujacy) {
    if (atakujacy->getSila() < 5) {
        std::cout << "Zolw na polu (" << this->getX() << "," << this->getY()
                 << ") odparl atak organizmu " << atakujacy->getSymbol()
                 << " (sila " << atakujacy->getSila()
                 << ") z pola (" << atakujacy->getX() << "," << atakujacy->getY() << ")" << std::endl;
        return true;
    }
    return false;
}

Zolw* Zolw::stworzPotomka(int nowyX, int nowyY) {
    return new Zolw(swiat, nowyX, nowyY);
}