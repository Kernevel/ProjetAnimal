#include "Animal.h"

  int Animal::nb_animaux=0;

  Animal::Animal():x(0),y(0),energie(100), nom("undefined")
  {
    nb_animaux++;
  }

  Animal::Animal(int xinit, int yinit, int einit):nom("undefined")
  {
    x=xinit;
    y=yinit;
    energie=einit;
    nb_animaux++;
  }

  Animal::~Animal(){
    nb_animaux--;
  }

  void Animal::setPixmap(const QPixmap pix)
  {
    img = new QGraphicsPixmapItem(pix.scaled(24,24));
  }

  QGraphicsPixmapItem *Animal::getImg() const
  {
    return (img);
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
