#pragma once

#include <iostream>
#include <string>
#include <QLabel>

using namespace std;

  class Animal{
    public :
      Animal();
      Animal(int xinit, int yinit,int einit);
      ~Animal();
      int getterX() const;
      int getterY() const;
      int getterE() const;
      void setterL(char l);
      void setterX(int xinit);
      void setterY(int yinit);
      void setterE(int einit);
      void affiche();
      static int getCount();
      virtual char getterId() const;
    protected :
      int x,y,energie;
      char lettre;
      std::string nom;
      static int nb_animaux;
      // QLabel label;
};