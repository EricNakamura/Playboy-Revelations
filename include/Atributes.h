#pragma once

namespace plr {
	class Atributes {
	private:
		int atributesLevels[5] = {1,1,1,1,1};
	public:
		int* getAtributes();
		int getAtributes(int selector);
	};
}