#include <iostream>
#include <string>
#include <vector>
#include "header.h"

using namespace std;

/*
	_____________________________________REMINDER_______________________________________
	Program can find the best fit of TWO single tetromino but when it comes to combining them, it sucks
	Line 92,93,94 are written just to prove that
	I could not find the best algorithm but did my best. 
*/


int main(){

	int amount; 			//Amunt of tetriminos.
	string ui_input; 			//Value that user entered on console. Used both for int and type inputs
	bool validInput = false;	//Control untill input is valid. Only used for int input validation

	/*_____Input Validation_____*/

	cout<<"How Many Tetriminos You Want ???"<<endl;
	getline(cin,ui_input);

	while (validInput == false){
		validInput = convertInt(ui_input,&amount);
		if (validInput == false){
			cout<<"You entered wrong input, try again!!"<<endl;
			ui_input = "";
			getline(cin,ui_input);
		}
		else
			validInput = true;
	}

	/*_______Type Validation_____*/

	cout<<"What are the types ??"<<endl;

	ui_input = "";
	vector<shapes> tetrisTypes;

	for (int i = 0; i < amount; i++){
		getline(cin,ui_input);
		if (ui_input.length() == 1){
			char tmp = ui_input[0];
			if (tmp != 'I' && tmp != 'O' && tmp != 'T' && tmp != 'J'&&
				tmp != 'L' && tmp != 'S' && tmp != 'Z')
			{
				cout<<"You entered invalid type, try again !!"<<endl;
				i--;
			}
			else{
				tetrisTypes.push_back(static_cast<shapes>(tmp));
			}
		}

		else{
			cout<<"You entered invalid type, try again !!"<<endl;
			i--;
		}
	}

	cout<<"Types are "<<endl;
	vector<tetrimino> ui_Tetriminos;

	/*_______ _____*/
	for (auto i : tetrisTypes){
		auto holder = tetrimino(i);
		holder.setType(i);
		ui_Tetriminos.push_back(holder);
	}

	for (auto i: ui_Tetriminos){
		i.print();
	}

	/*First object is assigned automaticly into the area. Rest is gonna be proccessed*/
	ui_Tetriminos[0].area.push_back(vector<shapes>());
	ui_Tetriminos[0].area.push_back(vector<shapes>());
	ui_Tetriminos[0].area.push_back(vector<shapes>());
	ui_Tetriminos[0].area = ui_Tetriminos[0].mergeVectors(ui_Tetriminos[0].area,ui_Tetriminos[0].t_shape);

	int index = 3;
	for (int i = 0; i < amount-1; i++){
		/*Finding the best fit position. Getting best fit direction*/
		ui_Tetriminos[i].canFit(ui_Tetriminos[i+1],'l');
		ui_Tetriminos[i].canFit(ui_Tetriminos[i+1],'d');
		ui_Tetriminos[i].canFit(ui_Tetriminos[i+1],'r');
		ui_Tetriminos[i].canFit(ui_Tetriminos[i+1],'u');

		// cout<<"True direction of "<<(char)ui_Tetriminos[i+1].getType()<<" to fit BEST on "<<(char)ui_Tetriminos[i].getType()<<" is -->>"<<ui_Tetriminos[i+1].getDir()<<endl;
		// cout<<"They are instersecting on "<<ui_Tetriminos[i+1].getWidth()<<" point"<<endl;
		// cout<<"Total height of them is "<<ui_Tetriminos[i+1].getHeight()<<endl;


		/* Merging best fit position of tetromino with result vector*/
		ui_Tetriminos[i+1].rotate2(ui_Tetriminos[i+1].getDir());
		ui_Tetriminos[i+1].organise();
		ui_Tetriminos[i].area = ui_Tetriminos[i].mergeVectors(ui_Tetriminos[i].area,ui_Tetriminos[i+1].t_shape);
		// printVectors(ui_Tetriminos[0].area);

		index = mergeWithArea(ui_Tetriminos[i+1], ui_Tetriminos[i].getType(), index);
	}

	cout<<"Finall Area:"<<endl;
	printVectors(ui_Tetriminos[0].area);

	
	return (0);
}