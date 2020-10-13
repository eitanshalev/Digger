# Digger
Diggeris a strategic, maze-based video game. FIRST project,  Object Oriented Programming and Game Development course 2020. Advisors Dr. Michal Alhanaty ,By Eitan Shalev, Yona Harel. Jerusalem.

[![Final Video](Digger/DIGGER_GAME.gif)](https://www.youtube.com/watch?v=zQyBtQYChKc&t=8s&ab_channel=%D7%90%D7%99%D7%AA%D7%9F%D7%A9%D7%9C%D7%95)
Details about the project and functionality:
The project is based on the computer game DIGGER and therefore derived all the actions that the game presents (for example after each victory in the stage the player gets an extra 20 points, how the player walks, and his graphic form, etc ...) and therefore the rules of the game are derived from the original DIGGER eraser.
The project is based on the use of the C ++ programming language, as well as extensive use of the SFML graphic library that we studied this semester, we used it specifically to display images, animations, music, experience and user interface.)
How to use the steps Let's load from a file called board.txt which each step is separated by a space and above each step in this file there is the data of desire - amount of stones allowed to eat, time (there is a possibility of time being infinite - and here this option is set exactly ...) Dimensions Size and length of the game).
If the player runs out of life, he loses, receives his score and returns to MENU (to paint the highest score).
Lowers the amount of his score) to decide whether to play again or finish. The game does come to an end when the player reaches the last stage - the MASTER. In order to challenge the game, we created 2 types of monsters whose function is to prevent the player from passing a stage and thus progress towards victory.

We will now present the list of game files (including class roles):
1.menu - Its role is to manage the game, depending on the user input. Contains the game menu.
MENU options: New game, increase or decrease the game according to user requirements, exit the game.
2.CONTROLLER- Manages each and every step according to the data. He actually runs the game, called what MENU; Receives from the BOARD department the game data (amount of diamonds, gifts, monsters, immovable objects. Prints the course of the game and displays messages about winning or ending a game.
3.BOARD - Here is kept all the information about the characters and in general - all the objects about their location, their images, their size and more. Each object has a drawing function.
4. ENTITY: The classes derived from this class are:
-CREATURE The base class of each character in the game.
The classes that are derived (inherited) from it are:
A. DIGGER - The department that manages everything the main player has to perform
B. MONSTER The classes derived from it are:
B.1. SMARTMONSTER
B.2 EASTMONSTER
5.UNMOVABLE: The classes that are derived (inherited) from it are all the static objects in fact:
A. DIAMOND
B. ROCK
third. WALL
D. PRESENT - The base class of any non-moving object. The classes that are derived (inherited) from it are all types of gifts:
1.RUNPRESENT gift that gives extra time
2.LIVEPRESENT A gift that gives extra life
3.TIMEPRESRNT A gift that allows extra time for the game.
6.SQUARE -
7. RESOURCES - A static class that loads only once in each run all the necessary files (images, sound and fonts).



Data Structure:
Array of game squares - all desired resources std :: vector <Square> m_squares;
An array of = contains all the data in the std :: vector <std :: string> m_board;
An array that contains all the objects that do not move on the board except for gifts std :: vector <Object *> m_objects;
An array containing all the monsters std :: vector <Monster *> m_monsters;
An array containing all the gifts std :: vector <Present *> m_gifts;
Algorithms:
Displacement of monsters:
SMARTMONSTER:
Each monster calculates the relative distance from the digger and according to this knows which direction they are moving
The monsters check where the digger is, right left top down. And move in his direction (if possible)
All monsters move subtly to move the digger only when they are close to it. Once a monster sees that it is not approaching the player it improvises a random change of direction in one direction, and at a speed twice its normal speed, to try to get closer to the player from the next point it is at, and at a relatively high speed to correct the normal movement.
EASYMONSTER:
The compensators move in the game completely randomly.
The file - TXT.BOARD - The file of the game stages:
The step file / s is located in the Resources folder and is called board.txt, to add a new step (let's say it is built) you must add a row of settings that it contains above the step: 1. The step size
                                                                      2. The number of stones Digger can eat
                                                                       3. Maximum time to combine
 All steps are on one file
The program opens this file, skips spaces, reads the definition bar of the stage and reads its map.
Known bugs:
(Were - and corrected - after an entire game the player can eat a collected amount of stones).
Other notes:
Here it is important to note that we have added options that are not necessarily derived from the original game, such as:
1. The additional options of gifts (extra life, time or speed to allow escape from the various monsters.
2. 2 options to enlarge the game to full screen using the button located MENU (another way is that during the game you can also enlarge the screen using two buttons together: Ctrl + Enter).
3. The graphic background of the game is based on a random combination of at least three images that represent castle background items to enhance the user experience and add interest and difference between one game and another, (it was also possible to make a completely different background in the use of images These if we would like).
4. Every fixed number of seconds on the game screen is drawn a gift that the player can eat, otherwise it disappears.
5. During the game the player can press the Escape key to stop the game, and with the Y / N press can also exit or continue playing. In addition - in the last 15 seconds of the game - an alert of the clock appears (it turns red and 'vibrates' to transmit it to the player.
6. The movement of the actor and the monsters according to the gestures - is an animated movement.
7. Background music + sound according to what is going on in the current time game (according to the player's gestures (eating a gift / diamond or being injured by monsters)).
7. Three types of gifts;
