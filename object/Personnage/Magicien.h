#ifndef DEF_MAGICIEN
#define DEF_MAGICIEN
 
#include <iostream>
#include <string>
#include "Personnage.h"
 
class Magicien : public Personnage
{
    public:
        Magicien();
        Magicien(std::string nom);
        void bouleDeFeu() const;
        void bouleDeGlace() const;
        void sePresenter() const;
 
    private:
        int m_mana;
};
 
#endif