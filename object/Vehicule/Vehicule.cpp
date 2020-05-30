#include "Vehicule.h"

using namespace std;

void Vehicule::affiche() const
{
    cout << "Ceci est un vehicule." << endl;
}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture." << endl;
}

void Moto::affiche() const
{
    cout << "Ceci est une moto." << endl;
}