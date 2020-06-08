#ifndef VEHICULE_DEF
#define VEHICULE_DEF

#include <iostream>
#include <string>
#include <vector>

//Une classe qui possède au moins une méthode virtuelle pure est une classe abstraite. Notre classe
//Vehicule est donc une classe abstraite
class Vehicule
{
public:
    Vehicule(int prix, int anneeFabrication); //Construit un véhicule d'un certain prix
    virtual void affiche() const;
    virtual ~Vehicule(); //Remarquez le 'virtual' ici
    virtual int nbrRoues() const=0;

protected:
    int m_prix;
    int m_dateFabrication;
};

class Camion : public Vehicule
{
public:
    Camion(int prix, int poidTransportable, int anneeFabrication);
    virtual void affiche() const;
    virtual ~Camion();
    virtual int nbrRoues() const;

protected:
    int m_poidTransportable;
};

class Voiture : public Vehicule
{
public:
    Voiture(int prix, int portes, int anneeFabrication);
    //Construit une voiture dont on fournit le prix et le nombre de portes
    virtual void affiche() const;
    virtual ~Voiture();
    virtual int nbrRoues() const;

private:
    int m_portes;
};

class Moto : public Vehicule
{
public:
    Moto(int prix, double vitesseMax, int anneeFabrication);
    //Construit une moto d'un prix donné et ayant une certaine vitesse maximale
    virtual void affiche() const;
    virtual ~Moto();
    virtual int nbrRoues() const;

private:
    double m_vitesse;
};
#endif