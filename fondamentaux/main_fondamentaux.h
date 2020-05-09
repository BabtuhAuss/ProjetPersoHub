#ifndef MATH_H_INCLUDED
#define MATH_H_INCLUDED

#include<iostream>
#include<string>
#include<cmath>
#include <vector>
#include<fstream>

using namespace std;

/**
 * \brief main des fondamentaux
 * \param rien
 * \return 0 pour dire que tout s'est bien passé
 */
int init_main_fondamentaux(void);


int manipulation_string(void);
int manipulation_maths(void);

int passage_reference(void);
int ajoute_deux(int&);

int nombre_secondes(int heures, int minutes = 0 , int seconde = 0);

void moyenne(void);

void fichiers();
void ecriture_fichier(string const& nomFichier);
void lecture_fichier(string const& nomFichier);

void taille_fichier(string nomFichier);

#endif // MATH_H_INCLUDED