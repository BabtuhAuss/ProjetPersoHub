#include "main_fondamentaux.h"

int init_main_fondamentaux()
{
    fichiers();
    return 0;
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

void moyenne()
{
    //pour utiliser les vecteurs dans des fonctions, il vaut mieux utiliser le passage par référence constante afin d'optimiser la copie (sauf
    // que le vectuer ne sera pas modifiable).
    vector<double> notes;
    notes.push_back(4);
    notes.push_back(8);
    notes.push_back(5);
    notes.push_back(9.5);

    double moyenne(0);
    for (unsigned int i(0); i < notes.size(); i++)
    {
        moyenne += notes[i];
    }
    moyenne /= notes.size();

    cout << "la moyenne des notes " << endl
         << "est de " << moyenne << endl;
}

void fichiers()
{
    string const nomFichier("test.txt");
    lecture_fichier(nomFichier);
    taille_fichier(nomFichier);

}
void ecriture_fichier(string const &nomFichier)
{
    ofstream monFlux(nomFichier.c_str(), ios::app); // declaration d'un flux permettant d'écrire dans un fichier

    int position_curseur; // position du curseur pour l'écriture

    if (monFlux)
    {
        //...faire le code
        monFlux << "coucou je suis un texte ecrit par le programme" << endl;
        position_curseur = monFlux.tellp();
        cout << "position du curseur=" << position_curseur << endl;
        monFlux << 42.5 << endl;
    }
    else
    {
        cout << "ERREUR : impossible d'ouvrir le fichier" << endl;
    }
}

void lecture_fichier(string const &nomFichier)
{
    /*
    il y a trois moyens de lire un fichier : 
    -   getline()   ligne par ligne
    -   >>          mot par mot
    -   get()       caractère par caractère    
    */
    ifstream monFlux(nomFichier.c_str());

    if (monFlux)
    {
        //Tout est prêt pour la lecture.
        string ligne;
        getline(monFlux, ligne); //On lit une ligne complète
        cout << ligne << endl;
        double nombre(1);

        monFlux >> nombre; //Lit un nombre à virgule depuis le fichier
        string mot;
        monFlux >> mot; //Lit un mot depuis le fichier
        monFlux.ignore();

        cout << nombre << " " << mot << endl;

        int position; // utile pour connaitre la position du curseur lors de la lecture d'un fichier

        int nombreCaracteres(10);

        /*  le début du fichier :   ios::beg;
            la fin du fichier :     ios::end;
            la position actuelle :  ios::cur. */
        monFlux.seekg(nombreCaracteres, ios::beg);
        //lire tout un fichier
        while (getline(monFlux, ligne))
        {
            position = monFlux.tellg();
            cout << ligne << endl
                 << "position du curseur =" << position << endl;
            
        }

        monFlux.close(); //fermeture du fichier
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}

void taille_fichier(string nomFichier){
    
        ifstream fichier(nomFichier.c_str()); //On ouvre le fichier
        fichier.seekg(0, ios::end); //On se déplace à la fin du fichier

        int taille;
        taille = fichier.tellg();
        //On récupère la position qui correspond donc a la taille du fichier !

        cout << "Taille du fichier : " << taille << " octets." << endl;
}