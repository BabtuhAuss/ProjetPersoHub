#include "Personnage.h"

using namespace std;

Personnage::Personnage()
{
    m_vie = 100;
    m_mana = 100;
    m_arme = Arme("Épée rouillée", 10);
}
/*

ce constructeur est aussi efficace
Personnage::Personnage() : m_vie(100), m_mana(100), m_nomArme("Épée rouillée"), m_degatsArme(10)
{
    //Rien à mettre dans le corps du constructeur, tout a déjà été fait !
}


*/

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100),m_arme(nomArme, degatsArme)
{
 
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

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
}
void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
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


void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}

Personnage::~Personnage()
{
    /* Rien à mettre ici car on ne fait pas d'allocation dynamique
    dans la classe Personnage. Le destructeur est donc inutile mais
    je le mets pour montrer à quoi cela ressemble.
    En temps normal, un destructeur fait souvent des delete et quelques
    autres vérifications si nécessaire avant la destruction de l'objet. */
}
