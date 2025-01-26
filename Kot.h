#ifndef KOT_H
#define KOT_H

#include "Zwierze.h"

class Kot : public Zwierze {
public:
    Kot(Swiat* swiat, int x, int y);

protected:
    Kot* stworzPotomka(int nowyX, int nowyY) override;
};

#endif // KOT_H