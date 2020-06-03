#include "Vehicule.h"

using namespace std;

void presenter(Vehicule const& v)  //Présente le véhicule passé en argument
{
    v.affiche();
}

int main()
{
    Vehicule v;
    presenter(v);

    Moto m;
    presenter(m);

    return 0;
}