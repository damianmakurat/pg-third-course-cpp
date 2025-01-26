#include "Guarana.h"

#include "Swiat.h"
#include <iostream>

Guarana::Guarana(Swiat* swiat, int x, int y)
: Roslina(swiat, x, y, 0, 'G') {
}

void Guarana::akcja() {
}

void Guarana::kolizja(Organizm* atakujacy) {
    // Zwierze* zwierze = dynamic_cast<Zwierze*>(atakujacy);
    // if (zwierze != nullptr) {
    //     zwierze->zwiekszSile(3);
    //     std::cout << "Organizm " << atakujacy->getSymbol()
    //                  << " zjadl guarane, jego sila aktualnie wynosi: "
    //                  << atakujacy->getSila() << std::endl;
    //     swiat->usunOrganizm(this);
    // }
    Roslina::akcja();
}

Roslina* Guarana::stworzPotomka(int nowyX, int nowyY) {
    return new Guarana(swiat, nowyX, nowyY);
}
