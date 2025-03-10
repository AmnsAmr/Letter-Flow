# Tube Sorting Puzzle

Welcome to **Tube Sorting Puzzle**,a C++-based console game where you sort letters (or items) between tubes to achieve a winning state!
The goal is to make all non-empty tubes full and uniform (containing only one type of letter), using a limited set of moves. You can play manually or let an AI bot solve it for you.

## Features
- **Interactive Gameplay**: Create tubes, move letters manually, and solve the puzzle yourself.
- **AI Solver**: A breadth-first search (BFS) bot finds a solution or determines if none exists.
- **Customizable**: Set the number of full tubes, empty tubes, and tube capacity at startup.

## Gameplay
- **Setup**: Define how many full tubes (with letters), empty tubes, and the capacity of each tube.
- **Moves**: Transfer a letter from one tube to another if the destination is empty or its top letter matches.
- **Win Condition**: All non-empty tubes must be full (at capacity) and contain only one letter type (e.g., `[A,A,A,A]`, `[B,B,B,B]`).
- **Bot Option**: Stuck? Let the bot calculate the moves for you!

## Prerequisites
- **C++17 Compiler**: Required for structured bindings and modern STL features (e.g., g++, MSVC with C++17 enabled).
## Example
- Here’s an example of the game in action with 5 full tubes, 2 empty tubes, and a capacity of 8:

- | P | | P | | G | | G | | R | |   | |   |
| Y | | P | | K | | G | | G | |   | |   |
| R | | Y | | Y | | R | | K | |   | |   |
| P | | G | | K | | R | | G | |   | |   |
| G | | P | | R | | G | | K | |   | |   |
| Y | | P | | R | | Y | | P | |   | |   |
| Y | | R | | K | | K | | Y | |   | |   |
| R | | K | | K | | P | | Y | |   | |   |
|| || || || || || |___|
Try to solve the puzzle yourself! Enter 'solve' to use the bot, or 'quit' to exit.
Enter command (move/solve/quit): solve
Solvable! Moves:
0 -> 5
1 -> 5
1 -> 5
1 -> 0
1 -> 6
1 -> 5
1 -> 5
2 -> 6
3 -> 6
3 -> 6
1 -> 3
2 -> 1
4 -> 3
4 -> 6
4 -> 1
4 -> 6
4 -> 1
4 -> 5
0 -> 4
0 -> 4
2 -> 4
2 -> 1
0 -> 2
0 -> 5
0 -> 6
0 -> 4
0 -> 4
2 -> 0
2 -> 0
2 -> 0
2 -> 1
2 -> 1
3 -> 0
3 -> 0
3 -> 0
3 -> 0
3 -> 6
3 -> 4
3 -> 1
3 -> 5

  
In this example:
- **Initial State**: 5 tubes filled with mixed letters (P, Y, R, G, K) and 2 empty tubes.
- **User Action**: The user opts to use the bot immediately by typing `solve`.
- **Bot Output**: A sequence of moves (e.g., `0 -> 5` means move the top letter from tube 0 to tube 5) that solves the puzzle, resulting in all non-empty tubes being full and uniform.

## Installation
1. Clone the repository:
   git clone https://github.com/yourusername/tube-sorting-puzzle.git
