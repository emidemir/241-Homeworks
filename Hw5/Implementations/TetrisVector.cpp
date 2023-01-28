#include "../Headers/TetrisVector.hpp"

Emirhan::TetrisVector::TetrisVector(){
	width = 10;
	height = 10;
	amountOfMoves = 0;

	for (int i = 0; i < height; ++i){
		Board.push_back(vector<char>());
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j){
			Board[i].push_back('.');
		}
	}
}

Emirhan::TetrisVector::TetrisVector(TetrisVector& copyObject){
	height = copyObject.height;
	width = copyObject.width;
	Board = copyObject.Board;
	lastTetromino = copyObject.lastTetromino;
	amountOfMoves = copyObject.amountOfMoves;
}

Emirhan::TetrisVector::TetrisVector(int X, int Y): width(X), height(Y){
	for (int i = 0; i < height; ++i){
		Board.push_back(vector<char>());
	}

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j){
			Board[i].push_back('.');
		}
	}

	Tetromino silBunu(shapes::J);
	lastTetromino = silBunu;

	amountOfMoves = 0;
}

bool Emirhan::readFromFile(TetrisVector& gameObject,string FileName){ 

	ifstream Record(FileName);

	if (!Record){
		cout << "Could not open the file : " << FileName << endl;
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

	/*This part is for this case. The file may contain more line than my gameObject. In that case, compiler will throw segmentation 
	fault. In order to prevent that , I am creating a new temp and opening enough space for new board, afterwards I will copy this
	new board to my currentBoard*/
	GameBoard temp;

	for (int i = 0; i < gameObject.height; ++i)	
		temp.push_back(vector<char>());
	
	gameObject.Board = temp;

	for (int i = 0; i < gameObject.height; ++i){
		getline(Record,cursor);
		for (int j = 0; j < gameObject.width; ++j){
			gameObject.Board[i].push_back(cursor[j]);
		}
	}

	/*Getting last move from file*/
	getline(Record, cursor);

	Tetromino tempTetromino((shapes)cursor.back());

	gameObject.lastTetromino = tempTetromino;

	Record.close();
	return (true);
}

bool Emirhan::writeToFile(TetrisVector& gameObject, string FileName){
	
	ofstream Record(FileName);

	GameBoard temp = gameObject.getBoard();

	Record << "Number of moves : " << gameObject.numberOfMoves() << endl;
	Record << "Width : " << gameObject.getwidth() << endl;
	Record << "Height : " << gameObject.getheight() << endl;
	
	for (auto i: temp){
		for (auto j: i)
			Record << j;
		Record << endl;
	}

	if (gameObject.lastMove().getHeight() == 0 && gameObject.lastMove().getLenght() == 0)
		Record << "Lates moved Tetromino Type is : " << endl;
	else
		Record << "Lates moved Tetromino Type is : " << (char)gameObject.lastMove().getType() << endl;

	
	Record.close();	/*Closing File*/
	return (true);
}

void Emirhan::TetrisVector::draw() const{
	for (int i = 0; i < width+2; i++)
		cout<<"#";
	
	cout<<endl;

	for (auto i: Board){
		cout<<"#";
		for (auto k: i){
			cout<<k;
		}
		cout<<"#"<<endl;
	}

	for (int i = 0; i < width+2; i++)
		cout<<"#";
	cout << endl;
}

bool Emirhan::TetrisVector::add(const Tetromino& object,int xAxis, int yAxis){

	int vertical = object.getHeight();
	int horizontal = object.getLenght();

	/*If tetromino is abouth to overflow from board, return false*/
	if (xAxis + horizontal > width || width < 0)
		return (false);
	if (yAxis + vertical > height || yAxis < 0)
		return (false);
	
	TETRO_PTR tempTetroBoard = object.getBoard();
	
	/*Add the tetromino to it's place*/
	for(int i = 0; i < vertical; i++){
		for(int k = 0; k < horizontal; k++){
			/*If current position is not empty, this means ı cannot add tetromino to this place, returning false*/
			if (Board[i+yAxis][k+xAxis] != (char)shapes::empty_block)
				return (false);
			Board[i+yAxis][k+xAxis] = tempTetroBoard[i][k];
		}
	}

	return (true);
}

bool Emirhan::TetrisVector::animate(Tetromino &object, int dir, int step){
	
	GameBoard temp = Board;		/*Store first state of board. We will use this to clear the Board*/

	int horizontal = width/2;	/*As we move the tetromino, this value will increase or decrease by 1 at every animation frame*/
	
	/*_________Horizontal Move_____________*/

	for (int i = 0; i < step; i++){
		horizontal += dir;
		
		/*Move 1 block in the direction. If add returns false, clear the board and stop because can not add more.*/
		if (add(object,horizontal,0) == false)
		{
			Board = temp;
			return (false);
		}
		/*If add returns true, go on*/
		draw();

		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout<<"\033[" << height + 2 << "A";
		
		Board = temp;	/*Clean out Board because on the next animation frame, I need clean Board to add on.*/
	}

	/*_______VERTICAL MOVE________*/

	int vertical = 0;			/*As we move down, */

	while (add(object,horizontal,vertical)){	
		
		draw();
				
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout<<"\033[" << height + 2<< "A";
		Board = temp;
		vertical++;
	}
	Board = temp;	
	add(object,horizontal,vertical-1);/*-2 explanation: 1 decreased for extra 1 incrementation after function call and 1 for invalid */
	draw();						/*Add fucntion which means 1 incremented state of vertical is false so that ı must decrement 1*/
	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	cout<<"\033[" << height+2<< "A";

	amountOfMoves++;	/*If animation is successfully done, another moves is done*/
	lastTetromino = object;
	return (true);
}

Emirhan::TetrisVector* Emirhan::TetrisVector::operator+=(const Tetromino& obj){

	int START_INDEX = width/2-1;
	TETRO_PTR tempBoard = obj.getBoard();
	int lenght = obj.getLenght();
	int height = obj.getHeight();

	for (int i = 0; i < height; ++i){
		for (int k = 0; k < lenght; ++k){
			Board[i][START_INDEX+k] = tempBoard[i][k];
			cout << Board[i][START_INDEX+k];
		}
	}
	return (this);
}

void Emirhan::TetrisVector::fit() const{
	cout << "No fit function is defined :)" << endl;
}