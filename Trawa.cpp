#include "Trawa.h"
#include <iostream>

Trawa::Trawa(Swiat* swiat, int x, int y)
: Roslina(swiat, x, y, 0, 'T') {
}

void Trawa::akcja() {
    Roslina::akcja();
}

void Trawa::kolizja(Organizm* atakujacy) {
    std::cout << "Organizm " << atakujacy->getSymbol()
                 << " zjada trawe na polu (" << this->getX()
                 << "," << this->getY() << ")" << std::endl;
    swiat->usunOrganizm(this);
}

Roslina* Trawa::stworzPotomka(int nowyX, int nowyY) {
    return new Trawa(swiat, nowyX, nowyY);
}
