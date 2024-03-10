#include <Atributes.h>
#include <iostream>

int* plr::Atributes::getAtributes()
{
    return this->atributesLevels;
}

int plr::Atributes::getAtributes(int selector)
{
    try {
        if (selector > 4) {
            throw ("Invalid Selector");
        }
        return this->atributesLevels[selector];
    }
    catch (std::string err) {
        std::cerr << err << std::endl;
    }
}

char* plr::Atributes::getAtributesTypes(int selector)
{
    try {
        if (selector>4) {
            throw ("Invalid Selector");
        }
        else
            return this->atributesTypes[selector];
    }
    catch (std::string err) {
        std::cerr << err << std::endl;
    }
}

void plr::Atributes::setAtributes(Enum::EAtributesTypes selector, int value)
{
    try {
        if (selector > 4) {
            throw ("Invalid Selector");
        }else if(value>3 || value < 1)
            throw ("Invalid value given, should be between 1 and 3");
        else
            this->atributesLevels[selector] = value;
    }
    catch (std::string err) {
        std::cerr << err << std::endl;
    }
}