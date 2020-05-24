#ifndef H_ZFRACTION
#define H_ZFRACTION

#include <iostream>
#include <cstdlib>

class ZFraction
{
public:
    ZFraction(int numerateur=0, int denominateur=1);

    bool estEgal(ZFraction const &a) const;
    bool estPlusGrand(ZFraction const &a) const;
    ZFraction& operator+=(ZFraction const &a);
    ZFraction& operator*=(ZFraction const &a);
    void afficher(std::ostream &flux) const;
    void simplifie();
    
private:
    int m_numerateur;
    int m_denominateur;
};

bool operator==(ZFraction const &a, ZFraction const &b);
bool operator>(ZFraction const &a, ZFraction const &b);

ZFraction operator+(ZFraction const &a, ZFraction const &b);
ZFraction operator*(ZFraction const &a, ZFraction const &b);
std::ostream &operator<<(std::ostream &flux, ZFraction const &a);


int pgcd(int a,int b);
#endif