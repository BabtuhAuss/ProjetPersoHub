#include "Magicien.h"

using namespace std;

Magicien::Magicien() : Personnage(), m_mana(100)
{
 
}
Magicien::Magicien(string nom) : Personnage(nom), m_mana(100)
{
 
}

void Magicien::sePresenter() const
{
    Personnage::sePresenter();
    cout << "je suis un magicien redoutable." << endl;
}