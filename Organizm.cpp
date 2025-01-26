#include "Organizm.h"
#include <iostream>

Organizm::Organizm(Swiat* swiat, int x, int y, int sila, int inicjatywa, char symbol)
    : swiat(swiat), x(x), y(y), sila(sila), inicjatywa(inicjatywa), symbol(symbol), wiek(0) {}

void Organizm::rysowanie() const {
    std::cout << symbol;
}

bool Organizm::czyTenSamGatunek(const Organizm* other) const {
    return typeid(*this) == typeid(*other);
}

void Organizm::setPozycja(int nowyX, int nowyY) {
    x = nowyX;
    y = nowyY;
}