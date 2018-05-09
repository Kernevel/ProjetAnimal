#include <iostream>
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
      static int nb_animaux;
  };

  class  Gazelle : public Animal{
    public :
    void affiche();
    char getterId() const;
    private :
    char nom[50]="Gazelle";
  };

  class  Lion : public Animal{
    public :
    void affiche();
    char getterId() const;
    private :
    char nom[50]="Lion";
  };
