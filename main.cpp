#include <iostream>
#include <vector>
#include <string>

#include "main.h"

using namespace std;

int main()
{
    t_tableau tab = alloue_tableau(5);
    init_tableau(tab);
    display_tableau(tab);
    destruct_tableau(&tab);

    display_tableau(tab);
    
}

t_tableau alloue_tableau(int n)
{
    t_tableau t;
    t.nb_elem = n;
    t.tab = (int *)malloc(sizeof(int) * n);
    if(t.tab == NULL)
        exit(EXIT_FAILURE);
    return t;
}
void destruct_tableau(t_tableau * tab)
{
    free(tab->tab);
    tab->nb_elem = 0;    
}
void init_tableau(t_tableau tab)
{
    for(int i =0; i < tab.nb_elem; i++){
        tab.tab[i] = rand()%30 + 1;
    }
}
void display_tableau(t_tableau tab)
{
    cout << "affichage du tableau avec " << tab.nb_elem << " élements" << endl;

    for(int i = 0; i < tab.nb_elem; i++){
        cout << i << " : " << tab.tab[i] << endl;
    }
    cout << endl;
}
t_tableau double_tableau(t_tableau tab)
{
    t_tableau t;
    t.nb_elem = tab.nb_elem;
    t.tab = (int *)malloc(sizeof(int) * tab.nb_elem);
    return t;
}