#pragma once

#include <iostream>
#include <vector>
#include <QPixmap>
#include <QGraphicsScene>
#include "Animal.h"
#include "Lion.h"
#include "Gazelle.h"
using namespace std;

  class World: public QGraphicsScene
  {
    private:
      static int const MAX_X=50;
      static int const MAX_Y=50;
      unsigned int nb_animaux;
      char tab[MAX_X][MAX_Y];
      vector <Animal*> world;
      QPixmap _lion;
      QPixmap _gazelle;
      QPixmap _sol;
    public:
      World();
      World(int tot, QObject *parent);
      int getMAX_X();
      int getMAX_Y();
      int getAnim();
      void peuplement();
      void affiche();
      void passeuntour();
      void bouge(Animal *goelan);
  };
