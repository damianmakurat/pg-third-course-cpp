#ifndef LEW_H
#define LEW_H

#include "Zwierze.h"

class Lew : public Zwierze {
public:
    Lew(Swiat* swiat, int x, int y);

protected:
    Lew* stworzPotomka(int nowyX, int nowyY) override;
    bool czyOdparlAtak(Organizm* atakujacy) override;
};

#endif // LEW_H