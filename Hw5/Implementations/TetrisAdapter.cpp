#include "../Headers/TetrisAdapter.hpp"

namespace Emirhan{

template <class T>
TetrisAdapter<T>::TetrisAdapter(){
	width = 10;
	height = 10;
	size = width * height;
	amountOfMoves = 0;

	for (int i = 0; i < size; ++i)
		Board.push_back('.');
}

template <class T>
TetrisAdapter<T>::TetrisAdapter(int X, int Y){
	width = X;
	height = Y;
	size = width*height;
	amountOfMoves = 0;
	
	for (int i = 0; i <= size; ++i)
		Board.push_back('.');
}

template <class T>
TetrisAdapter<T>::TetrisAdapter(const TetrisAdapter& copyObject){
	
	size = copyObject.size;
	width = copyObject.width;
	height = copyObject.height;
	amountOfMoves = copyObject.numberOfMoves();
	lastTetromino = copyObject.lastTetromino;

	for (int i = 0; i < copyObject.size; ++i)
		Board.push_back(copyObject.Board[i]);
}

template <class T>
void TetrisAdapter<T>::draw()const{
	for (int i = 0; i < width + 2; ++i)
	cout << '#';
	cout << endl;

	for (int i = 0; i < height; ++i){
		
		cout << '#';

		for (int j = 0; j < width; ++j){
			cout << Board[i*width + j];
		}
		cout << '#' << endl;
	}

	for (int i = 0; i < width + 2; ++i)
		cout << '#';
	cout << endl;
}

template <class T>
TetrisAdapter<T>* TetrisAdapter<T>::operator+=(const Tetromino& obj){
	int START_INDEX = width/2-1;
	
	TETRO_PTR tempBoard = obj.getBoard();
	int lenght = obj.getLenght();
	int height = obj.getHeight();

	for (int i = 0; i < height; ++i){
		for (int j = 0; j < lenght; ++j){
			Board[START_INDEX + j] = tempBoard[i][j];
		}
		START_INDEX += width;
	}

	tempBoard = nullptr;

	return (this);
}

template <class T>
bool TetrisAdapter<T>::animate(Tetromino &object, int dir, int step){
	
	/*Store first state of board. We will use this to clear the Board*/
	T TempBoard;

	TempBoard = Board;

	int horizontal = width/2;	/*As we move the tetromino, this value will increase or decrease by 1 at every animation frame*/
	
	/*_________Horizontal Move_____________*/

	for (int i = 0; i < step; i++){
		
		horizontal += dir;

		/*Move 1 block in the direction. If add returns false, clear the board and stop because can not add more.*/
		if (add(object,horizontal,0) == false)
		{
			Board = TempBoard;

			return (false);
		}
		draw();

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout<<"\033[" << height + 2 << "A";
		
		/*Clean out Board because on the next animation frame, I need clean Board to add on.*/
		Board = TempBoard;
	}

	/*_______VERTICAL MOVE________*/

	int vertical = 0;			/*As we move down, */

	while (add(object,horizontal,vertical)){	

		draw();
		
		Board = TempBoard;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout<<"\033[" << height+2<< "A";
		vertical++;
	}

	Board = TempBoard;

	add(object,horizontal,vertical-1);	/*-2 explanation: 1 decreased for extra 1 incrementation after function call and 1 for invalid */
	draw();						/*Add fucntion which means 1 incremented state of vertical is false so that ı must decrement 1*/
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	cout<<"\033[" << height+2<< "A";

	amountOfMoves++;	/*If animation is successfully done, another moves is done*/
	lastTetromino = object;

	return (true);
}

template <class T>
void TetrisAdapter<T>::fit()const{
	cout << "No fit function implemented :) " << endl;
}

template <class T>
bool TetrisAdapter<T>::add(const Tetromino& object, int xAxis, int yAxis){
	int vertical = object.getHeight();
	int horizontal = object.getLenght();

	/*If tetromino is about to overflow from board, return false*/
	if (xAxis + horizontal - 1 > width)
		return (false);
	if (yAxis + vertical - 1 > height)
		return (false);
	
	TETRO_PTR tempTetroBoard = object.getBoard();
	
	/*Add the tetromino to it's place*/
	for(int i = 0; i < vertical; i++){
		for(int k = 0; k < horizontal; k++){
			/*If current position is not empty, this means ı cannot add tetromino to this place, returning false*/
			if (Board[(yAxis+i)*width + k + xAxis-1] != (char)shapes::empty_block)
				return (false);
			Board[(yAxis+i)*width + k + xAxis-1] = tempTetroBoard[i][k];
		}
	}
	return (true);
}

template <class T>
bool readFromFile(TetrisAdapter<T>&gameObject ,string FileName){
	ifstream Record(FileName);

	if (!Record){
		cout << "There is a problem while reading file : " << FileName << endl;
		return (false);
	}

	string cursor;
	
	for (int i = 0; i < 3;++i){
		getline(Record,cursor);
		if (i == 0){	/*First line of file holds the amountOfMoves variable*/
			gameObject.amountOfMoves = getNumber(cursor);
		}else if (i == 1){	/*Second line holds the width*/
			gameObject.width = getNumber(cursor);
		}else if (i == 2){	/*Third line holds the height*/
			gameObject.height = getNumber(cursor);
		}
	}

	gameObject.size = gameObject.height * gameObject.width;

	/*This part is for this case. The file may contain more line than my gameObject. In that case, compiler will throw segmentation 
	fault. In order to prevent that , I am creating a new temp and opening enough space for new board, afterwards I will copy this
	new board to my currentBoard*/
	T Temp;


	for (int i = 0; i < gameObject.height; ++i){
		getline(Record,cursor);
		for (int j = 0; j < gameObject.width; ++j){
			Temp.push_back(cursor[j]);
		}
	}

	gameObject.Board = Temp;

	/*Getting last move from file*/
	getline(Record, cursor);

	if (cursor.back() != ' ')
	{
		Tetromino tempTetromino((shapes)cursor.back());
		gameObject.lastTetromino = tempTetromino;
	}

	Record.close();

	return (true);
}

template <class T>
bool writeToFile(TetrisAdapter<T>& gameObject, const string FileName){
	ofstream Record(FileName);

	T Temp = gameObject.getBoard();

	Record << "Number of moves : " << gameObject.numberOfMoves() << endl;
	Record << "Width : " << gameObject.getwidth() << endl;
	Record << "Height : " << gameObject.getheight() << endl;
	
	for (int i = 0; i < gameObject.getheight(); ++i){
		
		for (int j = 0; j < gameObject.getwidth(); ++j){
			Record << Temp[i*gameObject.getheight() + j];
		}
		Record << endl;
	}

	if (gameObject.lastMove().getHeight() == 0 && gameObject.lastMove().getLenght() == 0)
		Record << "Lates moved Tetromino Type is : " << endl;
	else
		Record << "Lates moved Tetromino Type is : " << (char)gameObject.lastMove().getType() << endl;

	Record.close();	/*Closing File*/
	return (true);
}

}