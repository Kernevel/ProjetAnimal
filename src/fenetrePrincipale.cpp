#include <QTimer>
#include "fenetrePrincipale.hpp"
#define NB_ANIMALO 100

MainWindow::MainWindow()
{
  QWidget *widget_general = new QWidget;
  setCentralWidget(widget_general);
  _world = new World(NB_ANIMALO, widget_general);
  _world->peuplement();
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(runTurn()));
  timer->start(100); //time specified in ms  QTimer::singleShot(5, this, SLOT(runTurn()));
}

void MainWindow::runTurn()
{
  _world->passeuntour();
  _world->affiche();
}