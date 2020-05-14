#include <iostream>
#include <string>
#include "main_object.h"
#include "Personnage.h"

using namespace std;

int init_main_object()
{
    Personnage goliath("Épée aiguisée", 20);
    Personnage david(goliath); //On crée david en copiant tous les attributs de goliath

    //Si toute fois, on veut changer le comportement du constructeur de copie, il faut simplement le déclarer dans l cllasse classe de la manière suivante
    //Personnage(Personnage const& autre);
    /* et changer comme ça la fonction
    Personnage::Personnage(Personnage const& autre): m_vie(autre.m_vie), m_mana(autre.m_mana), m_nomArme(autre.m_nomArme), m_degatsArme(autre.m_degatsArme)
    {
    }
    */
    //Au combat !
    goliath.attaquer(david);
    david.boirePotionDeVie(20);
    goliath.attaquer(david);
    david.attaquer(goliath);
    goliath.changerArme("Double hache tranchante vénéneuse de la mort", 40);
    goliath.attaquer(david);
 
    //Temps mort ! Voyons voir la vie de chacun…
    cout << "David" << endl;
    david.afficherEtat();
    cout << endl << "Goliath" << endl;
    goliath.afficherEtat();
 
    return 0;
}