# comp2113_survival_island
This is the Project of COMP2113. This file contains team information, game description, game rules and game features. 

### Team Information
Team number: 128
Team members:
1. Chow Cheuk Ying | UID: 3035565140  | BEng(CivE) Year 4
2. Cheung Wang     | UID: 3035570949  | BEng(CivE) Year 4

## 1. Description
Our text-based game is a single-player game called *Survival Island*. The primary actions of the player are to *Gather* *Food* and *Wood*. The player wins the game by successfully leaving the Island. 

### 1.1. Background 
The player is stranded on a deserted island. To survive, the player needs to find *Food* on the island; to win the game, the player needs to *gather* enough *Wood* and *Burn* them to produce smoke which acts as a distress signal. The more the *Wood* *burn*t, the higher the smoke reaches, and thus the larger the probability is for the player to be seen and rescued by ships passing nearby. 

## 2. General game mechanism
When the game starts, the player is at *Home* and has 100/100 *Stamina* and 100 *Food* units. A 2-D map showing the player’s position and the locations *Food* and *Wood* on the island are displayed, while the amounts are only shown when the player reaches their locations. The player can *Navigate* through the map to nodes with *Food* and *Wood* to *Gather* these resources. To  increase the amount of resources that can be carried per trip, the player can *Build* wooden *Boxes*. The player can also *Make* *Axes* and spend them to multiply resources when *Gather*ing them. 

When the accumulated amount of *Wood* reaches a threshold,at least 500 *Wood*, the player can start *Build*ing a distress signal by *Burn*ing *Wood*. To replenish the resources on the map and the player’s *Stamina*, the player can donate 20 *Food* to refresh the map, which is equivalent to getting sleep and starting a new day, such that new amounts of resources are generated at each resource node. 

### 2.1. Rules
1. The maximum *Stamina* is 100. When *Stamina* is smaller or equal to 0. The player loses and the game ends. 
2. All actions, including *Navigate*, *Gather* and *Burn* all consumes *Stamina*. *Eat*ing *Food* increases *Stamina*. 
3. The amount of *Food* and *Wood* is only shown when the player reaches the node. 
4. The player can *Navigate* to locations with *Food* to *Gather* *Food*. 
5. The player can *Navigate* to locations with *Wood* to *Gather* *Wood*. 
6. With each trip, the player can only carry a certain amount of resources. 
7. *Wood* can be used to *Build* *Box*es. *Box*es increases the amount of resources that the player can carry each trip. *Box*es will not be consumed. 
8. *Wood* can be used to *Build* *Axe*s. *Axe*s increases the amount of resources available at each node. *Axe*s are consumed each time they are used. 
9. *Wood* can be *Burn*t to *Build* a distress signal. The more the *Wood* used, the higher the smoke reaches, the higher the probability the player will be noticed and rescued by passing ships. 
10. Probability of rescued: High: woods > 5000, Medium: 1000 < woods <=5000, low: 1000 <=woods
11. The player wins when the player is noticed and rescued by passing ships. 
12. The amounts of *Food* and *Wood* at each node can be *Refresh*ed by donating 20 *Food*. 
13. The player can only *Build* *Box*es and *Axe*s and *Burn* *Wood* when the player is at *Home*.  *Navigate*, *Eat*, *Gather* can be done at all nodes. 

### 2.2. Exchange rates
1. 1 *Stamina* = 1 *Food* 
2. 1 (*Stamina* consumed) = 2 * (length of path)
3. 1 wooden *Box* = [50 + 50 * (number of wooden *Box* the player has)] *Wood* 
4. 1 *Axe* = [30 + 30 * (number of *Axe*s the player has)] *Wood* 
5. 1 *Refresh* = 20 *Food*


### 2.3. Details of actions available for the player

1. *Navigate*: 
A certain amount of *Stamina* is consumed when the player *Navigate*s around the Island. The amount consumed is proportional to the length of the path. The *Stamina* consumed is given by the following equation. 
> (*Stamina* consumed) = 2 * (total length of path)

2. *Gather*:
A certain amount of *Stamina* is used when *Gather*ing the *Food* and *Wood*. The amounts of *Food* and *Wood* *Gather*ed are stored in two integer variables respectively. 

On the other hand, the farther the location of resource away from *Home* is higher opportunity to *Gather* more resources. As luck is a part of *Gather*ing resources, the maximum *Gather*ing multiplied by a random number is drawn. Moverover, the axe can be used to *Gather* more resources at each time and is given by the following equation.
> The maximum *Gathering* = (the amount of the *Food* and *Wood*) * (1 + (number of axe) / 10) + (total distance between *Home* and location) * (random number)

4. *Refresh*
The player can donate 20 *Food* to refresh the map and store it as an integer variable. 

5. *Build box*
The player can use *Wood* to upgrade the level of the *Box*. The higher level of the *Box* requires more *Wood*. The *Wood* required to upgrade the *Box* of different levels stored as an integer variable and is given by the following equation.
> Amount of *Wood* required = 50 + 50 * (number of *Box*es the player has)

