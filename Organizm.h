#ifndef ORGANIZM_H
#define ORGANIZM_H

class Swiat;

class Organizm {

public:
    Organizm(Swiat* swiat, int x, int y, int sila, int inicjatywa, char symbol);
    virtual ~Organizm() = default;

    // Gettery
    int getSila() const { return sila; }
    int getInicjatywa() const { return inicjatywa; }
    int getX() const { return x; }
    int getY() const { return y; }
    char getSymbol() const { return symbol; }
    int getWiek() const { return wiek; }
    void zwiekszWiek() { wiek++; }

    // Settery
    void setSila(int nowaSila) { sila = nowaSila; }
    void setPozycja(int nowyX, int nowyY);

    // Metody wirtualne
    virtual void akcja() = 0;
    virtual void kolizja(Organizm* other) = 0;
    virtual void rysowanie() const;
    virtual bool czyOdparlAtak(Organizm* atakujacy) { return false; }
    virtual bool czyUcieka(Organizm* atakujacy) { return false; }

    // Dodatkowe metody pomocnicze
    bool czyTenSamGatunek(const Organizm* other) const;

protected:
    int sila;
    int inicjatywa;
    int x;
    int y;
    Swiat* swiat;
    char symbol;
    int wiek;
};

#endif // ORGANIZM_H