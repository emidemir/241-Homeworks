#include "../Headers/Tetris.hpp"

bool convertInt(string ui_input, int &amount){
	unsigned long long int holder = 0;
	if (ui_input[0] == '0')
		return (false);

	for (auto i: ui_input){			// i is iterator which is an object of the string ui_input (20min to realise ">_<" -angry face- )	
		if (i < '0' || i > '9')
			return (false);
		else if (holder > 2147483647)
			return (false);
		holder = (holder*10) + (i-'0');
	}

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

shapes getType(){
	string userInput;

	while (1){
		cout<<"Enter the type of Tetromino : ";
		getline(cin,userInput);

		if (userInput.length() > 1 || (userInput[0] != 'i' && userInput[0] != 'o' && userInput[0] != 't' && userInput[0] != 'j'&&
				userInput[0] != 'l' && userInput[0] != 's' && userInput[0] != 'z' && userInput[0] != 'r' && userInput[0] != 'q')){
			cout<<"You entered a wrong input"<<endl;
			cout<<"\033[2J"; 	/*Clear the concole on wrong answer*/
			userInput = "";
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
					vector<shapes>randomVector = {shapes::I,shapes::J,shapes::L,shapes::O,shapes::S,shapes::T,shapes::Z};
					return (randomVector.at(rand()%7));
				break;
			}
		}
	}
	return (shapes::quit);
}

Tetris::Tetris(int x, int y){
	width = x;
	height = y;
	startIndex = x/2;

	for (int i = 0; i < height; i++){
		board.push_back(vector<shapes>());
	}

	for (int i = 0; i < height; i++){
		for (int k = 1; k < width; k++){
			board[i].push_back(shapes::empty_block);
		}
	}
}

void Tetris::draw(){
	for (int i = 0; i < width; i++)
		cout<<"#";
	
	cout<<endl;
	for (auto i: board){
		cout<<"#";
		for (auto k: i){
			cout<<(char)k;
		}
		cout<<"#"<<endl;
	}

	for (int i = 0; i < width; i++)
		cout<<"#";
}

bool Tetris::add(tetroBoard unit,int xAxis, int yAxis){
	int vertical = unit.size();
	int horizontal = unit[0].size();

	/*If tetromino is abouth to overflow from board, return false*/
	if (xAxis + horizontal >= width)
		return (false);
	if (yAxis + vertical > height)
		return (false);
	/*Add the tetromino to it's place*/
	for(int i = 0; i < vertical; i++){
		for(int k = 0; k < horizontal; k++){
			/*If current position is not empty, this means ı cannot add tetromino to this place, returning false*/
			if (board[i+yAxis][k+xAxis] != shapes::empty_block)
				return (false);
			board[i+yAxis][k+xAxis] = unit[i][k];
		}
	}
	return (true);
}

bool Tetris::fit(tetrimino &unit){

	tetroBoard tempBoard = board;
	int vertical = unit.t_shape.size();
	int horizontal = unit.t_shape[0].size();

	for (int i = height-vertical; i >= 0; i--)	/*Start trying to position new tetromino from height-vertical lenght.Otherwise, 2 row */
	{/*will be checked for nothing and will cause segmentation fault because we will be looking for outside of board*/
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == shapes::empty_block)
			{
				/*If unrotated tetromino fit this place*/
				if (add(unit.t_shape,j,i) == true){
					unit.setHorizontal(j);
					unit.setVertical(i);
					unit.setRotation('u');
					board = tempBoard;
					return (false);
				}
				board = tempBoard;	/*If do not fit, clear the board, rotate and try other rotation*/
				unit.rotate2('r');
				/*If right rotated tetromino fit this place*/
				if (add(unit.t_shape,j,i) == true){
					unit.setHorizontal(j);
					unit.setVertical(i);
					unit.setRotation('r');
					board = tempBoard;
					return (false);
				}
				board = tempBoard;
				unit.rotate2('r');
				unit.rotate2('r');
				/*If left rotated tetromino fit this place*/
				if (add(unit.t_shape,j,i) == true){
					unit.setHorizontal(j);
					unit.setVertical(i);
					unit.setRotation('l');
					board = tempBoard;
					return (false);
				}
				board = tempBoard;
				unit.rotate2('r');
			}
		}
	}
	return (false);
}

bool Tetris::animate(tetrimino tetro){
	tetroBoard tempBoard = board;

	int animateX = startIndex;
	int animateY = 0;

	for (auto i: board[0]){	/*If first line of board is not empty (at least has 1 element) it means game is over*/
		if (i != shapes::empty_block)
			return (true);
	}
	
	add(board, animateX,animateY);	/*Print tetromino at the top first*/

	while (animateX != tetro.getHorizontal() || animateY != tetro.getVertical()){	/*Continue as long as tetromino did not reach destination*/
		add(tetro.t_shape, animateX,animateY);
		if (animateX > tetro.getHorizontal())	/*Moving the tetromino is done with this two if statement*/
			animateX--;
		else if (animateX < tetro.getHorizontal())	
			animateX++;
		if (animateY < tetro.getVertical())
			animateY++;
		draw();	/*After moving, draw the tetromino*/
		board = tempBoard;	/*Clear the board for the next frame of animation*/
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		cout<<"\033[" << height+1<< "A";
	}
	add(tetro.t_shape, animateX,animateY);
	draw();

	return (false);
}