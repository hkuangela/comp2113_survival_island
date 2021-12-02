#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "navigate.h"
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

void navigate(strength *&s){
    int x,y;	
    char temp;
    cout << "Enter X and Y co-ordinates : ";
	cin >> x >> y ;
	if (x >= MAPSIZE  || y >= MAPSIZE || x < 0 || y < 0) {
		cout << "!!!  Outside Island  !!!" << endl;
		cout << " Press 'e' to continue ...... " << endl;
		while (temp != 'e') {
			cin >> temp;
		}
	} else {
		s->Stamina -= 2*(abs(0.5*(x-s->loc_x))+abs(0.5*(y-s->loc_y)));
		s->Stamina <= 0 ? s->Stamina=0: s->Stamina;
		s->loc_x = x; s->loc_y = y;
	}
}
