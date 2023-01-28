#include "../Headers/TetrisVector.hpp"
#include "../Headers/TetrisArray1D.hpp"
#include "../Headers/TetrisAdapter.hpp"
#include "../Implementations/TetrisAdapter.cpp"
#include <vector>

using namespace Emirhan;
using std::cout;

int main(){

	/*________________TETRIS_____VECTOR______________*/

	/*Both Constructers work fine*/
	// TetrisVector Game1(5,5);
	// TetrisVector Game2;
	// TetrisVector Game3(Game2);

	// cout << "___________________________________________TETRISVECTOR___________________________________________"<<endl;
	// /*Draw function work fine*/
	// cout << "1) CONSTRUCTURES : "<<endl;
	// cout << "Game1 object is created by giving 5-5 to it's constructure"<< endl;
	// Game1.draw();
	// cout << "Game2 object is created by giving default constructure (10-10)"<< endl;
	// Game2.draw();
	// cout << "Game3 object is created by giving copy constructure (game2 is used)"<< endl;
	// Game3.draw();

	// Tetromino Tetro(shapes::J);

	// // /*+= works fine*/
	// cout << "2) OPEARTOR+= : "<<endl;
	// cout << "Here I am adding a tetromino to Game1 object and the board became" << endl;
	// Game1 += Tetro;
	// Game1.draw();

	// cout << "3) ADD FUNCTION : "<<endl;
	// // /*Add function works fine*/
	// Game1.add(Tetro,6,6);
	cout << "Keep In Mind that Add function do not increment the amountOfMoves since add is a special function created for aniamtion function" << endl;
	// cout << "Add fucntion takes 3 parameter, first is tetromino and other two are xAxis and yAxis" << endl;
	// cout << "function tries to put given tetromino to expressed position. If can't, function returns false" << endl;
	// cout << "Game1 object after add function is used for (6,6) position on board"<<endl;
	// Game1.draw();

	// cout << "Trying to add a Tetromino to outside of board, let's see what will happen" << endl;
	// if (Game1.add(Tetro, 15,15) == false){
	// 	cout << "This print will be printed if function returns false for position 15,15 which is abviously out of board" << endl;
	// }

	// cout << "4) ANIMATE : "<<endl;

	// int a;
	// cout << "Press a key to start animation" << endl;
	// cin>>a;
	// Game2.animate(Tetro,1,3);


	// cout << "5) WRITE TO FILE : "<<endl;
	// /*WriteFile function works fine*/
	// if (writeToFile(Game1, "Game1.txt") == true){
	// 	cout << "Game1 is written to text Board was(5,5)" << endl;
	// }

	// cout << "6) READ FROM FILE : "<<endl;
	// // /*Reading from file*/
	// readFromFile(Game3,"Game1.txt");

	// cout << "Game3 after : " <<
	// endl << endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl;
	// Game3.draw();
	// cout << "Also when you read from file, an object can get every value from the board as it must do. TO prove that, I printed some values" << endl;
	// cout << "Game3's last moved tetromino's type is : " << (char)Game3.lastMove().getType();
	// cout << "Game3 was 10-10 board but after reading from file, it's values have changed to : " << Game3.getheight() << "-" << Game3.getwidth() << endl; 

	

	/*____________TETRIS_____1D_____ARRAY__________________*/

// /*Both Constructers work fine*/
// 	TetrisArray1D Game4(5,5);
// 	TetrisArray1D Game5;
// 	TetrisArray1D Game6(Game5);

// 	cout << "___________________________________________TetrisArray1D___________________________________________"<<endl;
// 	/*Draw function work fine*/
// 	cout << "1) CONSTRUCTURES : "<<endl;
// 	cout << "Game4 object is created by giving 5-5 to it's constructure"<< endl;
// 	Game4.draw();
// 	cout << "Game5 object is created by giving default constructure (10-10)"<< endl;
// 	Game5.draw();
// 	cout << "Game6 object is created by giving copy constructure (Game5 is used)"<< endl;
// 	Game6.draw();

// 	Tetromino Tetro(shapes::J);

// 	// /*+= works fine*/
// 	cout << "2) OPEARTOR+= : "<<endl;
// 	cout << "Here I am adding a tetromino to Game4 object and the board became" << endl;
// 	Game4 += Tetro;
// 	Game4.draw();

// 	cout << "3) ADD FUNCTION : "<<endl;
// 	// /*Add function works fine*/
// 	Game4.add(Tetro,6,6);
cout << "Keep In Mind that Add function do not increment the amountOfMoves since add is a special function created for aniamtion function" << endl;
// 	cout << "Add fucntion takes 3 parameter, first is tetromino and other two are xAxis and yAxis" << endl;
// 	cout << "function tries to put given tetromino to expressed position. If can't, function returns false" << endl;
// 	cout << "Game4 object after add function is used for (6,6) position on board"<<endl;
// 	Game4.draw();

// 	cout << "Trying to add a Tetromino to outside of board, let's see what will happen" << endl;
// 	if (Game4.add(Tetro, 15,15) == false){
// 		cout << "This print will be printed if function returns false for position 15,15 which is abviously out of board" << endl;
// 	}

// 	cout << "4) ANIMATE : "<<endl;

// 	int a;
// 	cout << "Press a key to start animation" << endl;
// 	cin>>a;
// 	Game5.animate(Tetro,1,3);


// 	cout << "5) WRITE TO FILE : "<<endl;
// 	/*WriteFile function works fine*/
// 	if (writeToFile(Game4, "Game4.txt") == true){
// 		cout << "Game4 is written to text Board was(5,5)" << endl;
// 	}

// 	cout << "6) READ FROM FILE : "<<endl;
// 	// /*Reading from file*/
// 	readFromFile(Game6,"Game4.txt");

// 	cout << "Game6 after : " <<
// 	endl << endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl;
// 	Game6.draw();
// 	cout << "Also when you read from file, an object can get every value from the board as it must do. TO prove that, I printed some values" << endl;
// 	cout << "Game6's last moved tetromino's type is : " << (char)Game6.lastMove().getType();
// 	cout << "Game6 was 10-10 board but after reading from file, it's values have changed to : " << Game6.getheight() << "-" << Game6.getwidth() << endl; 

/*________________TETRIS ADAPTER________________*/

/*Both Constructers work fine*/
	TetrisAdapter<vector<char>> Game7(5,5);
	TetrisAdapter<vector<char>> Game8;
	TetrisAdapter<vector<char>> Game9(Game8);

	cout << "___________________________________________TetrisAdapter___________________________________________"<<endl;
	/*Draw function work fine*/
	cout << "1) CONSTRUCTURES : "<<endl;
	cout << "Game7 object is created by giving 5-5 to it's constructure"<< endl;
	Game7.draw();
	cout << "Game8 object is created by giving default constructure (10-10)"<< endl;
	Game8.draw();
	cout << "Game9 object is created by giving copy constructure (Game8 is used)"<< endl;
	Game9.draw();

	Tetromino Tetro(shapes::J);

	// /*+= works fine*/
	cout << "2) OPEARTOR+= : "<<endl;
	cout << "Here I am adding a tetromino to Game7 object and the board became" << endl;
	Game7 += Tetro;
	Game7.draw();

	cout << "3) ADD FUNCTION : "<<endl;
	// /*Add function works fine*/
	Game7.add(Tetro,6,6);
	cout << "Keep In Mind that Add function do not increment the amountOfMoves since add is a special function created for aniamtion function" << endl;
	cout << "Add fucntion takes 3 parameter, first is tetromino and other two are xAxis and yAxis" << endl;
	cout << "function tries to put given tetromino to expressed position. If can't, function returns false" << endl;
	cout << "Game7 object after add function is used for (6,6) position on board"<<endl;
	Game7.draw();

	cout << "Trying to add a Tetromino to outside of board, let's see what will happen" << endl;
	if (Game7.add(Tetro, 15,15) == false){
		cout << "This print will be printed if function returns false for position 15,15 which is abviously out of board" << endl;
	}

	cout << "4) ANIMATE : "<<endl;

	int a;
	cout << "Press a key to start animation" << endl;
	cin>>a;
	Game8.animate(Tetro,1,3);


	cout << "5) WRITE TO FILE : "<<endl;
	/*WriteFile function works fine*/
	if (writeToFile(Game7, "Game7.txt") == true){
		cout << "Game7 is written to text Board was(5,5)" << endl;
	}

	cout << "6) READ FROM FILE : "<<endl;
	// /*Reading from file*/
	readFromFile(Game9,"Game7.txt");

	cout << "Game9 after : " <<
	endl << endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl <<endl;
	Game9.draw();
	cout << "Also when you read from file, an object can get every value from the board as it must do. TO prove that, I printed some values" << endl;
	cout << "Game9's last moved tetromino's type is : " << (char)Game9.lastMove().getType();
	cout << "Game9 was 10-10 board but after reading from file, it's values have changed to : " << Game9.getheight() << "-" << Game9.getwidth() << endl; 


	return (0);
}
