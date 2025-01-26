#ifndef ROSLINA_H
#define ROSLINA_H

#include "Organizm.h"
#include <utility>

class Roslina : public Organizm {

public:
    Roslina(Swiat* swiat, int x, int y, int sila, char symbol);
    virtual ~Roslina() = default;

    void akcja() override;
    void kolizja(Organizm* atakujacy) override;

protected:
    bool sprobujRozprzestrzenanie();
    std::pair<int, int> znajdzWolnePoleSasiednie() const;
    virtual bool czyOdparlAtak(Organizm* atakujacy) { return false; }
    virtual bool czyUcieka(Organizm* atakujacy) { return false; }
    static const int SZANSA_ROZPRZESTRZENIENIA = 15;
    virtual Roslina* stworzPotomka(int nowyX, int nowyY) = 0;

};

#endif // ROSLINA_H