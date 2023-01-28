#ifndef ABSTRACT_CLASS
#define ABSTRACT_CLASS

#include "Tetromino.hpp"

namespace Emirhan{

	class AbstractTetris{
		public:
			virtual void draw()const = 0;
			virtual AbstractTetris* operator+=(const Tetromino& obj) = 0;	/*Depends on type*/
			virtual bool animate(Tetromino &object, int dir, int step) = 0;
			virtual void fit() const = 0;
			virtual Tetromino& lastMove() = 0;
			virtual int numberOfMoves() const = 0;
		protected:
			int amountOfMoves;
	};
}

#endif