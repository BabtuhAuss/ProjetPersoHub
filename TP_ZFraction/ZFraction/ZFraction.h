#ifndef H_ZFRACTION
#define H_ZFRACTION

#include <iostream>

class ZFraction
{
public:
    ZFraction(int numerateur = 0, int denominateur = 1);

    ZFraction(int numerateur = 0);
    
    ZFraction();
private:
    int m_numerateur;
    int m_denominateur;
};

#endif