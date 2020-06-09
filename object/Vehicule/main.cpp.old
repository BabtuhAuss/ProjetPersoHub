#include "Vehicule.h"

using namespace std;

void presenter(Vehicule const &v) //Présente le véhicule passé en argument
{
    v.affiche();
}

int main()
{
    vector<Vehicule *> listeVehicules;

    listeVehicules.push_back(new Voiture(15000, 5, 1999));
    listeVehicules.push_back(new Voiture(12000, 3, 2002));
    listeVehicules.push_back(new Camion(2000, 212234, 1990));

    listeVehicules[0]->affiche();
    //On affiche les informations de la première voiture

    listeVehicules[2]->affiche();
    //Et celles de la moto

    for (unsigned int i(0); i < listeVehicules.size(); ++i)
    {
        delete listeVehicules[i]; //On libère la i-ème case mémoire allouée
        listeVehicules[i] = 0;    //On met le pointeur à 0 pour éviter les soucis
    }

    Vehicule *ptr(0); //Un pointeur sur un véhicule

    Voiture caisse(20000, 5,1999);
    //On crée une voiture
    //Ceci est autorisé puisque toutes les fonctions ont un corps

    ptr = &caisse; //On fait pointer le pointeur sur la voiture

    cout << ptr->nbrRoues() << endl;
    //Dans la classe fille, nbrRoues() existe, ceci est donc autorisé

    return 0;
}