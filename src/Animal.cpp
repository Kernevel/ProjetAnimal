#include "Animal.h"

  int Animal::nb_animaux=0;

  Animal::Animal():x(0),y(0),energie(100){
    nb_animaux++;
  }

  Animal::Animal(int xinit, int yinit, int einit){
    x=xinit;
    y=yinit;
    energie=einit;
    nb_animaux++;
  }

  Animal::~Animal(){
    nb_animaux--;
  }

  int Animal::getterX() const{
    return x;
  }

  int Animal::getterY() const{
    return y;
  }

  int Animal::getterE() const{
    return energie;
  }

  char Animal::getterId() const{
   return lettre;
 }

  void Animal::setterX(int xinit){
    x=xinit;
  }

  void Animal::setterY(int yinit){
    y=yinit;
  }

  void Animal::setterE(int einit){
    energie=einit;
  }

  void Animal::setterL(char l){
    lettre=l;
  }


  void Animal::affiche(){
    cout << "x="<<x<<"\n"<<"y="<<y<<"\n"<<"energie="<< energie<<"\n";
  }

  int Animal::getCount(){
    return nb_animaux;
  }

  void Gazelle::affiche(){
    cout<<"x = "<<x<<" y = "<<y<<" type = "<< nom<<"\n";
  }

  char Gazelle::getterId() const{
   return lettre;
 }
  void Lion::affiche(){
    cout<<"x = "<<x<<" y = "<<y<<" type = "<< nom<<"\n";
  }
  char Lion::getterId() const{
   return lettre;
 }