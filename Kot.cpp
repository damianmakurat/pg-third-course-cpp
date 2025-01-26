#include "Kot.h"
Kot::Kot(Swiat* swiat, int x, int y)
: Zwierze(swiat, x, y, 5, 9, 'K') {}

Kot* Kot::stworzPotomka(int nowyX, int nowyY) {
    return new Kot(swiat, nowyX, nowyY);
}