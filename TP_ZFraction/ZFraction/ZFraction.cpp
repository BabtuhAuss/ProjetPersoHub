#include "ZFraction.h"

using namespace std;


int pgcd(int a, int b)
{
    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;
}





ZFraction::ZFraction(int num, int den)
    : m_numerateur(num), m_denominateur(den)
{
    simplifie();
}


bool ZFraction::estEgal(ZFraction const &a) const
{
    return (m_numerateur == a.m_numerateur) && (m_denominateur == a.m_denominateur);
}

bool ZFraction::estPlusGrand(ZFraction const &a) const
{
    //trouver si le dénominateur est le même
    if(m_denominateur == a.m_denominateur)
        return m_numerateur > a.m_numerateur;
    
    //sinon on mets tout sur la même fraction avec le produit en croix
    return m_numerateur * a.m_denominateur > a.m_numerateur * m_denominateur;
}

void ZFraction::afficher(ostream &flux) const
{
    if(m_denominateur == 1)
        flux << m_numerateur;
    else
        flux << m_numerateur << "/" << m_denominateur;
}


void ZFraction::simplifie()
{
    int nombre=pgcd(m_numerateur, m_denominateur); //Calcul du pgcd

    m_numerateur /= nombre;     //Et on simplifie
    m_denominateur /= nombre;
}

/*
    Surcharge des opérations
*/

ZFraction operator+(ZFraction const &a, ZFraction const &b)
{
    ZFraction copie(a);
    copie += b;
    return copie;
}
ZFraction operator*(ZFraction const &a, ZFraction const &b)
{
    ZFraction copie(a);
    copie *= b;
    return copie;
}


bool operator==(ZFraction const &a, ZFraction const &b)
{
    return a.estEgal(b);
}

bool operator>(ZFraction const &a, ZFraction const &b)
{
    return a.estPlusGrand(b);
}

ostream &operator<<( ostream &flux, ZFraction const& a)
{
    a.afficher(flux);
    return flux;
}


ZFraction& ZFraction::operator+=(ZFraction const &a)
{
    m_numerateur = m_numerateur * a.m_denominateur + m_denominateur * a.m_numerateur;
    m_denominateur = m_denominateur * a.m_denominateur;
    //réduire la fraction
    simplifie();
    return *this;    
}

ZFraction& ZFraction::operator*=(const ZFraction& a)
{
    m_numerateur*=a.m_numerateur;
    m_denominateur*=a.m_denominateur;
    
    //réduire la fraction
    simplifie();
    return *this;
}


