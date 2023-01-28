#include <iostream>
#include "../Headers/tetris.hpp"
#include "../Headers/tetromino.hpp"



using namespace std;
using namespace Tetris;

int main(){

	int xAxis, yAxis;
	
	// getAxis(xAxis,yAxis);
	xAxis = 10;
	yAxis = 10;

	tetris GameOn(xAxis,yAxis);

	shapes choice;

	choice = TetroType();
	if (choice == shapes::quit)
		exit(1);

	/*----------------------------------GAME STARTS---------------------------------*/
	int dir = 0;
	int step = 0;
	int rotateTime = 0;
	bool checkInput = false;
	char *userInput = new char[100];
	
	do{
		/*Get tetromino type*/
		tetrimino shape(choice);

		/*Get How Many Time To Rotates*/
		while (checkInput == false)
		{
			cout<<"How many time you want to rotate : ";
			cin.getline(userInput,100);
			if (convertInt(userInput,rotateTime) == true)
				checkInput = true;
			else{
				cout<<"Try again!!!"<<endl;
			}
		}
		checkInput = false;

		/*Rotate Tetromino*/
		for (int i = 0; i < rotateTime; i++){
			shape.rotateRight90();
		}

		/*Get Direction*/
		while (checkInput == false)
		{
			cout<<"Enter a direction (1 for right, -1 for left): ";
			cin.getline(userInput,100);
			convertInt(userInput,dir);
			if (dir == 1 || dir == -1)
				checkInput = true;
			else{
				cout<<"Try again!!!"<<endl;
			}
		}
		checkInput = false;

		/*Get How Many Step*/
		while (checkInput == false)
		{
			cout<<"How many step you want to move ?? : ";
			cin.getline(userInput,100);
			convertInt(userInput,step);
			if (step > 0 && dir == -1 && step <= xAxis/2){
				checkInput = true;
			}
			else if (step > 0 && dir == 1 && step <= (xAxis/2 - shape.getLenght())){
				checkInput = true;
			}
			else{
				cout<<"Try again!!!"<<endl;
			}
		}	
		checkInput = false;

		if (GameOn.animate(shape, dir, step) == false){
			cout<<"No more place to add tetromino. Game is over!!"<<endl;
			break;
		}

		cout<<"\033["<<(yAxis + 2)<<"A";
		choice = TetroType();

	}while(choice != shapes::quit);

	delete [] userInput;
	return (0);
}