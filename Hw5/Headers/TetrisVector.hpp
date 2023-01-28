#ifndef TETRIS_VECTOR
#define TETRIS_VECTOR

#include "AbstractClass.hpp"
#include <vector>

namespace Emirhan{

typedef vector<vector<char>> GameBoard;

class TetrisVector: public AbstractTetris{
	public:
	 TetrisVector();
	TetrisVector(TetrisVector& copyObject);
	TetrisVector(int X, int Y);
	void draw()const;	/*Draws the Board*/
	TetrisVector* operator+=(const Tetromino& obj);
	bool animate(Tetromino &object, int dir, int step) override;
	void fit() const override;
	Tetromino& lastMove() {return lastTetromino;};	/*Last move function returns a tetromino stored inside a 2D char array*/
	inline int numberOfMoves() const override {return amountOfMoves;};
	bool add(const Tetromino&, int xAxis, int yAxis);	/*Add a tetromino to a certain place at the board*/
	GameBoard getBoard(){return Board;};
	inline int getwidth(){return width;};
	inline void setwidth(int a){width = a;};
	inline int getheight(){return height;};
	inline void setheight(int a){height = a;};
	friend bool readFromFile(TetrisVector&gameObject ,string FileName);

	
	private:
	GameBoard Board;
	int width;	/*Width of tetris board*/
	int height;	/*Height of tetris board*/
	Tetromino lastTetromino; /*This is the last added Tetromino*/
};

bool readFromFile(TetrisVector&gameObject ,string FileName);
bool writeToFile(TetrisVector& gameObject, string FileName);
}



#endif