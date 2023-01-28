#pragma once
#include "header.h"

using namespace std;

/*_______________SHAPE OF I______________*/
vector<vector<shapes>>I_U = {
	{shapes::empty_block,shapes::I,shapes::empty_block},
	{shapes::empty_block,shapes::I,shapes::empty_block},
	{shapes::empty_block,shapes::I,shapes::empty_block}
};

// vector<vector<shapes>>I_LR =  {
// 	{shapes::empty_block,shapes::empty_block,shapes::empty_block},
// 	{shapes::I,shapes::I,shapes::I},
// 	{shapes::empty_block,shapes::empty_block,shapes::empty_block}
// };

/*_______________SHAPE OF O_______________*/

vector<vector<shapes>>O_U = {	//	shapes I of Up
	{shapes::empty_block,shapes::empty_block,shapes::empty_block},
	{shapes::empty_block,shapes::O,shapes::O},
	{shapes::empty_block,shapes::O,shapes::O}
};

/*_____________SHAPE OF T_________________*/

vector<vector<shapes>>T_U {
	{shapes::empty_block,shapes::empty_block,shapes::empty_block},
	{shapes::T,shapes::T,shapes::T},
	{shapes::empty_block,shapes::T,shapes::empty_block}
};

// vector<vector<shapes>>T_L{
// 	{shapes::T,shapes::empty_block,shapes::empty_block},
// 	{shapes::T,shapes::T,shapes::empty_block},
// 	{shapes::T,shapes::empty_block,shapes::empty_block}
// };

// vector<vector<shapes>>T_R {
// 	{shapes::empty_block,shapes::empty_block,shapes::T},
// 	{shapes::empty_block,shapes::T,shapes::T},
// 	{shapes::empty_block,shapes::empty_block,shapes::T}
// };

// vector<vector<shapes>>T_D {
// 	{shapes::empty_block,shapes::empty_block,shapes::empty_block},
// 	{shapes::empty_block,shapes::T,shapes::empty_block},
// 	{shapes::T,shapes::T,shapes::T}
// };

/*_____________SHAPE OF j_________________*/

vector<vector<shapes>>J_U{
	{shapes::empty_block,shapes::J,shapes::empty_block},
	{shapes::empty_block,shapes::J,shapes::empty_block},
	{shapes::J,shapes::J,shapes::empty_block}
};

// vector<vector<shapes>>J_R{
// 	{shapes::J,shapes::empty_block,shapes::empty_block},
// 	{shapes::J,shapes::J,shapes::J},
// 	{shapes::empty_block,shapes::empty_block,shapes::empty_block}
// };

// vector<vector<shapes>>J_L{
// 	{shapes::J,shapes::J,shapes::J},
// 	{shapes::empty_block,shapes::empty_block,shapes::J},
// 	{shapes::empty_block,shapes::empty_block,shapes::empty_block}
// };

// vector<vector<shapes>>J_D{
// 	{shapes::empty_block,shapes::J,shapes::J},
// 	{shapes::empty_block,shapes::J,shapes::empty_block},
// 	{shapes::empty_block,shapes::J,shapes::empty_block}
// };

/*_____________SHAPE OF L_________________*/

vector<vector<shapes>>L_U{
	{shapes::empty_block,shapes::L,shapes::empty_block},
	{shapes::empty_block,shapes::L,shapes::empty_block},
	{shapes::empty_block,shapes::L,shapes::L}
};

// vector<vector<shapes>>L_R{
// 	{shapes::L,shapes::L,shapes::L},
// 	{shapes::L,shapes::empty_block,shapes::empty_block},
// 	{shapes::empty_block,shapes::empty_block,shapes::empty_block}
// };

// vector<vector<shapes>>L_L{
// 	{shapes::empty_block,shapes::empty_block,shapes::empty_block},
// 	{shapes::empty_block,shapes::empty_block,shapes::L},
// 	{shapes::L,shapes::L,shapes::L}
// };


// vector<vector<shapes>>L_D{
// 	{shapes::L,shapes::L,shapes::empty_block},
// 	{shapes::empty_block,shapes::L,shapes::empty_block},
// 	{shapes::empty_block,shapes::L,shapes::empty_block}
// };

/*_____________SHAPE OF S_________________*/

vector<vector<shapes>>S_U{
	{shapes::empty_block,shapes::S,shapes::S},
	{shapes::S,shapes::S,shapes::empty_block},
	{shapes::empty_block,shapes::empty_block,shapes::empty_block}
};

// vector<vector<shapes>>S_RL{					// Left and right are same	
// 	{shapes::empty_block,shapes::S,shapes::empty_block},
// 	{shapes::empty_block,shapes::S,shapes::S},
// 	{shapes::empty_block,shapes::empty_block,shapes::S}
// };

/*_____________SHAPE OF Z_________________*/


vector<vector<shapes>>Z_U{
	{shapes::Z,shapes::Z,shapes::empty_block},
	{shapes::empty_block,shapes::Z,shapes::Z},
	{shapes::empty_block,shapes::empty_block,shapes::empty_block}
};

// vector<vector<shapes>>Z_RL{					// Left and right are same	
// 	{shapes::empty_block,shapes::Z,shapes::empty_block},
// 	{shapes::empty_block,shapes::Z,shapes::Z},
// 	{shapes::empty_block,shapes::Z,shapes::empty_block}
// };