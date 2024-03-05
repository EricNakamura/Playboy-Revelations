#include "Atributes.h"

int* plr::Atributes::getAtributes()
{
    return this->atributesLevels;
}

int plr::Atributes::getAtributes(int selector)
{
    return this->atributesLevels[selector];
}
