#ifndef DEF_PERSONNAGE_old
#define DEF_PERSONNAGE_old

#include <iostream>
#include <string>
#include "Arme.h" //Ne PAS oublier d'inclure Arme.h pour en avoir la définition

class Personnage
{
public:
    Personnage();

    //constructeur de copie;
    Personnage(Personnage const &personnageACopier);

    Personnage(std::string nomArme, int degatsArme);
    ~Personnage();
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;

    void afficherEtat() const;

    Personnage& operator=(Personnage const& personnageACopier);

private:
    int m_vie;
    int m_mana;

    //    Arme m_arme; //Notre Personnage possède une Arme

    //pointeurs object
    Arme *m_arme;
};

#endif