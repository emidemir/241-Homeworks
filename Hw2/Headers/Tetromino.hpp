#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum class shapes{I='I',O='O',T='T',J='J',L='L',S='S',Z='Z', empty_block = '.', quit='q',random='r'};

extern vector<vector<shapes>>I_U;
extern vector<vector<shapes>>O_U;
extern vector<vector<shapes>>T_U;
extern vector<vector<shapes>>J_U;
extern vector<vector<shapes>>L_U;
extern vector<vector<shapes>>S_U;
extern vector<vector<shapes>>Z_U;

class tetrimino{
	public:
		tetrimino(shapes type);

		/*deprecated*/void inline setType(shapes type){t_type = type;};
		/*deprecated*/void inline setHeight(int h){height = h;};
		/*deprecated*/void inline setWidth(int w){width = w;};
		/*deprecated*/shapes inline getType()const{return t_type;};
		/*deprecated*/int inline getHeight()const{return height;};
		/*deprecated*/int inline getWidth()const{return width;};
		/*deprecated*/char inline getDir()const{return d;};
		/*deprecated*/void setDir(char direction){d = direction;};

		void inline setRotation(char dir){direction = dir;};
		void inline setVertical(int h){vertical = h;};
		void inline setHorizontal(int w){horizontal = w;};
		char inline getRotation()const{return (direction);};
		int inline	getVertical()const{return (vertical);};
		int inline	getHorizontal()const{return (horizontal);};

		/*Deprecated*/vector<vector<shapes>> mergeVectors(vector<vector<shapes>>v1,vector<vector<shapes>>v2)const;
		/*Deprecated*/bool canFit(tetrimino &object2,char dir);
		/*Deprecated*/int tetAmount(shapes type,vector<vector<shapes>>board);
		void rotate2(char dir);
		void print() const;
		/*Deprecated*/bool moveBoard(vector<vector<shapes>>tempBoard, tetrimino &object2, char dir);
		/*Deprecated*/void organise();
		vector<vector<shapes>>t_shape;
		static vector<vector<shapes>>area;
	
	private:
		shapes t_type;
		int horizontal;
		int vertical;
		char direction;


		/*Deprecated*/int width = 0;				//	Amount of intersection point between current tetromino and previous one.
		/*Deprecated*/int height = 999;			//	Height of current tetromino.
		/*Deprecated*/char d;						//	Witch direction of object is best fit
		
};

int mergeWithArea(tetrimino object2, shapes type1, int index);
bool convertInt(string ui_input, int *amount);
void printVectors(vector<vector<shapes>>v1);
int minValue(vector<int>vec);