#include "Swiat.h"
#include "Wilk.h"
#include "Trawa.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Lew.h"
#include "Zolw.h"
#include "Kot.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <random>

Swiat::Swiat(int width, int height) : width(width), height(height) {
    srand(time(nullptr));
    inicjalizujSwiat();
}

Swiat::~Swiat() {
    for (auto organizm : organizmy) {
        delete organizm;
    }
    organizmy.clear();
}

void Swiat::wykonajTure() {

    sortujOrganizmy();

    size_t liczbaOrganizmow = organizmy.size();
    for (size_t i = 0; i < liczbaOrganizmow; i++) {
        if (organizmy[i] != nullptr) {
            organizmy[i]->zwiekszWiek();
            organizmy[i]->akcja();
        }
    }

    czyscMartweOrganizmy();
}

void Swiat::rysujSwiat() const {

    std::cout << "+";
    for (int i = 0; i < width; i++) std::cout << "-";
    std::cout << "+\n";

    for (int y = 0; y < height; y++) {
        std::cout << "|";
        for (int x = 0; x < width; x++) {
            Organizm* org = getOrganizmNaPolu(x, y);
            if (org != nullptr) {
                org->rysowanie();
            } else {
                std::cout << " ";
            }
        }
        std::cout << "|\n";
    }

    std::cout << "+";
    for (int i = 0; i < width; i++) std::cout << "-";
    std::cout << "+\n";
}

void Swiat::dodajOrganizm(Organizm* organizm) {
    if (organizm == nullptr) return;

    try {
        if (!czyPozycjaPoprawna(organizm->getX(), organizm->getY())) {
            throw std::out_of_range("Pozycja organizmu poza granicami świata");
        }

        if (getOrganizmNaPolu(organizm->getX(), organizm->getY()) != nullptr) {
            throw std::runtime_error("Pole jest już zajęte przez inny organizm");
        }

        organizmy.push_back(organizm);
    }
    catch (const std::exception& e) {
        delete organizm;
        throw;
    }
}

void Swiat::usunOrganizm(Organizm* organizm) {
    for (auto it = organizmy.begin(); it != organizmy.end(); ++it) {
        if (*it == organizm) {
            delete *it;
            organizmy.erase(it);
            break;
        }
    }
}

Organizm* Swiat::getOrganizmNaPolu(int x, int y) const {
    for (auto organizm : organizmy) {
        if (organizm != nullptr && organizm->getX() == x && organizm->getY() == y) {
            return organizm;
        }
    }
    return nullptr;
}

bool Swiat::czyPozycjaPoprawna(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

std::vector<std::pair<int, int>> Swiat::getWolnePolaSasiednie(int x, int y) const {
    std::vector<std::pair<int, int>> wolnePola;

    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;

            int newX = x + dx;
            int newY = y + dy;

            if (czyPozycjaPoprawna(newX, newY) && getOrganizmNaPolu(newX, newY) == nullptr) {
                wolnePola.emplace_back(newX, newY);
            }
        }
    }

    return wolnePola;
}

void Swiat::sortujOrganizmy() {
    std::sort(organizmy.begin(), organizmy.end(),
        [](const Organizm* a, const Organizm* b) {
            if (a == nullptr) return false;
            if (b == nullptr) return true;

            if (a->getInicjatywa() != b->getInicjatywa())
                return a->getInicjatywa() > b->getInicjatywa();

            if (a->getWiek() != b->getWiek())
                return a->getWiek() > b->getWiek();

            return false;
        });
}

void Swiat::czyscMartweOrganizmy() {
    organizmy.erase(
        std::remove_if(organizmy.begin(), organizmy.end(),
            [](Organizm* org) { return org == nullptr; }),
        organizmy.end()
        );
}

void Swiat::inicjalizujSwiat() {
    for (auto organizm : organizmy) {
        delete organizm;
    }
    organizmy.clear();

    auto getLosowaWolnaPozycja = [this]() -> std::pair<int, int> {
        while (true) {
            int x = rand() % width;
            int y = rand() % height;
            if (getOrganizmNaPolu(x, y) == nullptr) {
                return {x, y};
            }
        }
    };

    int liczbaKazdegoPoczatkowego = 2;

    for (int i = 0; i < 10; i++) {
        auto [x, y] = getLosowaWolnaPozycja();
        dodajOrganizm(new Wilk(this, x, y));
    }
    for (int i = 0; i < 10; i++) {
         auto [x, y] = getLosowaWolnaPozycja();
         dodajOrganizm(new Owca(this, x, y));
     }
     for (int i = 0; i < liczbaKazdegoPoczatkowego; i++) {
         auto [x, y] = getLosowaWolnaPozycja();
         dodajOrganizm(new Zolw(this, x, y));
     }
     for (int i = 0; i < 10; i++) {
         auto [x, y] = getLosowaWolnaPozycja();
         dodajOrganizm(new Lew(this, x, y));
     }
     for (int i = 0; i < liczbaKazdegoPoczatkowego; i++) {
         auto [x, y] = getLosowaWolnaPozycja();
         dodajOrganizm(new Trawa(this, x, y));
     }
    for (int i = 0; i < liczbaKazdegoPoczatkowego; i++) {
         auto [x, y] = getLosowaWolnaPozycja();
         dodajOrganizm(new Mlecz(this, x, y));
     }
     for (int i = 0; i < liczbaKazdegoPoczatkowego; i++) {
         auto [x, y] = getLosowaWolnaPozycja();
         dodajOrganizm(new Guarana(this, x, y));
     }
    for (int i = 0; i < liczbaKazdegoPoczatkowego; i++) {
        auto [x, y] = getLosowaWolnaPozycja();
        dodajOrganizm(new Kot(this, x, y));
    }
}

void Swiat::zapiszDoPliku(const std::string& nazwaPliku) const {
    std::ofstream plik(nazwaPliku);
    if (!plik.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku do zapisu");
    }

    plik << width << " " << height << "\n";

    plik << organizmy.size() << "\n";

    //TBD

    plik.close();
}

void Swiat::wczytajZPliku(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        throw std::runtime_error("Nie można otworzyć pliku do odczytu");
    }
    plik >> width >> height;

    for (auto organizm : organizmy) {
        delete organizm;
    }
    organizmy.clear();

    //TBD

    plik.close();
}