//Chow Cheuk Ying | UID: 3035565140 | BEng(CivE) Year 4
//Cheung Wang | UID: 3035570949 | BEng(CivE) Year 4
//Description: Main program for starting the game.
// Last Changed: Ded 3, 2021

// "display_help.h" and "display_introduction.h" are others two proram about information of the games.
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include "display_help.h"
#include "display_introduction.h"
#include <time.h>
using namespace std;



// Define the gobel the variable, include the size of the island and the basics setting.
const int filenamesize=80;
const int MAPSIZE = 10;
const int MAX_Stamina = 100;
const int wood2box = 50;
const int wood2axe = 30;

// Storage the data about the resoures
// Achieved the Code Requirement Task 2: Data structures for storing game status
struct map{
char resources =0;
int resources_amount = 0;
};


// Storage the data about the players in the games
// Achieved the Code Requirement Task 2: Data structures for storing game status
struct strength{
  int Box,Axe,Wood,Food,Stamina,loc_x,loc_y=0;
};

//Function called when the status of players is changed in the games

void default_strength(strength *&s){
	s->Food=100; s->Stamina=100; s->Wood=100;s->loc_x=s->loc_y=0;
}



//Function called when the players start a new games or the want to explore the new map to generate a new map
// The location and total amount of resoures are random allocated.
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


//Function called when the players build the equirment to obtain more food in each gathered
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

//Function called when the players build the equirment to obtain more woods in each gathered
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

//Function called when the players want to explore the new map to generate a new map
//Function will also called generate_map function for generate a new map
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


//Function called when the players want to recover the Stamina by eating

void eat_food(strength *&status){
	if (status->Food > 0){
        status->Food--;
	    status->Stamina++;
		status->Stamina >= MAX_Stamina ? status->Stamina=MAX_Stamina: status->Stamina;
	} else {
	   	cout << "No more Food !!! " << endl;
	}
}

//Function called when the players move to other location
//Need to input the coordinate of the destination
//cosume the Stamina in each movement
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


//Function called when the program finished a command
//Show the location of the player and resoures
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


//Function called when the player gathered the food and woods
// The total amount of the food and woods collected will be randomly increasing if the player have boxes or axe.

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



//Function called when the player distress signal
//This is the only way to win this game
//The program will radomly generate two numbers.
// If the values of these two numbers are the same, player will win this games.
// Achieved the Code Requirement Task 1: Generation of random game sets or events


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
        }
    } else {
       	cout << "Not at Home !!! " << endl;
    }
}


//Function called when player choose to save the game
// Achieved the Code Requirement Task 4: File input/output (e.g., for loading/saving game status)

void save2file(string &ofile,map *&node, strength *&status){
	ofstream fout;
	fout.open(ofile,ios::ate);
	if (fout.fail()){
		cout << "Error in opening " << ofile << endl;
	} else {

	  fout<<status->Box<<" "<<status->Axe<<" "<<status->Wood<<" "<<status->Food<<" "<<status->Stamina<<" "<<status->loc_x<<" "<<status->loc_y<<endl;
      for (int i=0;i<MAPSIZE;i++){
		for (int j=0;j<MAPSIZE;j++){
			node[i*MAPSIZE+j].resources == ' ' ? fout << "* " : fout << node[i*MAPSIZE+j].resources << " ";
		}
		fout << endl;
	  }
	  for (int i=0;i<MAPSIZE;i++){
		for (int j=0;j<MAPSIZE;j++){
			fout << node[i*MAPSIZE+j].resources_amount << " " ;
		}
		fout << endl;
	  }
	  cout << "... " << ofile << " is saved. " << endl;
	  fout.close();
    }
    ofile.clear();
}


//Function is called when user want to load a previous saved game or save the game.
//Function will output the data in a text file.
// Achieved the Code Requirement Task 4: File input/output (e.g., for loading/saving game status)

void get_file(string &filename){
	string temp;
	cout << "Enter filename: " ;
	cin >> temp;
	filename = temp + ".txt";
	//cout << "Data will be saved to " << ofile << endl;
}


//Function is called when user want to load a previous saved game.
// Achieved the Code Requirement Task 4: File input/output (e.g., for loading/saving game status)

void file2map(string &ifile,map *&node, strength *&status){
    string line;
    char tempchar;
	ifstream fin;
	fin.open(ifile);
    if (fin.fail()) {
       cout << "Error in opening " << ifile << endl;
	} else {
		getline(fin, line);
		istringstream sdata(line);
		//Box,Axe,Wood,Food,Stamina,loc_x,loc_y=0;
		sdata>>status->Box>>status->Axe>>status->Wood>>status->Food>>status->Stamina>>status->loc_x>>status->loc_y;
		for (int i=0; i<MAPSIZE;i++){
            getline(fin, line);
			istringstream sdata(line);
			for (int j=0;j<MAPSIZE;j++){
			    sdata>>tempchar;
				tempchar =='*' ? node[i*MAPSIZE+j].resources = ' ' :  node[i*MAPSIZE+j].resources = tempchar ;
 		    }
		}
		for (int i=0; i<MAPSIZE;i++){
			getline(fin, line);
			istringstream sdata(line);
			for (int j=0;j<MAPSIZE;j++){
			    sdata>>node[i*MAPSIZE+j].resources_amount;
		    }
		}
		fin.close();
	}
	ifile.clear();
}




// The main function of the game
//The status of the player will be saved in dynamic struct
// Once the player quit, win or lose the game.
// The memory will be reallocated.
// Achieved the Code Requirement Task 3: Dynamic memory management


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
  string ifile,ofile,line;
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
	  case 's' : // save to a file
	            if(ofile.length()){
	            	save2file(ofile,node,status);
				} else {
					get_file(ofile);
					save2file(ofile,node,status);
				}
				break;
	  case 'i' : // input file
	            get_file(ifile);
	            file2map(ifile,node,status);
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
