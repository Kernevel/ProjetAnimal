#include <vector>
#include "World.h"
#include <QApplication>
#include "fenetrePrincipale.hpp"

int main(int ac, char **av)
{
  QApplication app(ac, av);
  srand(time(NULL));

  MainWindow mainwindow;
  mainwindow.show();
  return app.exec();
}
