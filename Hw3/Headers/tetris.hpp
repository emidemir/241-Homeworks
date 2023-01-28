#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include "../Headers/tetromino.hpp"
using namespace std;

typedef char** BOARD_PTR;


namespace Tetris{

class tetris{
	public:
		tetris();
		tetris(int x, int y);
		~tetris();
		void printBoard()const;
		tetris& operator+=(const tetrimino &other);
		bool animate(const tetrimino &object, int dir, int step);

	private:
		bool add(const tetrimino &object, int xAxis, int yAxis);
		BOARD_PTR Board;
		int xAxis;
		int yAxis;
};

void getAxis(int &X, int &Y);	/*Get Axis of board*/
shapes TetroType();				/*Get Type of tetromino*/
bool convertInt(char* ui_input, int &amount);
}