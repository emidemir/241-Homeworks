// #include "../Headers/Tetris.hpp"
#include "../Headers/Tetromino.hpp"

using namespace std;

/*_______________SHAPE OF I______________*/
vector<vector<shapes>>I_U = {
	{shapes::I},
	{shapes::I},
	{shapes::I},
	{shapes::I}
};

/*_______________SHAPE OF O_______________*/
vector<vector<shapes>>O_U = {	//	shapes I of Up
	{shapes::O,shapes::O},
	{shapes::O,shapes::O}
};

/*_____________SHAPE OF T_________________*/
vector<vector<shapes>>T_U {
	{shapes::T,shapes::T,shapes::T},
	{shapes::empty_block,shapes::T,shapes::empty_block}
};

/*_____________SHAPE OF j_________________*/
vector<vector<shapes>>J_U{
	{shapes::empty_block,shapes::J},
	{shapes::empty_block,shapes::J},
	{shapes::J,shapes::J}
};

/*_____________SHAPE OF L_________________*/
vector<vector<shapes>>L_U{
	{shapes::L,shapes::empty_block},
	{shapes::L,shapes::empty_block},
	{shapes::L,shapes::L}
};

/*_____________SHAPE OF S_________________*/
vector<vector<shapes>>S_U{
	{shapes::empty_block,shapes::S,shapes::S},
	{shapes::S,shapes::S,shapes::empty_block},
};

/*_____________SHAPE OF Z_________________*/
vector<vector<shapes>>Z_U{
	{shapes::Z,shapes::Z,shapes::empty_block},
	{shapes::empty_block,shapes::Z,shapes::Z},
};

vector<vector<shapes>> tetrimino::area = vector<vector<shapes>>();	//	Static object need to be decleared in implementation file.

bool convertInt(string ui_input, int *amount){
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

	*amount = holder;
	return (true);
};

int minValue(vector<int>vec){
	int a = vec[0];
	for (auto i:vec){
		if (i < a)
			a = i;
	}
	return (a);
}

int absoluteValue(int a){
	if (a <= 0)
		return (-a);
	return (a);
};

tetrimino::tetrimino(shapes type){	//	Object Creation

	switch (type)
	{
	case shapes::I:
		t_shape = I_U;
		break;
	case shapes::O:
		t_shape = O_U;
		break;
	case shapes::T:
		t_shape = T_U;
		break;
	case shapes::J:
		t_shape = J_U;
		break;
	case shapes::L:
		t_shape = L_U;
		break;
	case shapes::S:
		t_shape = S_U;
		break;
	case shapes::Z:
		t_shape = Z_U;
		break;
	}
	horizontal = t_shape[0].size();
	vertical = t_shape.size();
};

void tetrimino::print() const
{
	for (auto i: t_shape)
	{
		for (auto k: i)
		{
			cout<<(char)k;
		}
		cout<<endl;
	}
	cout<<endl;
};

void printVectors(vector<vector<shapes>>v1)
{
	for (auto i: v1)
	{
		for (auto k: i)
		{
			cout<<(char)k;
		}
		cout<<endl;
	}
	cout<<endl;
};

void tetrimino::rotate2(char dir){

	vector<vector<shapes>>rValue;
	int innerSize = t_shape.size()-1;
	int outSize = t_shape.at(0).size()-1;

	for (int i = 0; i <= outSize; i++){
		rValue.push_back(vector<shapes>());
	}

	for (int i = 0; i <= outSize; i++){
		for (int k = 0; k <= innerSize; k++)
			rValue[i].push_back(shapes::empty_block);
	}

	for (int i = 0; i <= outSize; i++)
	{
		int l = 0;
		for (int j = innerSize; j >=0; j--)
		{
			rValue[i][l] = t_shape[j][i];
			l++;
		}
	}
	t_shape = rValue;
}

int tetrimino::tetAmount(shapes type,vector<vector<shapes>>board){
	int amount = 0;

	for (auto i : board){
		for (auto k: i){
			if (k == type)
				amount++;
		}
	}
	return (amount);
}

vector<vector<shapes>> tetrimino::mergeVectors(vector<vector<shapes>>v1,vector<vector<shapes>>v2)const{
	vector<vector<shapes>> tempVector;

	int biggerNumber;
	int col1 = v1[0].size();
	int col2 = v2[0].size();
	biggerNumber = (col1 >= col2 ? col1 : col2);

	for (int i = 0; i < 3; i++)
	{
		tempVector.push_back(vector<shapes>());
	}

	for (int i = 0; i < 3; i++){
		for (int k = 0; k < col1; k++){
			tempVector[i].push_back(v1[i][k]);
		}
	}

	for (int i = 0; i < 3; i++){
		for (int k = 0; k < col2; k++){
			tempVector[i].push_back(v2[i][k]);
		}
	}

	// printVectors(tempVector);

	return (tempVector);
};

