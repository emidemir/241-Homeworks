#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Tetromino.hpp"
#include <chrono>
#include <thread>

using namespace std;

typedef vector<vector<shapes>> tetroBoard;

class Tetris{
	public:
		Tetris(int x, int y);
		void draw();
		bool animate(tetrimino tetro);
		bool add(tetroBoard unit, int xAxis, int yAxis);
		bool fit(tetrimino &unit);

	private:
		tetroBoard board;
		int width;
		int height;
		int startIndex;
};

bool convertInt(string ui_input, int &amount);
void getAxis(int &, int &);
shapes getType();
void hi(int a);