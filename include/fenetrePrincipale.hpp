#pragma once

#include <QMainWindow>
#include "World.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

public slots:
    void runTurn();
private:
    World *_world;
};