<h1>⚪️SnackRun - Snake Game</h1>

<h2>🔴Overview</h2>

<br>SnackRun is a classic Snake Game developed in C++. The game features a snake that grows longer as it eats food, and the player must avoid running into the walls or its own body. It offers three difficulty levels: Easy, Medium, and Hard, where the speed of the game changes based on the difficulty selected.

<h2>🔴Features</h2>

<br>→Snake Movement: Control the snake using arrow keys (W, A, S, D) to move up, left, down, and right.
<br>→Food: The snake eats food represented by an apple (🍎), which increases its length and score.
<br>→Walls and Collision: If the snake runs into the walls or its own body, the game ends.
<br>→Difficulty Levels: Three difficulty levels are available, affecting the speed of the game.
<br>→Game Restart: After a game over, you can restart the game by pressing "R".

<h2>🔴Controls</h2>

<br>→W - Move Up
<br>→A - Move Left
<br>→S - Move Down
<br>→D - Move Right
<br>→X - Exit the Game
<br>→R - Restart the Game (after game over)

<h2>🔴How to Run</h2>

<br>→Clone or download the project files to your local machine.
<br>→Make sure you have a C++ compiler installed. This game requires the Windows console, so make sure you are working on a Windows environment.
<br>→Open the project in a C++ IDE or use the command line to compile the code.
<br>→Compile the game using a C++ compiler, such as g++, and run the executable.
<br>→Follow the on-screen instructions to start the game.
<br>→Example Compilation Command

<h2>🔴If you are using g++:</h2>

<br>g++ -o SnakeGame SnakeGame.cpp
<br>./SnakeGame

<h2>🔴Code Explanation</h2>

<br>👉SnakeGame Class
<br>  →The SnakeGame class contains the main game logic:
<br>→Game State: Manages the game state, including the snake's position, score, and the food's location.
<br>→Movement: Updates the snake's position based on user input.
<br>→Food Generation: Randomly generates food on the grid.
<br>→Collision Detection: Checks if the snake collides with walls or itself.

<br>👉SnackRun Class
<br>→The SnackRun class inherits from SnakeGame and adds user input handling and game loop functionality:
<br>Input Handling: Captures user input to control the snake using the conio.h library (_kbhit() and _getch()).
<br>Game Loop: The run() method runs the game loop, continuously drawing the game, accepting input, and updating the game state until a game-over condition is met.
<br>Difficulty: The game speed is adjusted according to the difficulty level set by the player.

<br>👉Graphics:
<br>The game uses console-based graphics, represented by characters such as:
<br>🧱 for walls
<br>🐍 for the snake
<br>🍎 for food
<br>The game area is drawn in the console using simple ASCII-style graphics. The snake is made up of several body parts that move along the grid.

<br>👉Game Flow:

<br>The game starts with an empty grid, a snake at the center of the screen, and a food item placed randomly.
<br>The snake moves in the direction chosen by the player. Each time it eats food, it grows longer, and the score increases.
<br>If the snake collides with a wall or its own body, the game ends.
<br>After the game ends, the player can choose to restart or exit the game.

<br>👉Project Customization:
<br>You can modify and extend this project as follows:
<br>→Change the Grid Size: Modify the width and height when creating the SnackRun object to create larger or smaller playing areas.
<br>→Adjust Speed and Controls: If you prefer different keys or want to tweak the game's speed even further, you can modify the difficulty settings and input handling.
<br>→Change Graphics: You can modify the symbols used to represent the snake, food, and walls. For example, you could replace the snake with a different character or use different colors if you have advanced console handling.

<h2>🔴Customization</h2>

<br>👉You can adjust the following parameters:

<br>→Game Size: Modify the width and height when creating the SnackRun object to change the game's grid size.
<br>→Difficulty: Choose between easy, medium, or hard difficulty to change the game's speed.

<h1>🔴Known Issues</h1>

<br>→The game may not run on non-Windows systems due to the use of windows.h for console manipulation.
<br>→The speed may be too fast or too slow on certain systems.
