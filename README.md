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

## Installation
1. Clone the repository:
   git clone https://github.com/yourusername/tube-sorting-puzzle.git
