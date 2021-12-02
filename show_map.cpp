#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "show_map.h"
using namespace std;

const int filenamesize=80;
const int MAPSIZE = 10;
const int MAX_Stamina = 100;
const int wood2box = 50;
const int wood2axe = 30;
// location of player
//int loc_x, loc_y = 0;
struct map{
//  char path = 0;
  char resources =0;
  int resources_amount = 0;

};
struct strength{
  int Box,Axe,Wood,Food,Stamina,loc_x,loc_y=0;	
};

void show_map(map *&a, strength *s,bool &input_correct_command){
	cout << endl << " ";
	for (int k=0;k<MAPSIZE;k++) cout << setw(4) << k;
	cout << endl;
	for (int i=0;i<MAPSIZE;i++){
		cout << i;
		for (int j=0;j<MAPSIZE;j++){
			if (s->loc_x == i && s->loc_y == j) 
				cout << setw(3) << "*" << a[i*MAPSIZE+j].resources;
			else 
			    cout << setw(4) << a[i*MAPSIZE+j].resources;
		}
		cout << endl;
	}
	cout << setfill('=') << setw(70) << "=" << endl;
	//cout << setfill(' ') << setw(4);
    cout << "Stamina(" << setfill(' ') << setw(4) << s->Stamina << ")  ";
    cout << "Box(" << setfill(' ') << setw(4) <<  s->Box << ")  ";
    cout << "Axe(" << setfill(' ') << setw(4) <<  s->Axe << ")  "; 
    cout << "Wood(" << setfill(' ') << setw(4) <<  s->Wood << ")  "; 
    cout << "Food(" << setfill(' ') << setw(4) <<  s->Food << ")  ";
    
	cout << endl;   
	cout << "'*' = You are here, 'H' = Home, 'W' = location of Woods, 'F' = location of food " <<endl;
	if (!input_correct_command){
    		cout << "Please type valid command. The command list can be displayed through input '?'" << endl;
  	}
  	input_correct_command = true;	
	cout << "Input>  " ;
}
