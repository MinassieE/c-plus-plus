hello, this is a c++ project.
i do this for a school assingment when i was learning programming fundamentals in c++.

it is a console app, but it used the boring black and white console display as a gui to run the game.

NB: this program will work on windows, because i used a window specific header "conio.h" and command to clear the window "system("cls").
if you manage to change this two things to whatever OS you are using every thing should be fine. i guess :)

this program uses 4 functions 
1. setup()
2. draw()
3. logic()
4. input()

the setup() function will set the initial values and position of the snake head.

draw() function is responsible for displaying to the console the borders, the fruits, and the snake it self to the console.

input() function is what sets the direction of the snake based on what key the user pressed.

and finally logic() function will be resposible to change the actual pixel size stored based on the direction set by the input function. which will be then drawn or displayed to the console by draw() function.

this game depends on a singel while loop as a game engine, which uses a boolian condion variable called gameover, which will be set to false as soon us the head of the snake riches the border/wall/ or touches it's own tail.
