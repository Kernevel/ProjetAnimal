#pragma once

#include <iostream>
#include <vector>
#include "Animal.h"
#include "Lion.h"
#include "Gazelle.h"
using namespace std;

  class World{
    private:
      static int const MAX_X=50;
      static int const MAX_Y=50;
      unsigned int nb_animaux;
      char tab[MAX_X][MAX_Y];
      vector <Animal*> world;
    public:
      World(int tot);
      int getMAX_X();
      int getMAX_Y();
      int getAnim();
      void peuplement();
      void affiche();
      void passeuntour();
      void bouge(Animal *goelan);
  };
