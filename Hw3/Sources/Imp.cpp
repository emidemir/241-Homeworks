#include "../Headers/tetris.hpp"

namespace Tetris{

int stringLenght(char *ptr){
	int i = 0;
	while (ptr[i])
		i++;
	return (i);
};

bool convertInt(char* ui_input, int &amount){
	int i = 0;
	bool minus = false;
	unsigned long long int holder = 0;

	if (ui_input[0] == '-')
	{
		minus = true;
		i++;
	}
	
	while (ui_input[i] != '\0'){			// i is iterator which is an object of the string ui_input (20min to realise ">_<" -angry face- )	
		if (ui_input[i] < '0' || ui_input[i] > '9')
			return (false);
		else if (holder > 2147483647)
			return (false);
		holder = (holder*10) + (ui_input[i]-'0');
		i++;
	}

	if (minus == true)
		amount = holder*-1;
	else
		amount = holder;

	return (true);
};

void getAxis(int &x, int &y){

	bool isValid = false;
	int ARRAY_SIZE = 200;
	char* userInput = new char[ARRAY_SIZE];
	int tempX, tempY;

	while (isValid == false){
		cout<<"Enter the size X axis :";
		cin.getline(userInput,ARRAY_SIZE);
		
		if (convertInt(userInput,tempX) == true)
			isValid = true;
		else
			cout<<"You entered a wrong value, try again!!!\n";
	}

	for (int i = 0; i < ARRAY_SIZE; ++i)
		userInput[i] = '\0';
	isValid = false;

	while (isValid == false){

		cout<<"Enter the size Y axis :";
		cin.getline(userInput,ARRAY_SIZE);
		
		if (convertInt(userInput,tempY) == true)
			isValid = true;
		else
			cout<<"You entered a wrong value, try again!!!\n";
	}

	delete [] userInput;
	x = tempX;
	y = tempY;
}

shapes TetroType(){
	int ARRAY_SIZE = 200;
	int currentSize;
	char* userInput = new char[ARRAY_SIZE];
	
	while (1){
		cout<<"Enter the type of Tetromino : ";
		cin.getline(userInput,ARRAY_SIZE);
		currentSize = stringLenght(userInput);

		if ( currentSize > 1 || (userInput[0] != 'i' && userInput[0] != 'o' && userInput[0] != 't' && userInput[0] != 'j'&&
				userInput[0] != 'l' && userInput[0] != 's' && userInput[0] != 'z' && userInput[0] != 'r' && userInput[0] != 'q')){
			cout<<"You entered a wrong input"<<endl;
			// cout<<"\033[2J"; 	/*Clear the concole on wrong answer*/
			userInput[0] = '\0';
		}
		else{
			switch (userInput[0])
			{
			case 'i':
					return(shapes::I);
				break;
			case 'o':
					return(shapes::O);
				break;
			case 't':
					return(shapes::T);
				break;
			case 'j':
					return(shapes::J);
				break;
			case 'l':
					return(shapes::L);
				break;
			case 's':
					return(shapes::S);
				break;
			case 'z':
					return(shapes::Z);
				break;
			case 'q':
					return(shapes::quit);
				break;
			case 'r':
					shapes tempArray[7] = {shapes::I,shapes::J,shapes::L,shapes::O,shapes::S,shapes::T,shapes::Z};
					return (tempArray[rand()%7]);
				break;
			}
		}
	}
	return (shapes::quit);
}

tetris::tetris(){
	xAxis = 10;
	yAxis = 10;

	/*Create the board*/
	Board = new char*[xAxis];
	
	for (int i = 0; i < xAxis; i++){
		Board[i] = new char[yAxis];
		for (int k = 0; k < yAxis; k++)
			Board[i][k] = (char)shapes::empty_block;
	}
}

tetris::tetris(int x, int y){
	xAxis = x;
	yAxis = y;

	/*Create the board*/
	Board = new char*[xAxis];
	
	for (int i = 0; i < xAxis; i++){
		Board[i] = new char[yAxis];
		for (int k = 0; k < yAxis; k++)
			Board[i][k] = (char)shapes::empty_block;
	}
}

tetris::~tetris(){
	for (int i = 0; i < xAxis; i++)
		delete [] Board[i];
	delete [] Board;
	Board = nullptr;
}

void tetris::printBoard()const{
	for (int i = 0; i < xAxis+2; i++)
	cout<<"#";
	
	cout<<endl;

	for (int i = 0; i < xAxis; i++){
		cout<<"#";
		for (int k = 0; k < yAxis; k++)
			cout<<Board[i][k];
		cout<<"#";
		cout<<endl;
	}

	for (int i = 0; i < xAxis+2; i++)
		cout<<"#";
}

tetris& tetris::operator+=(const tetrimino &other){
	int START_INDEX = xAxis/2-1;
	const BOARD_PTR tempBoard = other.getBoard();
	int lenght = other.getLenght();
	int height = other.getHeight();

	for (int i = 0; i < height; i++){
		for (int k = 0; k < lenght; k++){
			if (Board[i][START_INDEX+k] != (char)shapes::empty_block){
				return (*this);
			}
			Board[i][START_INDEX+k] = tempBoard[i][k];
		}
	}
	return (*this);
}

bool tetris::add(const tetrimino &object,int X, int Y){

	/*Get the lenght of the tetromino*/
	int horizontal = object.getLenght();
	int vertical = object.getHeight();

	if (Y + vertical > yAxis)	/*If object is out of boundaries, return false*/
		return (false);

		for (int i = X; i < X+horizontal; i++){	/*If the object is about to overwrite a tetrimino which is already on the board, return false*/
			if (Board[Y+vertical-1][i] != '.')
				return (false);
		}
	

	const BOARD_PTR tempBoard = object.getBoard();	/*Get the tetromino*/

	/*Add the tetromino to it's place*/
	for(int i = 0; i < vertical; i++){
		for(int k = 0; k < horizontal; k++){
			Board[i+Y][k+X] = tempBoard[i][k];
		}
	}
	return (true);
}

bool tetris::animate(const tetrimino &object, int dir, int step){
	
	BOARD_PTR tempBoard = new char*[yAxis];		/*Store first state of board*/
	for (int i = 0; i < yAxis; i++)
		tempBoard[i] = new char[xAxis];

	for (int i = 0; i < yAxis; i++)
		for (int k = 0; k < xAxis; k++)
			tempBoard[i][k] = Board[i][k];

	int horizontal = xAxis/2;	/*Counter for horizontal move*/
	
	for (int i = 0; i < step; i++){			/*_________Horizontal Move_____________*/
		if (add(object,horizontal,0) == false)
			return (false);
		printBoard();
		horizontal += dir;

		
		for (int i = 0; i < yAxis; i++)
			for (int k = 0; k < xAxis; k++)
				Board[i][k] = tempBoard[i][k];
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout<<"\033[" << yAxis+1<< "A";
	}

	int vertical = 0;
	while (add(object,horizontal,vertical++)){	/*_______VERTICAL MOVE________*/
		printBoard();
		for (int i = 0; i < yAxis; i++)
			for (int k = 0; k < xAxis; k++)
				Board[i][k] = tempBoard[i][k];
		
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout<<"\033[" << yAxis+1<< "A";
	}
	add(object,horizontal,vertical-2);	/*-2 explanation: 1 decreased for extra 1 incrementation after function call and 1 for invalid */
	printBoard();						/*Add fucntion which means 1 incremented state of vertical is false so that ı must decrement 1*/

	for (int i = 0; i < yAxis; i++)
		delete [] tempBoard[i];

	return (true);
}

}