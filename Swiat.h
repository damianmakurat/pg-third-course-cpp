#ifndef SWIAT_H
#define SWIAT_H

#include <vector>
#include <string>

#include "Organizm.h"

class Swiat {

public:
    Swiat(int width = DOMYSLNY_ROZMIAR, int height = DOMYSLNY_ROZMIAR);
    ~Swiat();

    // Glowne metody gry
    void wykonajTure();
    void rysujSwiat() const;

    // Zarzadzanie organizmami
    void dodajOrganizm(Organizm* organizm);
    void usunOrganizm(Organizm* organizm);
    Organizm* getOrganizmNaPolu(int x, int y) const;

    // Metody pomocnicze
    bool czyPozycjaPoprawna(int x, int y) const;
    std::vector<std::pair<int, int>> getWolnePolaSasiednie(int x, int y) const;

    // Gettery
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    // Zapis i odczyt stanu gry
    void zapiszDoPliku(const std::string& nazwaPliku) const;
    void wczytajZPliku(const std::string& nazwaPliku);

private:
    void inicjalizujSwiat();

    static const int DOMYSLNY_ROZMIAR = 20;
    int width;
    int height;
    std::vector<Organizm*> organizmy;

    void sortujOrganizmy();
    void czyscMartweOrganizmy();
    void wypiszInformacje(const std::string& info) const;
};

#endif // SWIAT_H