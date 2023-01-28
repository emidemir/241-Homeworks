#pragma once
#include <iostream>

typedef char** BOARD_PTR;
using namespace std;

namespace Tetris{

enum class shapes{I='I',O='O',T='T',J='J',L='L',S='S',Z='Z', empty_block = '.', repeat = 'R', quit = 'Q'};

class tetrimino{
	public:
		tetrimino(shapes type);
		void rotateRight90();
		~tetrimino();
		shapes inline getType()const{return t_type;};
		int getLenght()const{return lenght;};
		int getHeight()const{return height;};
		const BOARD_PTR getBoard()const{return TetroArr;};

	private:
		BOARD_PTR TetroArr;
		void create_I();
		void create_O();
		void create_T();
		void create_J();
		void create_L();
		void create_S();
		void create_Z();
		int lenght;
		int height;
		shapes t_type;
};

}