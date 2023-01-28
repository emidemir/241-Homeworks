#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>
#include "Tetromino.hpp"

using namespace std;

typedef vector<vector<shapes>> tetroBoard;

class Tetris{
	public:
		Tetris(int x, int y);
		void draw();
		bool animate(tetrimino &unit);
		bool add(tetrimino unit, int xAxis, int yAxis);
		bool fit(tetrimino &unit);

	private:
		tetroBoard board;
		int width;
		int height;
		// int totalIntersection = 1;
		// int searchIndex = height;			/*Start searching for a place to put tetromino from this index*/
};

bool convertInt(string ui_input, int &amount);
void getAxis(int &, int &);
shapes getType();
void hi(int a);