#include "Vehicule.h"

using namespace std;

Vehicule::Vehicule(int prix, int anneeFabrication)
    : m_prix(prix), m_dateFabrication(anneeFabrication)
{
}

void Vehicule::affiche() const
//J'en profite pour modifier un peu les fonctions d'affichage
{
    cout << "Ceci est un vehicule provenant de l'année " << m_dateFabrication << endl;
}

Vehicule::~Vehicule() //Même si le destructeur ne fait rien, on doit le mettre !
{
}

Voiture::Voiture(int prix, int portes, int anneeFabrication)
    : Vehicule(prix, anneeFabrication), m_portes(portes)
{
}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes et coutant " << m_prix << " euros." << endl;
}

Voiture::~Voiture()
{
}

Moto::Moto(int prix, double vitesseMax, int anneeFabrication)
    : Vehicule(prix, anneeFabrication), m_vitesse(vitesseMax)
{
}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
}

Moto::~Moto()
{
}

Camion::Camion(int prix, int poidTransportable, int anneeFabrication)
    : Vehicule(prix, anneeFabrication), m_poidTransportable(poidTransportable)
{
}

void Camion::affiche() const
{
    Vehicule::affiche();
    cout << "Ceci est un camion pouvant transporter " << m_poidTransportable << "KGs et coutant " << m_prix << "euros." << endl;
}

Camion::~Camion()
{
}

int Voiture::nbrRoues() const
{
    return 4;
}

int Camion::nbrRoues() const
{
    return 6;
}
int Moto::nbrRoues() const
{
    return 2;
}