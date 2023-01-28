#ifndef TETRIS_ARRAY_1D
#define TETRIS_ARRAY_1D

#include "AbstractClass.hpp"

typedef char* DynamicBoard;

namespace Emirhan{

class TetrisArray1D : public AbstractTetris{

public:
	explicit TetrisArray1D();
	~TetrisArray1D();
	TetrisArray1D(const TetrisArray1D& copyObject);
	TetrisArray1D(int X, int Y);
	void draw()const override;	/*Draws the Board*/
	/*MemoryLeak*/TetrisArray1D* operator+=(const Tetromino& obj);
	bool animate(Tetromino &object, int dir, int step) override;
	void fit() const override;
	Tetromino& lastMove() {return lastTetromino;};	/*Last move function returns a tetromino stored inside a 2D char array*/
	inline int numberOfMoves() const override {return amountOfMoves;};
	bool add(const Tetromino&, int xAxis, int yAxis);	/*Add a tetromino to a certain place at the board*/
	DynamicBoard getBoard(){return Board;};
	inline int getwidth(){return width;};
	inline void setwidth(int a){width = a;};
	inline int getheight(){return height;};
	inline void setheight(int a){height = a;};
	inline int getSize()const{return size;};
	inline void setSize(int a){size = a;};
	friend bool readFromFile(TetrisArray1D&gameObject ,string FileName);

private:
	DynamicBoard Board;
	int width;	/*Width of tetris board*/
	int height;	/*Height of tetris board*/
	int size = width * height;
	Tetromino lastTetromino; /*This is the last added Tetromino*/

};


bool readFromFile(TetrisArray1D&gameObject ,string FileName);
bool writeToFile(TetrisArray1D& gameObject, string FileName);
}

#endif