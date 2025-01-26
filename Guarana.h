#ifndef GUARANA_H
#define GUARANA_H

#include "Roslina.h"
#include "Zwierze.h"

class Guarana : public Roslina {
public:
    Guarana(Swiat* swiat, int x, int y);

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;

protected:
    Roslina* stworzPotomka(int nowyX, int nowyY) override;
};

#endif // GUARANA_H