#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

const int MAPSIZE = 4;
const int MAX_Stamina = 100;
const int wood2box = 50;
const int wood2axe = 30;
// location of player
int loc_x, loc_y = 0;
struct map{
//  char path = 0;
  char resources =0;
  int resources_amount = 0;
//  int loc_x, loc_y = 0;
};
struct strength{
  int Box,Axe,Wood,Food,Stamina,Smoke=0;	
};

//void sethome(map *&a){
//	loc_x =0; loc_y=0; a->resources='H';
//}
void default_strength(strength *&s){
	s->Food=100; s->Stamina=100; s->Wood=100;
}
void generate_map(map *&a){
	int type;
	for (int i=0;i<MAPSIZE;i++){
		for (int j=0;j<MAPSIZE;j++){
			type = rand()%5;
			switch (type){
				case 1: a[i*MAPSIZE+j].resources='W';
				        a[i*MAPSIZE+j].resources_amount=(rand()%100+1);
				        break;
				case 2: a[i*MAPSIZE+j].resources='F';
				        a[i*MAPSIZE+j].resources_amount=(rand()%100+1);
				        break;
			}
		}
	}
	
}
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
		s->Stamina -= 2*(abs(0.5*(x-loc_x))+abs(0.5*(y-loc_y)));
		s->Stamina <= 0 ? s->Stamina=0: s->Stamina;
		loc_x = x; loc_y = y;
	}
}
void show_map(map *&a, strength *s){
	cout << " ";
	for (int k=0;k<MAPSIZE;k++) cout << setw(4) << k;
	cout << endl;
	for (int i=0;i<MAPSIZE;i++){
		cout << i;
		for (int j=0;j<MAPSIZE;j++){
			if (loc_x == i && loc_y == j) 
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
	cout << "Smoke(" << setfill(' ') << setw(4) <<  s->Smoke << ")  ";  
    
	cout << endl;   
	cout << "Input>  " ;
}

int main(){
  // mapping of 2D to 1D array
  // node[row][col] == node[row*MAPSIZE + col]
  map *node = new map[MAPSIZE*MAPSIZE]();
  //map *node = new map[MAPSIZE][MAPSIZE];
  strength *status = new strength();
 /*
  node[0].resources = 'W';
  node[0].resources_amount=0;
  node[1].resources = 'W';
  node[1].resources_amount=10;
  node[2].resources = 'F';
  node[2].resources_amount=20;
  node[3].resources = 'F';
  node[3].resources_amount=30;
  */
    //*node[] = {{'H',0},{'F',10},{'W',10},{'F',20}};
  bool win, quit = false;
  char input;
  int temp, required;
  generate_map(node);
 // sethome(node); 
  default_strength(status);
  while (!quit){
    show_map(node, status);	
    cin >> input;
    switch (input){
      case 'c': generate_map(node);
                break;
      case 'b': // build_box
                if (loc_x == 0 && loc_y == 0){ 
                    if (status->Wood < (wood2box + wood2box*status->Box)){
                    	cout << "Not enough Wood !!! " << endl; 
                    } else {
                    	status->Wood-=(wood2box + wood2box*status->Box);
                    	status->Box++;
                    }
                } else {
                	cout << "Not at Home !!! " << endl;
                }
	  			break;
	  case 'a': // build_axe
	            if (loc_x == 0 && loc_y == 0){ 
                    if (status->Wood < (wood2axe + wood2axe*status->Axe)){
                    	cout << "Not enough Wood !!! " << endl; 
                    } else {
                    	status->Wood-=(wood2axe + wood2axe*status->Axe);
                    	status->Axe++;
                    }
                } else {
                	cout << "Not at Home !!! " << endl;
                }
	  			break;
	  case 'n' : // navigate
	            navigate(status);
	  			break;
	  case 'g' : // gather
	            if (node[loc_x*MAPSIZE+loc_y].resources == 'F') {
	            	status->Food+=(node[loc_x*MAPSIZE+loc_y].resources_amount*(1+status->Axe/10)+(loc_x+loc_y)*(rand()%30));
	            } else if (node[loc_x*MAPSIZE+loc_y].resources == 'W') {
	            	status->Wood+=(node[loc_x*MAPSIZE+loc_y].resources_amount*(1+status->Axe/10)+(loc_x+loc_y)*(rand()%30));
	            } 
	  			break;
	  case 'w' : // burn_wood
	  			break;
	  case 'e' : // eat_food
	            if (status->Food > 0){
                    status->Food--;
					status->Stamina++;
					status->Stamina >= MAX_Stamina ? status->Stamina=MAX_Stamina: status->Stamina;	            	
	            } else {
	            	cout << "No more Food !!! " << endl;
	            }
				break;
	  case 'r' : // refresh_map
	            status->Food-=20;
	            status->Food <= 0 ? status->Food=0: status->Food;
	            cout << status->Food << endl;
	  			break;
	  case 'q' : // quit
	  			quit=true;	  			
	  			break;
	  default:  break;
    } // case loop
    if (status->Stamina <=0){
    	quit=true;
    	cout << "Quit with Stamina = 0 !!! " << endl;
    }
	    
  } // while loop
  
  delete [] node;
  delete [] status;
  return 0;
  
}
