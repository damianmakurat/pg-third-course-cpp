#include "Mlecz.h"

Mlecz::Mlecz(Swiat* swiat, int x, int y)
: Roslina(swiat, x, y, 0, 'M') {}

void Mlecz::akcja() {
    for (int i = 0; i < 3; ++i) {
        sprobujRozprzestrzenanie();
    }
}

void Mlecz::kolizja(Organizm* atakujacy) {
}

Roslina* Mlecz::stworzPotomka(int nowyX, int nowyY) {
    return new Mlecz(swiat, nowyX, nowyY);
}
