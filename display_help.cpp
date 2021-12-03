//Chow Cheuk Ying | UID: 3035565140 | BEng(CivE) Year 4
//Cheung Wang | UID: 3035570949 | BEng(CivE) Year 4
//Description: Main program for starting the game.
// Last Changed: Ded 3, 2021

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "display_help.h"
using namespace std;


//Function called when the player want to know the command in this game.
// Achieved the Code Requirement Task 5: Program codes in multiple files

void display_help(){
    cout << endl;
	cout << "? ... help " << endl;
	cout << "b ... build a box" << endl;
	cout << "a ... make an axe" << endl;
	cout << "n ... nagviate" << endl;
	cout << "g ... gather wood or food" << endl;
	cout << "w ... burn wood" << endl;
	cout << "e ... eat food" << endl;
	cout << "r ... refresh map" << endl;
	cout << "i ... input file" << endl;
	cout << "s ... save to file" << endl;
	cout << "q ... quit" << endl;
	cout << setfill('=') << setw(70) << "=" << endl;
	cout << setfill(' ');
}
