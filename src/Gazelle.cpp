#include "Gazelle.h"

Gazelle::Gazelle()
{
    nom = "Gazelle";
    lettre = 'G';
}

void Gazelle::affiche(){
    cout<<"x = "<<x<<" y = "<<y<<" type = "<< nom<<"\n";
}

char Gazelle::getterId() const
{
   return lettre;
}