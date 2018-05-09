#include "Lion.h"

Lion::Lion()
{
    nom = "Lion";
    lettre = 'L';
}

void Lion::affiche(){
    cout<<"x = "<<x<<" y = "<<y<<" type = "<< nom<<"\n";
}
char Lion::getterId() const{
   return lettre;
}
