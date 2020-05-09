#include "main_mystere.h"

int init_main_mystere()
{
    cout << "********************************" << endl
         << "*                              *" << endl
         << "* TRAVAIL PRATIQUE MOT MYSTERE *" << endl
         << "*                              *" << endl
         << "********************************" << endl;

    string mot_mystere, mot_mystere_melange;

    //initialisation de la génération de nombres aléatoires
    srand(time(0));

    //demande de saisie d'un mot par le joueur 1
    cout << "veuillez entrer le mot à trouver" << endl;
    cin >> mot_mystere;

    for (int i(0); i < 20; i++)
    {
        cout << endl;
    }
    // mélange de lettres
    mot_mystere_melange = melanger_mot(mot_mystere);
    //demande au joueur 2 le mot
    string input;
    do
    {
        cout << "Quel est ce mot : " << mot_mystere_melange << endl;
        cin >> input;
    } while (input != mot_mystere);

    cout << "bravo !";
    return 0;
}

string melanger_mot(string mot_a_melanger)
{
    string mot_melanger;
    int position;

    while (mot_a_melanger.size() > 0)
    {
        position = rand() % mot_a_melanger.size();
        mot_melanger += mot_a_melanger[position];
        mot_a_melanger.erase(position, 1);
    }
    return mot_melanger;
}

void melanger_mot_par_reference(string mot_a_melanger, string &mot_melanger)
{
}