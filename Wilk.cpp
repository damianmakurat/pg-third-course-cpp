#include "Wilk.h"

Wilk::Wilk(Swiat* swiat, int x, int y) : Zwierze(swiat, x, y, 9, 5, 'W') {}

Wilk* Wilk::stworzPotomka(int nowyX, int nowyY) {
    return new Wilk(swiat, nowyX, nowyY);
}