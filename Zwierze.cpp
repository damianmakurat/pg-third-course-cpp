#include "Zwierze.h"
#include "Guarana.h"
#include "Swiat.h"
#include <cstdlib>
#include <iostream>

Zwierze::Zwierze(Swiat* swiat, int x, int y, int sila, int inicjatywa, char symbol)
    : Organizm(swiat, x, y, sila, inicjatywa, symbol) {}

void Zwierze::akcja() {
    int nowyX = x, nowyY = y;
    losujNowaPozycje(nowyX, nowyY);
    if (swiat->czyPozycjaPoprawna(nowyX, nowyY)) {
        if (Organizm* other = swiat->getOrganizmNaPolu(nowyX, nowyY)) {
            kolizja(other);
        } else {
            setPozycja(nowyX, nowyY);
        }
    }
}

void Zwierze::kolizja(Organizm* other) {
    if (czyTenSamGatunek(other)) {
        if (sprobujRozmnozenie(other)) {
            std::cout << "Nowy organizm " << this->symbol << " pojawil sie na swiecie!" << std::endl;
        }
        return;
    }

    if (other->czyUcieka(this)) {
        std::cout << "Organizm " << other->getSymbol() << " ucieka przed " << this->symbol << "!" << std::endl;
        return;
    }

    if (other->czyOdparlAtak(this)) {
        std::cout << "Organizm " << other->getSymbol() << " odparl atak " << this->symbol << "!" << std::endl;
        return;
    }

    // Sprawdzenie czy to guarana przed walką
    if (dynamic_cast<Guarana*>(other) != nullptr) {
        zwiekszSile(3);
        std::cout << "Zwierze " << this->symbol << " zwieksza sile o 3. Aktualna sila: " << this->getSila() << std::endl;
        swiat->usunOrganizm(other);
        setPozycja(other->getX(), other->getY());
        return;
    }

    std::cout << "Walka: " << this->symbol << " (sila " << this->getSila()
              << ") vs " << other->getSymbol() << " (sila " << other->getSila() << ")" << std::endl;

    if (this->getSila() >= other->getSila()) {
        std::cout << "Organizm " << other->getSymbol() << " zostal zabity przez " << this->symbol << std::endl;
        swiat->usunOrganizm(other);
        setPozycja(other->getX(), other->getY());
    } else {
        std::cout << "Organizm " << this->symbol << " zostal zabity przez " << other->getSymbol() << std::endl;
        swiat->usunOrganizm(this);
    }
}

void Zwierze::zwiekszSile(int wartosc) {
    this->sila += wartosc;
    std::cout << "Sila organizmu " << this->symbol << " zwiekszona o " << wartosc
              << ". Aktualna sila: " << this->sila << std::endl;
}

void Zwierze::losujNowaPozycje(int& nowyX, int& nowyY) {
    int kierunek = rand() % 4;
    nowyX = x;
    nowyY = y;

    switch (kierunek) {
        case 0: nowyY--; break;
        case 1: nowyY++; break;
        case 2: nowyX--; break;
        case 3: nowyX++; break;
    }
}

bool Zwierze::sprobujRozmnozenie(Organizm* partner) {

    int nowyX = x, nowyY = y;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;

            nowyX = x + dx;
            nowyY = y + dy;

            if (swiat->czyPozycjaPoprawna(nowyX, nowyY) &&
                !swiat->getOrganizmNaPolu(nowyX, nowyY)) {
                // Create a new organism of the same type
                swiat->dodajOrganizm(this->stworzPotomka(nowyX, nowyY));
                return true;
            }
        }
    }

    return false;
}