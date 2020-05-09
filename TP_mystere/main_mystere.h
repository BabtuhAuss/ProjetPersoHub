#ifndef MAIN_MYSTERE
#define MAIN_MYSTERE

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int init_main_mystere(void);
string melanger_mot(string mot_a_melanger);
void melanger_mot_par_reference(string mot_a_melanger, string &mot_melanger);

#endif