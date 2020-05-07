#include "main_fondamentaux.h"

int init_main_fondamentaux()
{
    return nombre_secondes(6);
}

int manipulation_string()
{
    cout << "Combien vaut pi ?" << endl;
    double piUtilisateur(-1.); //On crée une case mémoire pour stocker unnombre réel
    cin >> piUtilisateur;      //Et on remplit cette case avec ce qu'écritl'utilisateur

    cin.ignore();

    cout << "Quel est votre nom ?" << endl;
    string nomUtilisateur("Sans nom"); //On crée une case mémoire pour contenir une chaine de caractères
    getline(cin, nomUtilisateur);      //On remplit cette case avec toute la ligne que l'utilisateur a écrit

    cout << "Vous vous appelez " << nomUtilisateur << " et vous pensez que pivaut " << piUtilisateur << "." << endl;
    return 0;
}

int manipulation_maths()
{
    double const nombre(16);
    double resultat;
    resultat = sqrt(nombre);
    cout << "la racine carrée de " << nombre << " est " << resultat << endl;

    return 0;
}

int passage_reference()
{
    int a(4), resultat;
    resultat = ajoute_deux(a);

    cout << a << " : " << resultat << endl;
    return 0;
}

//en ayant un argument const&, la constante référente ne peut ni être copié, ni modifiée
int ajoute_deux(int &a)
{
    a += 2;
    return a;
}

int nombre_secondes(int heures, int minutes, int secondes)
{
    int total = 0;

    total = heures * 60 * 60;
    total += minutes * 60;
    total += secondes;

    return total;
}