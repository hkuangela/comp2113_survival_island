# comp2113_survival_island
This is the Project of COMP2113. This file contains team information, game description, game rules and game features. 

### Team Information
Team number: 128
Team members:
1. Chow Cheuk Ying | UID: 3035565140  | BEng(CivE) Year 4
2. Cheung Wang     | UID: 3035570949  | BEng(CivE) Year 4

## Description
Our text-based game is a single-player game called *Survival Island*. The primary actions of the player are to *Gather* *Food* and *Wood*. The player wins the game by successfully leaving the Island. 

### Background 
The player is stranded on a deserted island. To survive, the player needs to find *Food* on the island; to win the game, the player needs to *gather* enough *Wood* and *Burn* them to produce smoke which acts as a distress signal. The more the *Wood* *burn*t, the higher the smoke reaches, and thus the larger the probability is for the player to be seen and rescued by ships passing nearby. 

## General game mechanism
When the game starts, the player is at *Home* and has 100/100 *Stamina* and 50 *Food* units. A 2-D map showing the player’s position and the locations *Food* and *Wood* on the island are displayed, while the amounts are only shown when the player reaches their locations. The player can *Navigate* through the map to nodes with *Food* and *Wood* to *Gather* these resources. The player can then bring the *Gather*ed resources back *Home*. With each trip, the player can only carry a certain amount of resources. To  increase the amount of resources that can be carried per trip, the player can *Build* wooden *Boxes*. The player can also *Make* *Axes* and spend them to multiply resources when *Gather*ing them. 
When the accumulated amount of *Wood* reaches a threshold, the player can start *Build*ing a distress signal by *Burn*ing *Wood*. To replenish the resources on the map and the player’s *Stamina*, the player can donate 20 *Food* to refresh the map, which is equivalent to getting sleep and starting a new day, such that new amounts of resources are generated at each resource node. 

### Rules
The maximum *Stamina* is 100. When *Stamina* is smaller or equal to 0. The player loses and the game ends. 
All actions, including *Navigate*, *Gather* and *Burn* all consumes *Stamina*. *Eat*ing *Food* increases *Stamina*. 
The amount of *Food* and *Wood* is only shown when the player reaches the node. 
The player can *Navigate* to locations with *Food* to *Gather* *Food*. 
The player can *Navigate* to locations with *Wood* to *Gather* *Wood*. 
With each trip, the player can only carry a certain amount of resources. 
*Wood* can be used to *Build* *Box*es. *Box*es increases the amount of resources that the player can carry each trip. *Box*es will not be consumed. 
*Wood* can be used to *Build* *Axe*s. *Axe*s increases the amount of resources available at each node. *Axe*s are consumed each time they are used. 
*Wood* can be *Burn*t to *Build* a distress signal. The more the *Wood* used, the higher the smoke reaches, the higher the probability the player will be noticed and rescued by passing ships. 
The player wins when the player is noticed and rescued by passing ships. 
The amounts of *Food* and *Wood* at each node can be *Refresh*ed by donating 20 *Food*. 
The player can only *Build* *Box*es and *Axe*s and *Burn* *Wood* when the player is at *Home*.  *Navigate*, *Eat*, *Gather* can be done at all nodes. 