bool tetrimino::canFit(tetrimino &object2, char direction){
	
	vector<vector<shapes>>tempBoard;	//	Holder of two merged vector
	tetrimino tmpObject = object2;		//	If I rotate my original, Original position will be lost forever and it will impossible to solve. I spent 1 hour to find this bug
	tmpObject.rotate2(direction);		//	Rotating another object by the char direction parameter

	/*Mergin 2 vectors*/
	tempBoard = mergeVectors(t_shape,tmpObject.t_shape);

	// printVectors(tempBoard);	You can see it combined two vector

	/*Move the tetrimino on the right to the left in order to fit it without any holes. If impossible, return false; else return true*/
	if (moveBoard(tempBoard,object2,direction) == false)
		return (false);
	return (true);
}

bool tetrimino::moveBoard(vector<vector<shapes>>tempBoard, tetrimino &object2, char direction){
	
	int amount1 = tetAmount(t_type,tempBoard);
	int amount2 = object2.tetAmount(object2.t_type,tempBoard);

	for (int i = 0; i < 3; i++){
		for (int k = 3; k < 6; k++){
			/*	Moving tetrominos 1 unit left to see if it will fit*/
			if (tempBoard[i][k] == object2.t_type)
			{
				tempBoard[i][k-1] = object2.t_type;
				tempBoard[i][k] = shapes::empty_block;
			}
		}
	}

	/*Check that if any tetrimino from right is occupying left tetrimino's places.*/
	/*Validation will be done over amount of tetrominos on the board*/
	/*If there are less tetromine than amount1 or amount2, it means that there is one overlaping another*/
	if (tetAmount(t_type,tempBoard) + tetAmount(object2.getType(),tempBoard) != amount1 + amount2)
		return (false);
	

	int width = 0;		// Intersection point of two tangent tetromino for example O and 180deg rotated L has 2 point. Normal L and normal O has 2 point too.
	int height = 0;		// For example, OL merged vector has height of 3 because L is taller and has 3 shapes::L on top eachother

	/*Setting width, height and directions of object2.*/
	for (int i = 0; i < 3; i++){
		if (tempBoard[i][2] == t_type && tempBoard[i][3] == object2.t_type)
			width++;
	};

	for (auto i : tempBoard){
		for (auto k : i){
			if (k != shapes::empty_block)
			{
				height++;
				break;
			}
		}
	};

	/*If new width and height which is found just now is better than previous one, eliminate previous one and get present position*/
	if (width >= object2.getWidth() && height <= object2.getHeight())
	{
		object2.setWidth(width);
		object2.setHeight(height);
		object2.setDir(direction);
	}
	else{
		return (false);
	}
	return (true);
};

int mergeWithArea(tetrimino obj2, shapes type1, int index){

	int row = 0;
	vector<int>how_Much_To_Move_Left(3,0);	//	I got bored, don't think about the stupid name pls.
	/* Trying to find how much space do I need to delete between two tetromino on overall vector*/
	/* for example If I have
		. . . . L .
		. o o . L .
		. o o . L L
		vector's indexes will be like (4,1,1) -line 290 print statement are written in order to control that numbers-
		and in that (4,1,1) 1 is the lowest number so that I will delete 1 empty_block element between two tetromino 
	*/
	int index2 = 0;
	int index1 = 0;

	for (int i = 0; i < 3; i++)
	{
		row = obj2.area[i].size();
		for (int k = index; k >= 0; k--)
		{
			if (obj2.area[i][k] == type1)
			{
				index1 = k;
				break;
			}
		}
		for (int k = index; k < row; k++)
		{
			if (obj2.area[i][k] == obj2.getType())
			{
				index2 = k;
				break;
			}
		}
		how_Much_To_Move_Left[i] = absoluteValue(index2 - index1-1);
		index1 = 0;
		index2 = 0;
	}

/* There are 3 dimentions on total 2dvector. This how_Much_To.... vector holds the amount of empty_block element to be deleted on every line*/
	// cout<<"___________";
	// cout<<how_Much_To_Move_Left[0];
	// cout<<how_Much_To_Move_Left[1];
	// cout<<how_Much_To_Move_Left[2];
	// cout<<"___________"<<endl;

	int min_Move_Left = minValue(how_Much_To_Move_Left);

	/*Deleting spaces between two tetromino*/
	for (int i = 0; i < 3; i++){
		for (int k = index; k < row; k++){
			if (obj2.area[i][k] == obj2.getType()){
				obj2.area[i][k-min_Move_Left] = obj2.getType();
				obj2.area[i][k] = shapes::empty_block;
			}
		}
	}
	return (row);
};

void tetrimino::organise(){
	if (t_shape[2][0] == shapes::empty_block && t_shape[2][1] == shapes::empty_block && t_shape[2][2] == shapes::empty_block)
	{
		t_shape.pop_back();
		vector<vector<shapes>>temp;
		temp.push_back({shapes::empty_block,shapes::empty_block,shapes::empty_block});
		temp.push_back(t_shape[0]);
		temp.push_back(t_shape[1]);
		t_shape = temp;
	}
	// printVectors(t_shape);
}

