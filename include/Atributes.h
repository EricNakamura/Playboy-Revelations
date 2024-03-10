#pragma once
#include <string>
#include <Enums.h>

namespace plr {
	class Atributes {
	private:
		
		int atributesLevels[5] = {1,1,1,1,1};
		char* atributesTypes[5] = {"Camisa","Sapato","Cord�o","Cal�a","Arma"};
	public:
		int* getAtributes();
		int getAtributes(int selector);
		char* getAtributesTypes(int selector);

		void setAtributes(Enum::EAtributesTypes selector, int value);
	};
}