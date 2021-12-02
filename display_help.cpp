//display_help.cpp
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
