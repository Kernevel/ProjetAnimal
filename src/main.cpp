#include <vector>
#include "World.h"
#include <QApplication>
#include "fenetrePrincipale.hpp"

int main(int ac, char **av)
{
  // if (ac == 1)
  // {
  //   std::cerr << "Usage : " <<  av[0] << " map_width map_height" << std::endl;
  //   return (EXIT_FAILURE);
  // }
  QApplication app(ac, av);
  srand(time(NULL));

  MainWindow mainwindow;
  mainwindow.show();
  return app.exec();
}
