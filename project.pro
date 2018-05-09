TARGET = main.exe
SOURCES += ./src/Animal.cpp ./src/Gazelle.cpp ./src/Lion.cpp ./src/main.cpp ./src/World.cpp ./src/fenetrePrincipale.cpp
HEADERS += ./include/fenetrePrincipale.hpp ./include/World.h
MOC_DIR += ./src/moc/
QT += widgets
INCLUDEPATH += ./include/