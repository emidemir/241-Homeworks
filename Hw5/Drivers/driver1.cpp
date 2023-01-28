#include <iostream>
#include <vector>
#include <limits>
#include "../Headers/TetrisAdapter.hpp"
#include "../Implementations/TetrisAdapter.cpp"
#include "../Headers/TetrisArray1D.hpp"
#include "../Headers/TetrisVector.hpp"

using namespace Emirhan;
using namespace std;

int main()
{

	int x = 0;
	int y = 0;
	string userInput;
	bool checkInput = true;

	/*Get axis of board*/
	getAxis(x,y);
	
	char GameType = '0';
	GameType = 'V';

	/*Get which class to use*/
	cout << "Which Board (TetrisVector = 'V') (TetrisArray1D = '1') (TetrisAdapter = 'A') : ";
	while (checkInput){
		getline(cin,userInput);
		if (userInput.length() == 1)
		{
			GameType = userInput[0];
			if (GameType == 'V' || GameType == '1' || GameType == 'A')
				checkInput = false;
			else
				cout << "Try again : ";
		}
		else
			cout << "Try Again : ";
	}

	shapes userShape;
	bool keepPlaying = true;

	/*TetrisVector*/
	if (GameType == 'V')
	{
		TetrisVector Game1(x,y);
		
		while (keepPlaying)
		{
			userInput = "";
			userShape = getTetroType();
			if (userShape == shapes::quit)
			{
				keepPlaying = false;
				char saveFile;
				cout << "Do you want to save to file ?(Y/N) : ";
				cin >> saveFile;
				if (saveFile == 'Y'){
					string fileName;
					cout << "Enter the file name with extention (.txt) : ";
					getline(cin,fileName);
					writeToFile(Game1,fileName);
				}
			}
			
			else
			{
				Tetromino tempTetro(userShape);
				int rotAmount = 0;
				cout << "Enter amount of rotation (it will rotate right) : ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin,userInput);
				while (!convertInt(userInput,rotAmount))
				{
					cout << "Try again : ";
					userInput = "";
					getline(cin,userInput);
				}
				for (int i = 0; i < rotAmount; ++i)
					tempTetro.rotateRight90();
				int dir = 0;
				cout << "Enter direction (1 for right, -1 for left) : ";
				getline(cin,userInput);
				convertInt(userInput,dir);
				while (dir != -1 && dir != 1)
				{
					cout << "Try again : ";
					getline(cin,userInput);
					convertInt(userInput,dir);
				}

				int step = 0;
				cout << "Enter how many step yo wanna move : ";
				getline(cin,userInput);
				while (!convertInt(userInput,step))
				{
					cout << "Try again : ";
					getline(cin,userInput);
				}

				if (Game1.animate(tempTetro,dir,step) == false)
				{
					cout << "Game is over";
					return (0);
				}
			}
		}
	}
	
	/*TetrisArray1D*/
	else if (GameType == '1')
	{
		TetrisArray1D Game2(x,y);
		
		while (keepPlaying)
		{
			userInput = "";
			userShape = getTetroType();
			if (userShape == shapes::quit)
			{
				keepPlaying = false;
				char saveFile;
				cout << "Do you want to save to file ?(Y/N) : ";
				cin >> saveFile;
				if (saveFile == 'Y'){
					string fileName;
					cout << "Enter the file name with extention (.txt) : ";
					getline(cin,fileName);
					writeToFile(Game2,fileName);
				}
			}
			
			else
			{
				userInput = "";
				Tetromino tempTetro(userShape);
				int rotAmount = 0;
				cout << "Enter amount of rotation (it will rotate right) : ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin,userInput);
				while (!convertInt(userInput,rotAmount))
				{
					cout << "Try again : ";
					userInput = "";
					getline(cin,userInput);
				}
				for (int i = 0; i < rotAmount; ++i)
					tempTetro.rotateRight90();
				int dir = 0;
				cout << "Enter direction (1 for right, -1 for left) : ";
				getline(cin,userInput);
				convertInt(userInput,dir);
				while (dir != -1 && dir != 1)
				{
					cout << "Try again : ";
					getline(cin,userInput);
					convertInt(userInput,dir);
				}

				int step = 0;
				cout << "Enter how many step yo wanna move : ";
				getline(cin,userInput);
				while (!convertInt(userInput,step))
				{
					cout << "Try again : ";
					getline(cin,userInput);
				}

				if (Game2.animate(tempTetro,dir,step) == false)
				{
					cout << "Game is over";
					return (0);
				}
			}
		}

	}
	
	/*TetrisAdapter*/
	else if (GameType == 'A')
	{
		TetrisAdapter<vector<char>> Game3(x,y);
		
		while (keepPlaying)
		{
			userInput = "";
			userShape = getTetroType();
			if (userShape == shapes::quit)
			{
				keepPlaying = false;
				char saveFile;
				cout << "Do you want to save to file ?(Y/N) : ";
				cin >> saveFile;
				if (saveFile == 'Y'){
					string fileName;
					cout << "Enter the file name with extention (.txt) : ";
					getline(cin,fileName);
					writeToFile(Game3,fileName);
				}
			}
			
			else
			{
				userInput = "";
				Tetromino tempTetro(userShape);
				int rotAmount = 0;
				cout << "Enter amount of rotation (it will rotate right) : ";
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin,userInput);
				while (!convertInt(userInput,rotAmount))
				{
					cout << "Try again : ";
					userInput = "";
					getline(cin,userInput);
				}
				for (int i = 0; i < rotAmount; ++i)
					tempTetro.rotateRight90();
				int dir = 0;
				cout << "Enter direction (1 for right, -1 for left) : ";
				getline(cin,userInput);
				convertInt(userInput,dir);
				while (dir != -1 && dir != 1)
				{
					cout << "Try again : ";
					getline(cin,userInput);
					convertInt(userInput,dir);
				}

				int step = 0;
				cout << "Enter how many step yo wanna move : ";
				getline(cin,userInput);
				while (!convertInt(userInput,step))
				{
					cout << "Try again : ";
					getline(cin,userInput);
				}

				if (Game3.animate(tempTetro,dir,step) == false)
				{
					cout << "Game is over";
					return (0);
				}
			}
		}		
	}

	return (0);
}