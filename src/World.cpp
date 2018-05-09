#include "World.h"
#include <cstdlib>
#include <ctime>
#include <QGraphicsPixmapItem>
#include <unistd.h>

World::World()
{

}

World::World(int nb_anim, QObject *parent) : QGraphicsScene(parent){
  nb_animaux=nb_anim;
  for(int i=0;i<getMAX_X();i++){
    for(int o=0;o<getMAX_Y();o++){
      tab[i][o]=',';
    }
  }
  _lion = QPixmap("./img/Lion.png");
  _gazelle = QPixmap("./img/Gazelle.png");
  _sol = QPixmap("./img/sol.png");
  for (int y = 0; y < getMAX_Y(); y++)
  {
    for (int x = 0; x < getMAX_X(); x++)
    {
      QGraphicsPixmapItem *imgTmp = new QGraphicsPixmapItem(_sol.scaled(24,24));
      
      // std::cout << x * 24 << " " << y * 24 << std::endl;
      imgTmp->setPos(x * 24, y * 24);
      imgTmp->show();
      addItem(imgTmp);
      _imgsSol.push_back(imgTmp);
    }
  }

  setSceneRect(0,0, getMAX_X() * 24, getMAX_X() * 24);
}

int World::getMAX_X(){
  return MAX_X;
}

int World::getMAX_Y(){
  return MAX_Y;
}

int World::getAnim(){
  return nb_animaux;
}
void World::peuplement(){
  int status=0;
    Gazelle* gaz;
    Lion* soap;
    for (unsigned int i=0;i<nb_animaux;i++){
      switch (status) {
        case 0:
          gaz=new Gazelle;
          gaz->setterX(rand()%getMAX_X());
          gaz->setterY(rand()%getMAX_Y());
          gaz->setPixmap(_gazelle);
          addItem(gaz->getImg());
          world.push_back(gaz);
          //tab[world[i].getterX()][world[i].getterY()]='A';
          std::cout << "Position en x = " << world[i]->getterX()<<" Position en y = "<< world[i]->getterY()<<'\n';
          status=1;
          break;
        case 1:
          soap=new Lion;
          soap->setterX(rand()%getMAX_X());
          soap->setterY(rand()%getMAX_Y());
          soap->setPixmap(_lion);
          addItem(soap->getImg());
          world.push_back(soap);
          //tab[world[i].getterX()][world[i].getterY()]='A';
          std::cout << "Position en x = " << world[i]->getterX()<<" Position en y = "<< world[i]->getterY()<<'\n';
          status=0;
          break;
    }
  }
}

void World::affiche()
{
  for (unsigned int i = 0; i < _imgsSol.size(); i++)
  {
    _imgsSol[i]->show();
  }
  for (unsigned int i = 0; i < world.size(); i++)
  {
    world[i]->getImg()->setPos(world[i]->getterX() * 24, world[i]->getterY() * 24);
    world[i]->getImg()->show();
  }
}

void World::bouge(Animal *goelan)
{
      tab[goelan->getterX()][goelan->getterY()]=',';
      switch (rand()%4) {
        case 0: //Déplacement vers la g80auche
          if (goelan->getterX()>0){
            goelan->setterX(goelan->getterX()-1);
            goelan->setterE(goelan->getterE()-1);
          }
          break;
        case 1: //Déplacement vers le haut
          if (goelan->getterY()>0){
            goelan->setterY(goelan->getterY()-1);
            goelan->setterE(goelan->getterE()-1);
          }
          break;
        case 2: //Déplacement vers la droite
          if (goelan->getterX()<getMAX_X()-1){
            goelan->setterX(goelan->getterX()+1);
            goelan->setterE(goelan->getterE()-1);
          }
          break;
        case 3: //Déplacement vers le bas
          if (goelan->getterY()<getMAX_Y()-1){
            goelan->setterY(goelan->getterY()+1);
            goelan->setterE(goelan->getterE()-1);
          }
          break;
    }
    tab[goelan->getterX()][goelan->getterY()]=goelan->getterId();
}

void World::passeuntour(){
  int ax;
  int ay;
  for(unsigned int i=0;i<nb_animaux && i < world.size();i++)
  {
    bouge(world[i]);
    ax=world[i]->getterX();
    ay=world[i]->getterY();
    if (world[i]->getterId() == 'L') //if lion
    {
      for (unsigned int j = 0; j < world.size(); j++)
      {
        if (j == i || world[j]->getterId() == 'L') //continue if it's myself or an other lion
          continue;
        if (world[j]->getterX() == ax && world[j]->getterY() == ay) //if a gazelle is at my pos
        {
          world[i]->setterE(world[i]->getterE() + world[j]->getterE()); //absorb gazelle energy
          world[j]->setterE(0); //eat the gazelle
        }
      }
    }
    if (world[i]->getterE() <= 0){
      tab[world[i]->getterX()][world[i]->getterY()]='X';
      delete world[i]->getImg();
      delete world[i];
      world.erase(world.begin()+i);
      nb_animaux--;
      i--;
    }
  }
}
