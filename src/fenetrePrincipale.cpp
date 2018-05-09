#pragma once
#include fenetrePrincipale.hpp
#include World.h

MainWindow::MainWindow():QMainWindow(){
  widget_general = new QWidget;
  QHBoxLayout * qbl_general = new QHBoxLayout;
  widget_general->setLayout(qbl_general);
  widget_general->setFixedWidth(getMAX_X()*24);
  widget_general->setFixedHeight(getMAX_Y()*24);
  this->setCentralWidget(widget_general);
  //exemple de creation d'une zone ou mettre boutons...
  // exemple de création d'un menu
  MyScene * myscene = new MyScene(this);
  myscene->setBackgroundBrush(Qt::green);
  QGraphicsView * myview = new QGraphicsView(myscene,this);
  qbl_general->addWidget(myview);
  menuFichier = menuBar()->addMenu(tr("&Fichier"));
}

MainWindow::~MainWindow(){

}
