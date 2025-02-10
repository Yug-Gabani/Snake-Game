<h1>⚪️SnackRun - Snake Game</h1>

<h2>🔴Overview</h2>

<br>SnackRun is a classic Snake Game developed in C++. The game features a snake that grows longer as it eats food, and the player must avoid running into the walls or its own body. It offers three difficulty levels: Easy, Medium, and Hard, where the speed of the game changes based on the difficulty selected.

<h2>🔴Features</h2>

<br>Snake Movement: Control the snake using arrow keys (W, A, S, D) to move up, left, down, and right.
<br>Food: The snake eats food represented by an apple (🍎), which increases its length and score.
<br>Walls and Collision: If the snake runs into the walls or its own body, the game ends.
<br>Difficulty Levels: Three difficulty levels are available, affecting the speed of the game.
<br>Game Restart: After a game over, you can restart the game by pressing "R".

<h2>🔴Controls</h2>

<br>W - Move Up
<br>A - Move Left
<br>S - Move Down
<br>D - Move Right
<br>X - Exit the Game
<br>R - Restart the Game (after game over)

<h2>🔴How to Run</h2>

<br>Clone or download the project files to your local machine.
<br>Make sure you have a C++ compiler installed. This game requires the Windows console, so make sure you are working on a Windows environment.
<br>Open the project in a C++ IDE or use the command line to compile the code.
<br>Compile the game using a C++ compiler, such as g++, and run the executable.
<br>Follow the on-screen instructions to start the game.
<br>Example Compilation Command

<h2>🔴If you are using g++:</h2>

<br>g++ -o SnakeGame SnakeGame.cpp./SnakeGame

<h2>🔴Code Explanation</h2>

<br>SnakeGame Class: Contains the core logic for the game, such as movement, food generation, and collision detection.
<br>SnackRun Class: Inherits from the SnakeGame class, adds functionality for user input, game logic, and managing difficulty.
<br>setDifficulty: Sets the game speed based on the selected difficulty level.
<br>Input Handling: Uses conio.h to capture keyboard inputs during gameplay.
<br>Graphics: Simple console graphics are used with symbols such as 🧱 for walls, 🐍 for the snake, and 🍎 for food.

<h2>🔴Customization</h2>

<br>👉You can adjust the following parameters:

<br>Game Size: Modify the width and height when creating the SnackRun object to change the game's grid size.
Difficulty: Choose between easy, medium, or hard difficulty to change the game's speed.

<h1>Known Issues</h1>

<br>The game may not run on non-Windows systems due to the use of windows.h for console manipulation.
<br>The speed may be too fast or too slow on certain systems.
