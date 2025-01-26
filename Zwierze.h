#ifndef ZWIERZE_H
#define ZWIERZE_H

#include "Organizm.h"

class Zwierze : public Organizm {

public:
    Zwierze(Swiat* swiat, int x, int y, int sila, int inicjatywa, char symbol);
    virtual ~Zwierze() = default;

    void akcja() override;
    void kolizja(Organizm* other) override;

    void zwiekszSile(int wartosc);

protected:
    void losujNowaPozycje(int& nowyX, int& nowyY);
    bool sprobujRozmnozenie(Organizm* partner);
    virtual bool czyOdparlAtak(Organizm* atakujacy) { return false; }
    virtual bool czyUcieka(Organizm* atakujacy) { return false; }
    virtual Zwierze* stworzPotomka(int nowyX, int nowyY) = 0;
};

#endif // ZWIERZE_H
