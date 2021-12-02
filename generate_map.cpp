#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "generate_map.h"
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


void generate_map(map *&a){
	int type;
	for (int i=1;i<MAPSIZE;i++){
		for (int j=1;j<MAPSIZE;j++){
			srand(time(NULL));
      type = rand()%20;
			switch (type){
				case 1: a[i*MAPSIZE+j].resources='W';
				        a[i*MAPSIZE+j].resources_amount=(rand()%100+1);
				        break;
				case 2: a[i*MAPSIZE+j].resources='F';
				        a[i*MAPSIZE+j].resources_amount=(rand()%100+1);
				        break;
				default:
					    a[i*MAPSIZE+j].resources=' ';
				        a[i*MAPSIZE+j].resources_amount=0;
				        break;
			}
		}
	}
	a[0].resources = 'H';
	a[0].resources_amount=0;
	
}
