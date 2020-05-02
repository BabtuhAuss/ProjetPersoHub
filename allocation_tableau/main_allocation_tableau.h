#include <iostream>

using namespace std;

typedef struct
{
    int nb_elem; //nombre d'elements
    int * tab; //tableau en question
} t_tableau;


t_tableau alloue_tableau(int n);
void destruct_tableau(t_tableau * tab);
void init_tableau(t_tableau tab);
void display_tableau(t_tableau tab);
t_tableau double_tableau(t_tableau tab);