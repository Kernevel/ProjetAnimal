#include <QTimer>
#include <QGraphicsView>
#include <QHBoxLayout>
#include "fenetrePrincipale.hpp"
#define NB_ANIMALO 100

MainWindow::MainWindow()
{
  QWidget *widget_general = new QWidget;
  QHBoxLayout *layout = new QHBoxLayout();
  _world = new World(NB_ANIMALO, widget_general);
  _world->peuplement();
  widget_general->setLayout(layout);
  widget_general->setFixedWidth(_world->getMAX_X() * 24);
  widget_general->setFixedHeight(_world->getMAX_Y() * 24);
  setCentralWidget(widget_general);
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(runTurn()));
  timer->start(100); //time specified in ms  QTimer::singleShot(5, this, SLOT(runTurn()));
  QGraphicsView *myview = new QGraphicsView(_world, this);
  layout->addWidget(myview);
}

void MainWindow::runTurn()
{
  _world->passeuntour();
  _world->affiche();
}