#ifndef MLECZ_H
#define MLECZ_H

#include "Roslina.h"

class Mlecz : public Roslina {
public:
    Mlecz(Swiat* swiat, int x, int y);

    void akcja() override;

    void kolizja(Organizm* atakujacy) override;
protected:
    Roslina* stworzPotomka(int nowyX, int nowyY) override;
};

#endif // MLECZ_H