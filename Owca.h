#ifndef OWCA_H
#define OWCA_H

#include "Zwierze.h"

class Owca : public Zwierze {
public:
    Owca(Swiat* swiat, int x, int y);

protected:
    Owca* stworzPotomka(int nowyX, int nowyY) override;
};

#endif // OWCA_H
