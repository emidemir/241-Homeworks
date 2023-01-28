void tetrimino::rotateRight90(){

	int newLenght = height;	/*Height and lenght variables are gonna change if we rotate tetromino*/
	int newHeight = lenght;

	/*Create new array for rotated tetromino*/
	BOARD_PTR rotatedTetro = new char*[newLenght];

	for (int i = 0; i < lenght; i++)
		rotatedTetro[i] = new char[newHeight];

	int x = 0;	/*This is a counter for index of rotatedTetro*/ 
	for (int i = 0; i <lenght ; i++){	/*This is an algorithm which depends on the fact that data is stored as line on memory.*/
		for (int k = height-1; k >= 0; k--){
			rotatedTetro[i][x] = TetroArr[k][i];
			x++;
		}
		x = 0;
	}

	for (int i = 0; i < lenght; i++){	/*Freeying the old array*/
		delete [] TetroArr[i];
	}
	delete [] TetroArr;
	TetroArr = rotatedTetro;	/*Assign new array pointer onto new one*/

	lenght = newLenght;	/*Change old lenght and height variable*/
	height = newHeight;
}

tetrimino::tetrimino(shapes type){
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
	}
}

void tetrimino::create_I(){

	TetroArr = new char*[4];

	for (int i = 0; i < 4; i++){
		TetroArr[i] = new char[1];
		TetroArr[i][0] = (char)shapes::I;
	}
	lenght = 1;
	height = 4;
}

void tetrimino::create_O(){
	TetroArr = new char*[2];
	
	for (int i = 0; i < 2; i++){
		TetroArr[i] = new char[2];
		TetroArr[i][0] = (char)shapes::O;
		TetroArr[i][1] = (char)shapes::O;
	}
	lenght = 2;
	height = 2;
}

void tetrimino::create_T(){
	TetroArr = new char*[3];
	
	for (int i = 0; i < 3; i++)
		TetroArr[i] = new char[3];
	TetroArr[0][0] = (char)shapes::T;
	TetroArr[0][1] = (char)shapes::T;
	TetroArr[0][2] = (char)shapes::T;
	TetroArr[1][0] = (char)shapes::empty_block;
	TetroArr[1][1] = (char)shapes::T;
	TetroArr[1][2] = (char)shapes::empty_block;
	TetroArr[2][0] = (char)shapes::empty_block;
	TetroArr[2][1] = (char)shapes::T;
	TetroArr[2][2] = (char)shapes::empty_block;

	lenght = 3;
	height = 3;
}

void tetrimino::create_J(){
	
	TetroArr = new char*[3];

	for (int i = 0; i < 3; i++)
		TetroArr[i] = new char[2];
	TetroArr[0][0] = (char)shapes::J;
	TetroArr[0][1] = (char)shapes::empty_block;
	TetroArr[1][0] = (char)shapes::J;
	TetroArr[1][1] = (char)shapes::empty_block;
	TetroArr[2][0] = (char)shapes::J;
	TetroArr[2][1] = (char)shapes::J;
	
	lenght = 2;
	height = 3;
}

void tetrimino::create_L(){
	TetroArr = new char*[3];

	for (int i = 0; i < 3; i++)
		TetroArr[i] = new char[2];
	TetroArr[0][0] = (char)shapes::L;
	TetroArr[0][1] = (char)shapes::empty_block;
	TetroArr[1][0] = (char)shapes::L;
	TetroArr[1][1] = (char)shapes::empty_block;
	TetroArr[2][0] = (char)shapes::L;
	TetroArr[2][1] = (char)shapes::L;

	lenght = 2;
	height = 3;
}

void tetrimino::create_S(){
	TetroArr = new char*[2];

	for (int i = 0; i < 2; i++)
		TetroArr[i] = new char[3];
	TetroArr[0][0] = (char)shapes::empty_block;
	TetroArr[0][1] = (char)shapes::S;
	TetroArr[0][2] = (char)shapes::S;
	TetroArr[1][0] = (char)shapes::S;
	TetroArr[1][1] = (char)shapes::S;
	TetroArr[1][2] = (char)shapes::empty_block;

	lenght = 3;
	height = 2;
}

void tetrimino::create_Z(){
	TetroArr = new char*[2];

	for (int i = 0; i < 2; i++)
		TetroArr[i] = new char[3];
	TetroArr[0][0] = (char)shapes::empty_block;
	TetroArr[0][1] = (char)shapes::Z;
	TetroArr[0][2] = (char)shapes::Z;
	TetroArr[1][0] = (char)shapes::Z;
	TetroArr[1][1] = (char)shapes::Z;
	TetroArr[1][2] = (char)shapes::empty_block;

	lenght = 3;
	height = 2;
}

tetrimino::~tetrimino(){
	for (int i = 0; i < lenght; i++){
		delete [] TetroArr[i];
	}
}