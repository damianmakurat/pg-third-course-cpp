#include "Roslina.h"
#include "Swiat.h"
#include <cstdlib>
#include <iostream>

Roslina::Roslina(Swiat* swiat, int x, int y, int sila, char symbol)
: Organizm(swiat, x, y, sila, 0, symbol) {}

void Roslina::akcja() {
    sprobujRozprzestrzenanie();
}

void Roslina::kolizja(Organizm* atakujacy) {
    std::cout << "Organizm " << atakujacy->getSymbol() << " zjada rosline " << this->symbol << std::endl;
    swiat->usunOrganizm(this);
}

bool Roslina::sprobujRozprzestrzenanie() {
    if (rand() % 100 < SZANSA_ROZPRZESTRZENIENIA) {
        auto nowaPozycja = znajdzWolnePoleSasiednie();

        if (nowaPozycja.first != -1 && nowaPozycja.second != -1) {
            Roslina* nowaRoslina = stworzPotomka(nowaPozycja.first, nowaPozycja.second);
            try {
                swiat->dodajOrganizm(nowaRoslina);
                std::cout << "Nowa roslina " << this->symbol << " wyrosla na polu ("
                         << nowaPozycja.first << "," << nowaPozycja.second << ")" << std::endl;
                return true;
            }
            catch (const std::exception& e) {
                delete nowaRoslina;
                return false;
            }
        }
    }
    return false;
}
std::pair<int, int> Roslina::znajdzWolnePoleSasiednie() const {
    const int kierunki[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    std::vector<std::pair<int, int>> wolnePola;

    for (int i = 0; i < 4; i++) {
        int nowyX = x + kierunki[i][0];
        int nowyY = y + kierunki[i][1];

        if (swiat->czyPozycjaPoprawna(nowyX, nowyY) &&
            swiat->getOrganizmNaPolu(nowyX, nowyY) == nullptr) {
            wolnePola.emplace_back(nowyX, nowyY);
        }
    }

    if (!wolnePola.empty()) {
        int index = rand() % wolnePola.size();
        return wolnePola[index];
    }

    return std::make_pair(-1, -1);
}
