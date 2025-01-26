#ifndef TRAWA_H
#define TRAWA_H

#include "Roslina.h"
#include "Swiat.h"

class Trawa : public Roslina {
public:
    Trawa(Swiat* swiat, int x, int y);

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

protected:
    Roslina* stworzPotomka(int nowyX, int nowyY) override;
};

#endif // TRAWA_H
