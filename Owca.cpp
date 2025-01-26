#include "Owca.h"

Owca::Owca(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y, 4, 4, 'O') {}

Owca* Owca::stworzPotomka(int nowyX, int nowyY) {
    return new Owca(swiat, nowyX, nowyY);
}
