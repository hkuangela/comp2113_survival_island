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
#include "display_introduction.h"
using namespace std;


//Function called when the player start the games
// Provided basics information
// Achieved the Code Requirement Task 5: Program codes in multiple files
void display_introduction (bool &newgame){
  cout << endl;
  cout << "The plane you are on gets caught in a storm and crashes into ocean." << endl;
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
