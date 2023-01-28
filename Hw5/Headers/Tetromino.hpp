#ifndef TETROMINO
#define TETROMINO

#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;

typedef char** TETRO_PTR;

namespace Emirhan{

enum class shapes{I='I',O='O',T='T',J='J',L='L',S='S',Z='Z', empty_block = '.', R = 'R', quit = 'Q'};

class Tetromino{
	public:
		Tetromino();
		Tetromino(shapes type);
		void rotateRight90();
		~Tetromino();
		shapes inline getType()const{return t_type;};
		int getLenght()const{return lenght;};
		int getHeight()const{return height;};
		TETRO_PTR  getBoard()const{return TetrominoBoard;};
		void  setBoardNull(){TetrominoBoard = nullptr;};
		void operator=(const Tetromino& lhs);
	private:
		void create_I();
		void create_O();
		void create_T();
		void create_J();
		void create_L();
		void create_S();
		void create_Z();
		void createRandom();
		int lenght;
		int height;
		shapes t_type;
		TETRO_PTR TetrominoBoard;
};

bool convertInt(string ui_input, int &amount);
void getAxis(int &x, int &y);
int getNumber(const string& input);
shapes getTetroType();

}

#endif