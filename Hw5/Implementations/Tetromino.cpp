#include "../Headers/Tetromino.hpp"

namespace Emirhan{

int getNumber(const string& input){

	bool isNegative = false;
	int holder = 0;

	for (auto i: input){
		if (i == '-'){
			isNegative = true;
		}
		else if (i < '0' || i > '9'){	/*If not number, start over*/
			isNegative = false;
			holder = 0;
		}
		else if (i >= '0' && i <= '9'){	/*If got number, continue incrementing it as it comes*/
			holder = holder*10 + (i-48);
		}
	}

	if (isNegative == true)
		return (-holder);
	return (holder);
}

bool convertInt(string ui_input, int &amount){
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
	string userInput;
	int tempX, tempY;

	
	while (isValid == false){
		cout<<"Enter the size X axis :";
		getline(cin,userInput);
		if (convertInt(userInput,tempX) == true)
			isValid = true;
		else
			cout<<"You entered a wrong value, try again!!!\n";
	}

	isValid = false;

	while (isValid == false){
		cout<<"\nEnter the size Y axis: ";
		getline(cin,userInput);
		if (convertInt(userInput,tempY) == true)
			isValid = true;
		else
			cout<<"You entered a wrong value, try again!!!\n";
	}

	x = tempX;
	y = tempY;
}

shapes getTetroType(){
	
	bool keepAsking = true;
	string userInput;

	cout << "Enter the type of tetromino : ";

	while (keepAsking){
		cin >> userInput;

		if (userInput.size() > 1)
			cout << "Try Again : ";
		else{
			if (userInput[0] == 'I')
				return (shapes::I);
			else if (userInput[0] == 'O')
				return (shapes::O);
			else if (userInput[0] == 'J')
				return (shapes::J);
			else if (userInput[0] == 'L')
				return (shapes::L);
			else if (userInput[0] == 'S')
				return (shapes::S);
			else if (userInput[0] == 'Z')
				return (shapes::Z);
			else if (userInput[0] == 'T')
				return (shapes::T);
			else if (userInput[0] == 'Q')
				return (shapes::quit);
			else if (userInput[0] == 'R')
				return (shapes::R);
			else
				cout << "Try Again : ";
		}
	}
	return (shapes::R);
}

void Tetromino::rotateRight90(){

	int newLenght = height;	/*Height and lenght variables are gonna change if we rotate tetromino*/
	int newHeight = lenght;

	/*Create new array for rotated tetromino*/
	TETRO_PTR rotatedTetro = new char*[newLenght];

	for (int i = 0; i < lenght; i++)
		rotatedTetro[i] = new char[newHeight];

	int x = 0;	/*This is a counter for index of rotatedTetro*/ 
	for (int i = 0; i <lenght ; i++){	/*This is an algorithm which depends on the fact that data is stored as line on memory.*/
		for (int k = height-1; k >= 0; k--){
			rotatedTetro[i][x] = TetrominoBoard[k][i];
			x++;
		}
		x = 0;
	}

	for (int i = 0; i < lenght; i++){	/*Freeying the old array*/
		delete [] TetrominoBoard[i];
	}
	delete [] TetrominoBoard;
	TetrominoBoard = rotatedTetro;	/*Assign new array pointer onto new one*/

	lenght = newLenght;	/*Change old lenght and height variable*/
	height = newHeight;
}

Tetromino::Tetromino(){
	lenght = 0;
	height = 0;
	TetrominoBoard = nullptr;
}

Tetromino::Tetromino(shapes type){
	switch (type)
	{
		case shapes::I:
			create_I();
			break;
	
		case shapes::J:
			create_J();
			break;

		case shapes::L:
			create_L();
			break;

		case shapes::O:
			create_O();
			break;

		case shapes::S:
			create_S();
			break;

		case shapes::T:
			create_T();
			break;

		case shapes::Z:
			create_Z();
			break;
		case shapes::R:
			createRandom();
			break;
		case shapes::empty_block:
			break;
		case shapes::quit:
			break;
	}
}

void Tetromino::operator=(const Tetromino& lhs){

	if (this == &lhs)
		return;

	// for (int i = 0; i < height; ++i)
	// delete [] TetrominoBoard[i];

	shapes type = lhs.getType();
	
	switch (type)
	{
		case shapes::I:
			create_I();
			break;
	
		case shapes::J:
			create_J();
			break;

		case shapes::L:
			create_L();
			break;

		case shapes::O:
			create_O();
			break;

		case shapes::S:
			create_S();
			break;

		case shapes::T:
			create_T();
			break;

		case shapes::Z:
			create_Z();
			break;
		case shapes::R:
			createRandom();
			break;
		case shapes::empty_block:
			break;
		case shapes::quit:
			break;
	}
}

void Tetromino::create_I(){

	TetrominoBoard = new char*[4];
		
	for (int i = 0; i < 4; i++){
		TetrominoBoard[i] = new char[1];
		TetrominoBoard[i][0] = (char)shapes::I;
	}
	lenght = 1;
	height = 4;
	t_type = shapes::I;
}

void Tetromino::create_O(){
	TetrominoBoard = new char*[2];
	
	for (int i = 0; i < 2; i++){
		TetrominoBoard[i] = new char[2];
		TetrominoBoard[i][0] = (char)shapes::O;
		TetrominoBoard[i][1] = (char)shapes::O;
	}
	lenght = 2;
	height = 2;
	t_type = shapes::O;
}

void Tetromino::create_T(){
	TetrominoBoard = new char*[3];
	
	for (int i = 0; i < 3; i++)
		TetrominoBoard[i] = new char[3];
	TetrominoBoard[0][0] = (char)shapes::T;
	TetrominoBoard[0][1] = (char)shapes::T;
	TetrominoBoard[0][2] = (char)shapes::T;
	TetrominoBoard[1][0] = (char)shapes::empty_block;
	TetrominoBoard[1][1] = (char)shapes::T;
	TetrominoBoard[1][2] = (char)shapes::empty_block;
	TetrominoBoard[2][0] = (char)shapes::empty_block;
	TetrominoBoard[2][1] = (char)shapes::T;
	TetrominoBoard[2][2] = (char)shapes::empty_block;

	lenght = 3;
	height = 3;
	t_type = shapes::T;
}

void Tetromino::create_J(){
	
	TetrominoBoard = new char*[3];

	for (int i = 0; i < 3; i++)
		TetrominoBoard[i] = new char[2];
	TetrominoBoard[0][0] = (char)shapes::J;
	TetrominoBoard[0][1] = (char)shapes::empty_block;
	TetrominoBoard[1][0] = (char)shapes::J;
	TetrominoBoard[1][1] = (char)shapes::empty_block;
	TetrominoBoard[2][0] = (char)shapes::J;
	TetrominoBoard[2][1] = (char)shapes::J;
	
	lenght = 2;
	height = 3;
	t_type = shapes::J;
}

void Tetromino::create_L(){
	TetrominoBoard = new char*[3];

	for (int i = 0; i < 3; i++)
		TetrominoBoard[i] = new char[2];
	TetrominoBoard[0][0] = (char)shapes::L;
	TetrominoBoard[0][1] = (char)shapes::empty_block;
	TetrominoBoard[1][0] = (char)shapes::L;
	TetrominoBoard[1][1] = (char)shapes::empty_block;
	TetrominoBoard[2][0] = (char)shapes::L;
	TetrominoBoard[2][1] = (char)shapes::L;

	lenght = 2;
	height = 3;
	t_type = shapes::L;
}

void Tetromino::create_S(){
	TetrominoBoard = new char*[2];

	for (int i = 0; i < 2; i++)
		TetrominoBoard[i] = new char[3];
	TetrominoBoard[0][0] = (char)shapes::empty_block;
	TetrominoBoard[0][1] = (char)shapes::S;
	TetrominoBoard[0][2] = (char)shapes::S;
	TetrominoBoard[1][0] = (char)shapes::S;
	TetrominoBoard[1][1] = (char)shapes::S;
	TetrominoBoard[1][2] = (char)shapes::empty_block;

	lenght = 3;
	height = 2;
	t_type = shapes::S;
}

void Tetromino::create_Z(){
	TetrominoBoard = new char*[2];

	for (int i = 0; i < 2; i++)
		TetrominoBoard[i] = new char[3];
	TetrominoBoard[0][0] = (char)shapes::empty_block;
	TetrominoBoard[0][1] = (char)shapes::Z;
	TetrominoBoard[0][2] = (char)shapes::Z;
	TetrominoBoard[1][0] = (char)shapes::Z;
	TetrominoBoard[1][1] = (char)shapes::Z;
	TetrominoBoard[1][2] = (char)shapes::empty_block;

	lenght = 3;
	height = 2;
	t_type = shapes::Z;
}

void Tetromino::createRandom(){
	int vRand = rand() % 7 + 1;	/*Get a rand value*/

	if (vRand == 1){
		create_I();
	}else if (vRand == 2){
		create_J();
	}else if (vRand == 3){
		create_L();
	}else if (vRand == 4){
		create_O();
	}else if (vRand == 5){
		create_S();
	}else if (vRand == 6){
		create_T();
	}else if (vRand == 7){
		create_Z();
	}
}

Tetromino::~Tetromino(){
	for (int i = 0; i < height; ++i){
		delete [] TetrominoBoard[i];
	}
}

}