### Exchange rates
1 *Stamina* = 1 *Food* 
1 (*Stamina* consumed) = 2 /* (length of path)
1 wooden *Box* = [50 + 50 /* (number of wooden *Box* the player has)] *Wood* 
1 *Axe* = [30 + 30 /* (number of *Axe*s the player has)] *Wood* 
1 *Refresh* = 20 *Food*


### Details of actions available for the player

*Navigate*: 
A certain amount of *Stamina* is consumed when the player *Navigate*s around the Island. The amount consumed is proportional to the length of the path. The *Stamina* consumed is given by the following equation. 
> (*Stamina* consumed) = 2 /* (total length of path)

*Gather*:
A certain amount of *Stamina* is used when *Gather*ing the *Food* and *Wood*. The amounts of *Food* and *Wood* *Gather*ed are stored in two integer variables respectively. 

On the other hand, the farther the location of resource away from *Home* is higher opportunity to *Gather* more resources. As luck is a part of *Gather*ing resources, the maximum *Gather*ing multiplied by a random number is drawn. Moverover, the axe can be used to *Gather* more resources at each time and is given by the following equation.
> The maximum *Gathering* = (the amount of the *Food* and *Wood*) /* (1 + (number of axe) / 10) + (total distance between *Home* and location) /* (random number)

*Refresh*
The player can donate 20 *Food* to refresh the map and store it as an integer variable. 

*Build box*
The player can use *Wood* to upgrade the level of the *Box*. The higher level of the *Box* requires more *Wood*. The *Wood* required to upgrade the *Box* of different levels stored as an integer variable and is given by the following equation.
> Amount of *Wood* required = 50 + 50 /* (number of *Box*es the player has)

*Build axe*
The player can use *Wood* to *Build* *Axe*s. *Build*ing each marginal *Axe* requires more *Wood*. The amount of *Wood* required to *build* each marginal *Axe* are calculated by the following equation.
> Amount of *Wood* required = 30 + 30 /* (number of *Axe*s the player has)

*Use axe*
*Axe*s can only be used once. The number of *Axe*s stored as integer variable and used will be subtracted from the user’s storage once they are used.  

Burn
The player can *Burn* *Wood* to produce a distress signal. A boolean variable stores a value that indicates whether the player is successfully rescued or not. 


## Features
### 1. Generation of random game events
There are three major randomly generated elements involved in this game. 
First of all, the locations of the *Food* and *Wood* are randomly generated for every new game. Therefore, the paths will be randomly generated to connect *Home* and the location of the resources.  
Second, the amounts of *Food* and *Wood* at each location are randomly generated every time the map refreshes.
Third, the chance of being rescued is random to a certain extent. The probability of the smoke being noticed by ships passing nearby is dependent on the height of the smoke (with a larger smoke height having a larger possibility), but a certain level of randomness is present when determining whether the smoke is noticed. 
The mechanism for determining whether the player is rescued is as follows. The player is rescued if the two randomly generated numbers are the same. The range of numbers of which the two random integer reside in differs with the amount of *Wood* *Burn*t. The larger the amount of *Wood* used, the higher the smoke, the smaller the range. The smaller the range, the larger the probability for the two integers to be equal. This means *Burn*ing more *Wood* results in a larger probability to be rescued. The range of randomly generated values can be determined by following the equation. 
>  (Range of values) = 1000 - 10 /* amount of *Wood* *Burn*t

The computer will randomly draw an integer twice within the same range. The two numbers are then stored in an integer array. If the two randomly generated numbers are the same, the player is rescued. 


### 2. Data structures for storing game status

#### A. Deserted Island Map

All locations and marks on the desert island map are stored in a 2D character array. The path is indicated with “-” and “l”; the location of *Home*, *Food* and *Wood* are represented by “H”, "F" and "W'' respectively. This information is stored in a 2-D character array.

#### B. Amount of resources
The quantities of *Food* and *Wood* at each location is randomly selected within the range 5-30. When the map is refreshed, the amount of *Food* and *Wood* in each location will be randomly generated again. The quantities are stored in a 2D array, where the rows and columns gives the location of the *Food* or *Wood* and the numbers stored in each cell represents the amount of *Food* or *Wood* present at that particular location. 



#### C. Player's status
Base storage capacity of resources: Storage capacity of *Food* and *Wood* at *Home* is fixed. Base storage capacity of *Food* and *Wood* during a trip is fixed. The quantities are stored in two 1D integer arrays. 

*Stamina*: The player's *Stamina* value ranges from 0 to 100. It is stored in an integer variable.

Number of *Axe*s:  Players can make *Axe*s to multiply the amount of *Wood* and *Food* collected each time. The number of the *Axe*s ranges from 0 to 10 and is stored in an integer variable. 

Number of *Box*es:  Players can make *Box*es to increase the total capacity they carry. It will multiply the 1D integer array storing the base storage capacity of the player during a trip. The number of the wooden *Box* ranges from 0 to 10 and is stored in an integer variable. 

Location of player
"*" represents the current player's position. It is stored in a 1-D integer array; the first integer represents the row, the second number represents the column. 

Records of the height of the distress signal
The tallest 20 heights of the distress signal are recorded and stored in a 1-D double array. 


### 5. Program codes in multiple files

initiate_map: Locations of *Food* and *Wood*, amounts of *Food* and *Wood*, and paths are generated. 
walk: move the location of the player from one point to another
gather: It subtracts the amount of *Food* and *Wood* collected at each node. It also prompts the player to use *Axe*s can call the use_axe function below.
refresh: amounts of *Food* and *Wood* at each node is generated 
build_box: It subtracts an amount of *Wood* from the player’s storage and increases the number of *Box*es the player has
build_axe: It subtracts an amount of *Wood* from the player’s storage and increases the number of *Axe*s the player has
use_axe: It subtracts an amount of *Axe*s from the player’s *Axe*s storage and multiplies the amount of *Food* and *Wood* collected
burn_wood: It subtract an amount of *Wood* from the player’s storage and increases the height of the smoke
