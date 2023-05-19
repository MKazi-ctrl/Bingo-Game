A2 Bingo Game

This project is a program that simulates a Bingo game. The game is played on a 5x5 grid, where each cell contains a number. The objective of the game is to mark specific patterns on the grid to win.

Features
The program reads a list of 25 integers from a file, representing the Bingo card.
The user is prompted to enter a seed value and a Bingo card file when running the program.
The program verifies the format and integrity of the input data.
The program generates a random sequence of numbers and presents them as "calls."
If a called number is present on the Bingo card, it is marked.
The program continuously updates the Bingo card and checks for winning conditions.
If a winning pattern is achieved, the program declares the user as the winner and exits.
Files
list.c and list.h:
These files contain the implementation and declaration of functions related to managing a list data structure used in the program.
The list data structure stores the called numbers and provides operations like adding items, checking for duplicates, and printing the list.
m.c:
This file contains the main program logic for the Bingo game.
It includes functions for verifying inputs, printing the Bingo card, checking for winning conditions, and marking called numbers on the card.
The main function initializes the game, reads user inputs, generates random calls, updates the Bingo card, and checks for winning conditions in a loop.
makefile:
This file provides rules for compiling the program using the cc compiler.
It includes rules for compiling the source files and linking them to create the final executable (A2).
The clean rule is provided to remove the compiled object files and the executable.
How to Run
To run the Bingo game program, follow these steps:

Ensure you have a C compiler installed on your system (e.g., GCC).
Compile the program by running the following command in the terminal:
make
Run the program with the seed value and the path to the Bingo card file as command-line arguments:
./A2 <seed> <cardFile>
<seed>: An integer value used to seed the random number generator.
<cardFile>: The path to a file containing 25 integers representing the Bingo card.
Follow the prompts and observe the output in the terminal.
To quit the program, press q followed by the Enter key.
Feel free to modify the program or experiment with different Bingo card files to explore different gameplay scenarios.

Note: Make sure to replace <seed> and <cardFile> with actual values when running the program.

Enjoy playing the Bingo game!

Please note that this explanation assumes the provided code functions correctly and accurately represents the intended Bingo game.


