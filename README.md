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



## Features






### 5. Program codes in multiple files

initiate_map: Locations of *Food* and *Wood*, amounts of *Food* and *Wood*, and paths are generated. 
walk: move the location of the player from one point to another
gather: It subtracts the amount of *Food* and *Wood* collected at each node. It also prompts the player to use *Axe*s can call the use_axe function below.
refresh: amounts of *Food* and *Wood* at each node is generated 
build_box: It subtracts an amount of *Wood* from the player’s storage and increases the number of *Box*es the player has
build_axe: It subtracts an amount of *Wood* from the player’s storage and increases the number of *Axe*s the player has
use_axe: It subtracts an amount of *Axe*s from the player’s *Axe*s storage and multiplies the amount of *Food* and *Wood* collected
burn_wood: It subtract an amount of *Wood* from the player’s storage and increases the height of the smoke
