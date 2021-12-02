#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

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

void default_strength(strength *&s){
	s->Food=100; s->Stamina=100; s->Wood=100;s->loc_x=s->loc_y=0;
}
void generate_map(map *&a){
	int type;
	for (int i=1;i<MAPSIZE;i++){
		for (int j=1;j<MAPSIZE;j++){
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
void build_axe(strength *&status){
	if (status->loc_x == 0 && status->loc_y == 0){ 
        if (status->Wood < (wood2axe + wood2axe*status->Axe)){
           	cout << "Not enough Wood !!! " << endl; 
        } else {
           	status->Wood-=(wood2axe + wood2axe*status->Axe);
           	status->Axe++;
        }
    } else {
       	cout << "Not at Home !!! " << endl;
    }
}
void refresh_map(strength *&status, map *&node){
  if (status->loc_x == 0 && status->loc_y == 0 && status->Food >= 20){
        generate_map(node);
        status->Food-=20;
        status->Food <= 0 ? status->Food=0: status->Food;
        cout << status->Food << endl;

    } else {
       	cout << "Not at Home !!! " << endl;
    }

}
void eat_food(strength *&status){
	if (status->Food > 0){
        status->Food--;
	    status->Stamina++;
		status->Stamina >= MAX_Stamina ? status->Stamina=MAX_Stamina: status->Stamina;	            	
	} else {
	   	cout << "No more Food !!! " << endl;
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
		s->Stamina -= 2*(abs(0.5*(x-s->loc_x))+abs(0.5*(y-s->loc_y)));
		s->Stamina <= 0 ? s->Stamina=0: s->Stamina;
		s->loc_x = x; s->loc_y = y;
	}
}
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
	if (!input_correct_command){
    		cout << "Please type valid command. The command list can be displayed through input '?'" << endl;
  	}
  	input_correct_command = true;	
	cout << "'*' = You are here, 'H' = Home, 'W' = location of Woods, 'F' = location of food " <<endl;
	cout << "Input>  " ;
}

void gather(map *&node, strength *&status){
	if (node[status->loc_x*MAPSIZE+status->loc_y].resources == 'F') {
	   	status->Food += (node[status->loc_x*MAPSIZE+status->loc_y].resources_amount*(1+status->Axe/10)+(status->loc_x+status->loc_y)*(rand()%30));
	   	node[status->loc_x*MAPSIZE+status->loc_y].resources = ' ';
	   	node[status->loc_x*MAPSIZE+status->loc_y].resources_amount = 0;
	} else if (node[status->loc_x*MAPSIZE+status->loc_y].resources == 'W') {
	   	status->Wood += (node[status->loc_x*MAPSIZE+status->loc_y].resources_amount*(1+status->Axe/10)+(status->loc_x+status->loc_y)*(rand()%30));
	   	node[status->loc_x*MAPSIZE+status->loc_y].resources = ' ';
	   	node[status->loc_x*MAPSIZE+status->loc_y].resources_amount = 0;
	} 
}





void burn_wood(strength *&status, bool &quit){
	if (status->loc_x == 0 && status->loc_y == 0){
        if (status->Wood < (500)){
           	cout << "Not enough Wood !!! At least 500 Wood required" << endl;
        } else {
            int num_1;
            int num_2;
            if (status->Wood <= (1000))
            {
              srand(time(NULL));
              num_1 = rand() % 100;
              num_2 = rand() % 100;
            }
            else if (status->Wood <= (5000))
            {
              srand(time(NULL));
              num_1 = rand() % 10;
              num_2 = rand() % 10;
            }
            else if (status->Wood > (5000))
            {
              srand(time(NULL));
              num_1 = rand() % 2;
              num_2 = rand() % 2;
            }
            if (num_1 == num_2){
            cout << "Congratulation, you are rescued" << endl;
            quit=true;
            }
            else{
           	status->Wood = 0;
            cout << "Unfortunately, you are not rescued" << endl;
            }
           	status->Box++;
        }
    } else {
       	cout << "Not at Home !!! " << endl;
    }
}



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
	cout << "q ... quit" << endl;
	cout << setfill('=') << setw(70) << "=" << endl;
	cout << setfill(' ');	
}

void display_introduction (bool &newgame){
  cout << endl;
  cout << "You are on gets caught the plane in a storm and crashes into Ocean." << endl;
  cout << "You are only survivor and washes up on an uninhabited island. " << endl;
  cout << "You can collect food and wood in this uninhabited island. " << endl;
  cout << "You need to find sufficient food to sustain stamina" << endl;
  cout << "You also can built box and axe for collect more food and wood by using wood" << endl;
  cout << "In this game, you also need to try to signal a passing ship by burnt wood" << endl;
  cout << "The probability of rescue depend on the number of wood burnt" << endl;
  cout << "Tip: There are three level of probability of rescue." << endl;
  cout << "High: woods > 5000, Medium: 1000 < woods <=5000, low: 1000 <=woods" << endl;
  cout << "You can refresh the map by paying 20 Food" << endl;
  cout << "You can iuput '?' to obtain the command list" << endl;
  cout << "Good Luck!!!" << endl;
  cout << setfill('=') << setw(70) << "=" << endl;
  cout << setfill(' ');
  newgame = false;
}


int main(){
  // mapping of 2D to 1D array
  // node[row][col] == node[row*MAPSIZE + col]
  map *node = new map[MAPSIZE*MAPSIZE]();
  //map *node = new map[MAPSIZE][MAPSIZE];
  strength *status = new strength();
  bool win, quit = false;
  bool newgame = true;
  bool input_correct_command = true;
  char input;
  int temp, required;
  generate_map(node);
  default_strength(status);
if (newgame){
    display_introduction (newgame);
  }



  while (!quit){
    show_map(node, status,input_correct_command);	
    cin >> input;
    switch (input){
      case 'b': // build_box
                build_box(status);
                break;
	  case 'a': // build_axe
	            build_axe(status);
	  			break;
	  case 'n' : // navigate
	            navigate(status);
	  			break;
	  case 'g' : // gather
	            gather(node,status);
	  			break;
	  case 'w' : // burn_wood       //done
             		 burn_wood(status, quit);
	  			break;		    
	  case 'e' : // eat_food
	            eat_food(status);
				break;
	  case 'r' : // refresh_map
	            refresh_map(status, node);
	  			break;
	  case 'q' : // quit
	  			quit=true;	  			
	  			break;
	  case '?': display_help();
	            break;
	  default:
             	 input_correct_command = false;
		    break;
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
