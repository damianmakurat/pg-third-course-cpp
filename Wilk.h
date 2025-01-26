#ifndef WILK_H
#define WILK_H

#include "Zwierze.h"

class Wilk : public Zwierze {
public:
    Wilk(Swiat* swiat, int x, int y);

protected:
    Wilk* stworzPotomka(int nowyX, int nowyY) override;
};

#endif // WILK_H