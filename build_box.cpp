#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "build_box.h"
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


void build_box(strength *&status){
	if (status->loc_x == 0 && status->loc_y == 0){ 
        if (status->Wood < (wood2box + wood2box*status->Box)){
           	cout << "Not enough Wood !!! " << endl; 
        } else {
           	status->Wood-=(wood2box + wood2box*status->Box);
           	status->Box++;
        }
    } else {
       	cout << "Not at Home !!! " << endl;
    }
}
