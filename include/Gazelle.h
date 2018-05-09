#pragma once

#include "Animal.h"


class  Gazelle : public Animal
{
    public:
        Gazelle();
        void affiche();
        char getterId() const;
};