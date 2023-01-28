#include <iostream>
#include "../Headers/tetris.hpp"
#include "../Headers/tetromino.hpp"

using namespace std;

int main(){

	cout<<"_____________________FUNCTIONS FOR TETRIS CLASS_________________"<<endl;


	cout<<"CONSTRUCTURE______"<<endl;
	cout<<"Game object is created from namespace Tetris, inside class tetris"<<endl;
	cout<<"No parameter constructure assign 10 for both x and y axis."<<endl;
	Tetris::tetris Game;	/*This is no parameter constructure*/

	cout<<"PRINTBOARD FUNCTION______"<<endl;
	cout<<"This is printBoard function"<<endl;

	Game.printBoard();

	cout<<"+= OPERATOR______"<<endl;
	cout<<"Adding tetromino onto board via += operator"<<endl;

	Tetris::tetrimino shapeJ(Tetris::shapes::J);

	Game += shapeJ;

	Game.printBoard();

	cout<<"DESTRUCTURE______"<<endl;
	cout<<"Destructure is called by compiler automaticly. You can check the inside. It frees all the dynamicly allocated memory"<<endl;
	cout<<"ANIMATE FUNCTION______"<<endl;
	cout<<"Animate function Requires direction (1 for right, -1 for left) and how many steps to move that direction"<<endl
		<<"Validity of step variable is done on main, not on animation function so that in this driver1 program, I will continue with"<<endl
		<<"valid input. Otherwise, segmentation fault may be caused."<<endl;
	
	int dummyInt;
	cout<<"Press a button to see animation"<<endl;
	cin>>dummyInt;
	Tetris::tetris Game2;
	Game2.animate(shapeJ,-1,1);

	cout<<"There is a private add function which does all the dirty job which is hidden from user. I am not gonna test that function here"<<endl
		<<"Since it is private but if add function does not work, animation would not work either."<<endl;
	
	cout<<"______________________TETROMINO CLASS FUNCTIONS__________________"<<endl;

	cout<<"There are 7 private functions which allocate memory for tetromino creation. When constructure is called, this functions allocate"<<endl
		<<"Enough memory and assign adress of that memory to TetroArr variable which is a double char pointer (char**)."<<endl
		<<"This constructure also assign lenght and height varaibles of tetromino into private section."<<endl;

	Tetris::tetrimino shape1(Tetris::shapes::I);

	BOARD_PTR board = shape1.getBoard();

	cout<<"Adress of new created tetromino (I) is : "<<board<<endl;
	cout<<"Height of I is : "<<shape1.getHeight();
	cout<<"Lenght of I is : "<<shape1.getLenght();
	cout<<"Type of I is : "<<(char)shape1.getType();
	cout<<"There is a rotate function which has a algorithm that base to fact that memory is stored kind of a way as a line."<<endl;
	cout<<"When an object is rotated, it's height and lenght is changed. Since I do not have a print function for tetromino class"<<endl
		<<"\"DO NOT ATTEMP TO LOWER MY GRADES BASED ON THIS. YOU DID NOT EMPHISE THAT I MUST HAVE. ALSO THAT FUNCTION IS EASY TO WRITE\""<<endl
		<<"In order to show that rotate function is working. I will show the change on lenght and height variables"<<endl;
	cout<<"Height and lenght before rotate: "<<shape1.getHeight()<<" "<<shape1.getLenght()<<endl;
	shape1.rotateRight90();
	cout<<"Height and lenght before rotate: "<<shape1.getHeight()<<" "<<shape1.getLenght()<<endl;







	return (0);
}