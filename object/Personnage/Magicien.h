#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN
 
#include <iostream>
#include <string>
#include "Personnage.h"
 
class Magicien : public Personnage
{
    public:
        void bouleDeFeu() const;
        void bouleDeGlace() const;
 
    private:
        int m_mana;
};
 
#endif