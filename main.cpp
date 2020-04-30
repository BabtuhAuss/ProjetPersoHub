#include <iostream>
#include <vector>
#include <string>

#include "main.h"

using namespace std;

int main()
{
    t_tableau tab = alloue_tableau(5);
}

t_tableau alloue_tableau(int n)
{
    t_tableau t;
    t.nb_elem = n;
    t.tab = (int *)malloc(sizeof(int) * n);
    return t;
}
void destruct_tableau(t_tableau tab)
{
}
void init_tableau(t_tableau tab)
{
}
void display_tableau(t_tableau tab)
{
}
t_tableau double_tableau(t_tableau tab)
{
    t_tableau t;
    t.nb_elem = tab.nb_elem;
    t.tab = (int *)malloc(sizeof(int) * tab.nb_elem);
    return t;
}