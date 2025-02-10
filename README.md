<h1>SnackRun - Snake Game</h1>

<h2>Overview</h2>

<br>SnackRun is a classic Snake Game developed in C++. The game features a snake that grows longer as it eats food, and the player must avoid running into the walls or its own body. It offers three difficulty levels: Easy, Medium, and Hard, where the speed of the game changes based on the difficulty selected.

<h2>Features</h2>

Snake Movement: Control the snake using arrow keys (W, A, S, D) to move up, left, down, and right.
Food: The snake eats food represented by an apple (🍎), which increases its length and score.
Walls and Collision: If the snake runs into the walls or its own body, the game ends.
Difficulty Levels: Three difficulty levels are available, affecting the speed of the game.
Game Restart: After a game over, you can restart the game by pressing "R".
Controls

W - Move Up
A - Move Left
S - Move Down
D - Move Right
X - Exit the Game
R - Restart the Game (after game over)
How to Run

Clone or download the project files to your local machine.
Make sure you have a C++ compiler installed. This game requires the Windows console, so make sure you are working on a Windows environment.
Open the project in a C++ IDE or use the command line to compile the code.
Compile the game using a C++ compiler, such as g++, and run the executable.
Follow the on-screen instructions to start the game.
Example Compilation Command

If you are using g++:

g++ -o SnakeGame SnakeGame.cpp
./SnakeGame
Code Explanation

SnakeGame Class: Contains the core logic for the game, such as movement, food generation, and collision detection.
SnackRun Class: Inherits from the SnakeGame class, adds functionality for user input, game logic, and managing difficulty.
setDifficulty: Sets the game speed based on the selected difficulty level.
Input Handling: Uses conio.h to capture keyboard inputs during gameplay.
Graphics: Simple console graphics are used with symbols such as 🧱 for walls, 🐍 for the snake, and 🍎 for food.
Customization

You can adjust the following parameters:

Game Size: Modify the width and height when creating the SnackRun object to change the game's grid size.
Difficulty: Choose between easy, medium, or hard difficulty to change the game's speed.
Known Issues

The game may not run on non-Windows systems due to the use of windows.h for console manipulation.
The speed may be too fast or too slow on certain systems.
License

This project is open-source and free to use, modify, and distribute.

I hope this helps! Let me know if you need any adjustments to the readme.
