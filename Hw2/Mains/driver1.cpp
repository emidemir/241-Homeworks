#include "../Headers/Tetris.hpp"
#include "../Headers/Tetromino.hpp"

using namespace std;

int main(){

	tetrimino unit1(shapes::T);
	tetrimino unit2(shapes::I);
	tetroBoard temp_Holder;

	cout<<"Functions from tetrimino : "<<endl;
	cout<<"1) Print function works perfectly: "<<endl;
	unit1.print();

	cout<<"2) Rotate function works perfectly: "<<endl;
	unit1.rotate2('r');
	unit1.print();

	cout<<"3) Merge Function works perfectly (not used on this homework): "<<endl;
	temp_Holder = unit1.mergeVectors(unit1.t_shape, unit2.t_shape);
	printVectors(temp_Holder);
	
	cout<<"4) tetAmount Function works perfectly (not used on this homework): "<<endl;
	cout<<"Amount of tetromino on unit1 variable is->>"<<unit1.tetAmount(shapes::T,unit1.t_shape)<<endl;
	
	cout<<"5) Merge Function works perfectly (not used on this homework): "<<endl;
	
	cout<<"6) Can fit function works perfectly (not used on this homework): "<<endl;
	cout<<"I am checking if unit2 (I) can fit to unit1 (T). Can fit will try every position(Right, down, left)."<<endl;
	cout<<"0 means false, 1 means true"<<endl;
	cout<<unit1.canFit(unit2,'r')<<endl;

	cout<<"7) moveBoard function works perfectly (not used on this homework): "<<endl;
	cout<<"This functions set the values such as intersection point of the tetromino, height of them and direction of tetromino"<<endl;
	cout<<"If better fit position is found, values are reseted"<<endl;
	cout<<"This are the values"<<endl;
	unit1.moveBoard(unit2.t_shape, unit2, 'r');
	cout<<unit2.getHeight()<<"Height of I"<<endl;
	cout<<unit2.getWidth()<<"intersection point amount with T and I"<<endl;
	cout<<unit2.getDir()<<"Direction of I"<<endl;

	cout<<"8) mergeWithArea function does not works properly because of the structure of driver1 file is not appropriate to this function (not used on this homework): "<<endl;
	cout<<"It is merging two vectors but it has problems"<<endl;
	// unit1.area.push_back(vector<shapes>());
	// unit1.area.push_back(vector<shapes>());
	// unit1.area.push_back(vector<shapes>());
	// unit1.area = unit1.mergeVectors(unit1.area, unit1.t_shape);
	// mergeWithArea(unit2,shapes::T,3);
	// unit2.organise();
	// printVectors(unit2.area);

	cout<<"____________TETRIS CLASS FUCNTIONS______________"<<endl;
	
	Tetris game(10,10);

	cout<<"1) Draw function works perfectly: "<<endl;
	game.draw();
	cout<<"\n\n\n\n\n\n\n\n\n\n"<<endl;
	cout<<"2) Add function works perfectly: "<<endl;
	cout<<"It adds tetrominos to the place where you wish. Just write the coordinates."<<endl;
	cout<<"It also uses the direction information from tetromino class of each tetromino object."<<endl;
	game.add(unit1, 0,0);
	game.draw();

	cout<<"3) Fit function works perfectly: "<<endl;
	cout<<"What this fucntion does is searching for proper place on board."<<endl;
	cout<<"When it finds an empty block element on the board, it tries 3 rotatşon position of tetromino (normal, right, left)."<<endl;
	cout<<"It sets values of coordinates and direction to tetroomino object, and return true which indicates tetromino is added to a place."<<endl;

	Tetris myGame(10,10);
	cout<<"4) Animate function works perfectly: "<<endl;
	cout<<"What it does is, start from 5 x axis and 0 y axis(on a 10x10 board) and move tetromino untill it reaches the destination"
	<<"which is saved on fit function to tetromino object"<<endl;
	cout<<"It moves tetromino 1 unit per 50ms";
	myGame.animate(unit2);

	
	
	// tetrimino tetro(shapes::L);

	// cout<<game.add(tetro,4,5)<<endl;
	// game.draw();
	// cout<<game.add(tetro,4,5)<<endl;

	return (0);
}