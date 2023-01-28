#ifndef TETRIS_ADAPTER
#define TETRIS_ADAPTER

#include "AbstractClass.hpp"

namespace Emirhan{

template <class T>
class TetrisAdapter : public AbstractTetris{

public:
	explicit TetrisAdapter();
	TetrisAdapter(int X, int Y);
	TetrisAdapter(const TetrisAdapter& copyObject);
	void draw()const override;	/*Draws the Board*/
	/*MemoryLeak*/TetrisAdapter<T>* operator+=(const Tetromino& obj);
	bool animate(Tetromino &object, int dir, int step) override;
	void fit() const override;
	bool add(const Tetromino&, int xAxis, int yAxis);	/*Add a tetromino to a certain place at the board*/
	// ~TetrisAdapter();
	Tetromino& lastMove() {return lastTetromino;};	/*Last move function returns a tetromino stored inside a 2D char array*/
	inline int numberOfMoves() const override {return amountOfMoves;};
	T getBoard(){return Board;};
	inline int getwidth(){return width;};
	inline void setwidth(int a){width = a;};
	inline int getheight(){return height;};
	inline void setheight(int a){height = a;};
	inline int getSize()const{return size;};
	inline void setSize(int a){size = a;};
	template <class Y>
	friend bool readFromFile(TetrisAdapter<Y>&gameObject ,string FileName);

private:
	T Board;
	int width;	/*Width of tetris board*/
	int height;	/*Height of tetris board*/
	int size = width * height;
	Tetromino lastTetromino; /*This is the last added Tetromino*/
};

template <class T>
bool readFromFile(TetrisAdapter<T>&gameObject ,string FileName);
template <class T>
bool writeToFile(TetrisAdapter<T>& gameObject, string FileName);
}

#endif