#include "../Headers/Tetris.hpp"

using namespace std;

int main(){

	int xAxsis, yAxsis;
	bool gameOver = false;

	/*Getting the sizes of board*/
	getAxis(xAxsis,yAxsis);
	shapes choice = shapes::empty_block;

	Tetris myGame(xAxsis,yAxsis);
	bool GameOver = false; 

	/*Continue as long as user do not enter quit*/
	while (choice != shapes::quit){

		choice = getType();
		if (choice == shapes::quit)
			break;
		tetrimino tempObject(choice);
		
		GameOver = myGame.animate(tempObject);
		
		if (GameOver == true)
			break;
	}

	cout<<"______________________GAME IS OVER______________________"<<endl;
	/*Clear the console after complete the game*/
	// cout<<"\033[2J";	/*ANSI code of clearing the console. By the way, ANSI codes are working fine on VSCode terminal which uses WSL*/

	return (0);
}