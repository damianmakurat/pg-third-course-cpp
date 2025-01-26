#ifndef ZOLW_H
#define ZOLW_H

#include "Zwierze.h"

class Zolw : public Zwierze {
protected:
    Zolw(Swiat* swiat, int x, int y);
    void akcja() override;
    bool czyOdparlAtak(Organizm* atakujacy) override;
    Zolw* stworzPotomka(int nowyX, int nowyY) override;

    friend class Swiat;
};

#endif // ZOLW_H