#include "World.h"
#include <vector>
#define NB_ANIMALO 100

int main()
{
  srand(time(NULL));
  World the_world(NB_ANIMALO);
  the_world.peuplement();

  while(Animal::getCount()){
    the_world.passeuntour();
    the_world.affiche();
  }
  the_world.passeuntour();
  cout<<"fin\n";
  //vect.pop_back();
  Gazelle Bandyboi;
  Lion thavageboi;
  Bandyboi.affiche();
  thavageboi.affiche();
  return 0;
}
