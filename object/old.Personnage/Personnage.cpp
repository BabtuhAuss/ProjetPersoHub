#include "Personnage.h"

using namespace std;


/*

ce constructeur est aussi efficace
Personnage::Personnage() : m_vie(100), m_mana(100), m_nomArme("Épée rouillée"), m_degatsArme(10)
{
    //Rien à mettre dans le corps du constructeur, tout a déjà été fait !
}


*/

// Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100),m_arme(nomArme, degatsArme)
// {
 
// }
// Personnage::Personnage()
// {
//     m_vie = 100;
//     m_mana = 100;
//     m_arme = Arme("Épée rouillée", 10);
// }

//pointeur object 
Personnage::Personnage() : m_vie(100), m_mana(100), m_arme(0)
{
    m_arme = new Arme();
}
Personnage::Personnage(string nomArme, int degatsArme) : m_arme(0), m_vie(100), m_mana(100)
{
    m_arme = new Arme(nomArme, degatsArme);
}


Personnage::Personnage(Personnage const& personnageACopier) 
   : m_vie(personnageACopier.m_vie), m_mana(personnageACopier.m_mana), m_arme(0)
{
    //il faut envoyer l'objet lui-même et pas son adresse
    m_arme = new Arme(*(personnageACopier.m_arme));
}



void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;
    //On enlève le nombre de dégâts reçus à la vie du personnage

    if (m_vie < 0) //Pour éviter d'avoir une vie négative
    {
        m_vie = 0; //On met la vie à 0 (cela veut dire mort)
    }
}

// void Personnage::attaquer(Personnage &cible)
// {
//     cible.recevoirDegats(m_arme.getDegats());
// }
// void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
// {
//     m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
// }

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme->getDegats());
}
void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme->changer(nomNouvelleArme, degatsNouvelleArme);
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdiction de dépasser 100 de vie
    {
        m_vie = 100;
    }
}

/*

    Pour vous : 
        vous savez que votre méthode ne fait que lire les attributs et 
        vous vous interdisez dès le début de les modifier. 
        Si par erreur vous tentez d'en modifier un, 
        le compilateur plante en vous reprochant 
        de ne pas respecter la règle que vous vous êtes fixée. Et cela, c'est bien.

    Pour les utilisateurs de votre classe : 
        c'est très important aussi pour eux, cela leur indique 
        que la méthode se contente de renvoyer un résultat 
        et qu'elle ne modifie pas l'objet.
        Dans une documentation, le mot-clé const apparaît dans le prototype de la méthode 
        et c'est un excellent indicateur de ce qu'elle fait,
        ou plutôt de ce qu'elle ne peut pas faire
        (cela pourrait se traduire par : « cette méthode ne modifiera pas votre objet »).

    Pour le compilateur : 
        si vous vous rappelez le chapitre sur les variables,
        je vous conseillais de toujours déclarer const ce qui peut l'être.
        Nous sommes ici dans le même cas. 
        On offre des garanties aux utilisateurs de la classe 
        et on aide le compilateur à générer du code binaire de meilleure qualité.

*/

bool Personnage::estVivant() const
{
    return m_vie > 0;
}


// void Personnage::afficherEtat() const
// {
//     cout << "Vie : " << m_vie << endl;
//     cout << "Mana : " << m_mana << endl;
//     m_arme.afficher();
// }
void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme->afficher();
}

Personnage::~Personnage()
{
    delete m_arme;
}



Personnage& Personnage::operator=(Personnage const& personnageACopier) 
{
    if(this != &personnageACopier)
    //On vérifie que l'objet n'est pas le même que celui reçu en argument
    {
        m_vie = personnageACopier.m_vie; //On copie tous les champs
        m_mana = personnageACopier.m_mana;
	delete m_arme;
        m_arme = new Arme(*(personnageACopier.m_arme));
    }
    return *this; //On renvoie l'objet lui-même
}