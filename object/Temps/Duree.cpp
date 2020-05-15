#include "Duree.h"

using namespace std;

Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
    if (minutes < 0 || secondes < 0)
    {
        cout << "erreur dans l'entrée de la date";
        exit(EXIT_FAILURE);
    }
    else if (m_minutes > 60 || m_secondes > 60)
    {
        cout << "changement de la date pour la reconvertir" << endl;
        while (m_secondes > 60)
        {
            m_secondes = m_secondes - 60;
            m_minutes++;
        }
        while (minutes > 60)
        {
            m_minutes = m_minutes - 60;
            m_heures++;
        }

        cout << "nouvelle durée valide :" << m_heures << ":" << m_minutes << ":" << m_secondes << endl;
    }
    
}

bool Duree::estEgal(Duree const& b) const
{
    //Teste si a.m_heure == b.m_heure etc.  
    if (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes)
        return true;
    else
        return false;
}

bool operator==(Duree const& a, Duree const& b)
{
    return a.estEgal(b);
}

bool operator!=(Duree const& a, Duree const& b)
{
    return !(a==b); //On utilise l'opérateur == qu'on a défini précédemment !
}