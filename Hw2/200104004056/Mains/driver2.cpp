#include "../Headers/Tetris.hpp"

using namespace std;

int main(){

	int xAxsis, yAxsis;
	bool gameOver = false;

	getAxis(xAxsis,yAxsis);
	shapes choice = shapes::empty_block;

	Tetris myGame(xAxsis,yAxsis);	/*Creating object*/

	while (gameOver == false){	/*Play as long as gameOver is true or user do not enter quit(quit will breake the loop)*/
		
		/*Get the type of new tetromino*/
		choice = getType();
		if (choice == shapes::quit)
			break;
		/*Create new tetromino*/
		tetrimino tempObject(choice);

		if (myGame.fit(tempObject) == true)
			break;

		gameOver = myGame.animate(tempObject);
		cout<<"\033["<<(yAxsis + 2)<<"A";
	}

	cout<<"___________GAME IS OVER_________"<<endl;
	/*Clear the console after complete the game*/
	// cout<<"\033[2J";	/*ANSI code of clearing the console. By the way, ANSI codes are working fine on VSCode terminal which uses WSL*/

	return (0);
}