6. *Build axe*
The player can use *Wood* to *Build* *Axe*s. *Build*ing each marginal *Axe* requires more *Wood*. The amount of *Wood* required to *build* each marginal *Axe* are calculated by the following equation.
> Amount of *Wood* required = 30 + 30 * (number of *Axe*s the player has) 

7. *Burn*
The player can *Burn* *Wood* to produce a distress signal. A boolean variable stores a value that indicates whether the player is successfully rescued or not.

9.*Save the progress*
The player may not finised the game at once. They can save their progress in the games through set their own username.

9.*Input the progress*
The player can countinue their games at the saving point through recall their username. The saving point will be changed if they save their new progress.

## 3. Features
Features 1-5 are described below. 

### 3.1. Generation of random game events
There are three major randomly generated elements involved in this game. 

First of all, the locations of the *Food* and *Wood* are randomly generated for every new game. Therefore, the paths will be randomly generated to connect *Home* and the location of the resources.  

Second, the amounts of *Food* and *Wood* at each location are randomly generated every time the map refreshes.
Third, the chance of being rescued is random to a certain extent. The probability of the smoke being noticed by ships passing nearby is dependent on the height of the smoke (with a larger smoke height having a larger possibility), but a certain level of randomness is present when determining whether the smoke is noticed. 

The mechanism for determining whether the player is rescued is as follows. The player is rescued if the two randomly generated numbers are the same. The range of numbers of which the two random integer reside in differs with the amount of *Wood* *Burn*t. The larger the amount of *Wood* used, the higher the smoke, the smaller the range. The smaller the range, the larger the probability for the two integers to be equal. This means *Burn*ing more *Wood* results in a larger probability to be rescued. The range of randomly generated values can be determined by following the equation. 
>  (Range of values) = 1000 - 10 * amount of *Wood* *Burn*t

The computer will randomly draw an integer twice within the same range. The two numbers are then stored in an integer array. If the two randomly generated numbers are the same, the player is rescued. 


### 3.2. Data structures for storing game status

#### A. Deserted Island Map

All locations and marks on the desert island map are stored in a 2D character array. The path is indicated with “-” and “l”; the location of *Home*, *Food* and *Wood* are represented by “H”, "F" and "W'' respectively. This information is stored in a 2-D character array.

#### B. Amount of resources
The quantities of *Food* and *Wood* at each location is randomly selected within the range 5-30. When the map is refreshed, the amount of *Food* and *Wood* in each location will be randomly generated again. The quantities are stored in a 2D array, where the rows and columns gives the location of the *Food* or *Wood* and the numbers stored in each cell represents the amount of *Food* or *Wood* present at that particular location. 

#### C. Player's status
1. Base storage capacity of resources

Storage capacity of *Food* and *Wood* at *Home* is fixed. Base storage capacity of *Food* and *Wood* during a trip is fixed. The quantities are stored in two 1D integer arrays. 

2. *Stamina*

The player's *Stamina* value ranges from 0 to 100. It is stored in an integer variable.

3. Number of *Axe*s

Players can make *Axe*s to multiply the amount of *Wood* and *Food* collected each time. The number of the *Axe*s ranges from 0 to 10 and is stored in an integer variable. 

4. Number of *Box*es

Players can make *Box*es to increase the total capacity they carry. It will multiply the 1D integer array storing the base storage capacity of the player during a trip. The number of the wooden *Box* ranges from 0 to 10 and is stored in an integer variable. 

5. Location of player

"\*" represents the current player's position. It is stored in a 1-D integer array; the first integer represents the row, the second number represents the column. 

6. Records of the height of the distress signal

The heights of the distress signal are recorded and stored in a dynamic 1-D double array. 


### 3.3. Dynamic memory management
The following data are stored dynamically during the execution of the program
1. Nodes of Map
2. Player's status
  2.1. Stamina
  2.2. Number of *Axe*s
  2.3. Number of *Box*es
  2.4. The location of player
  2.5. Number of *Food*
  2.6. Number of *Wood*

Although these information are stored in strength static struct, the status of the player will be changed and map will be generated a new one under the player's command. This means the the this data will be stored in a dynamic array. Once the data is out of scope, the memory will be allocated, declared and released. The player can save the games progress in the external text file permanently until they save the new progress in the same username.
 


### 3.4. File input/output
Only one file with the player's progress is stored, changed and read by the program. The [name_of_player].txt file is used to save the player’s status, where [name_of_player] is the name the player set for themselves at the beginning of the game, the map (including the paths and locations of resources) and the amount of resources at each location. The progress is saved every time the player exits the game. The player can return to the saved progress when the player continues the game. The file [name_of_player].txt will be read if the player chooses to continue his/her progress. The original progress will be overwritten when the player saves a new progress. 


### 3.5. Program codes in multiple files
1. main.cpp: this program include the main() of the program. 
2. display_help.cpp: this function display the Help message when "?" is inputted. 
3. display_introduction.cpp: this function display the introduction of the code. 
4. Makefile: The Makefile compile the programs and generate executables. 

## 4. Non-standard C/C++ library
No non-standard library is used in this program.


## 5. Compilation for the program
To compile the program, please follow the instructions below: 
1. Download the whole folder. 
2. Input "make main" to make the executable.
3. Input "./main" to run the excutable.
