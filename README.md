<h1>🔴 Snake Game :</h1>

This is a simple implementation of the classic Snake game using C++ and console graphics. The snake moves around the screen, eating food to grow longer, and the player must avoid crashing into the walls or the snake's own body.

<h1>🔴 Features :</h1>
<br>👉Classic Snake gameplay.
<br>👉Dynamic food generation.
<br>👉Score tracking.
<br>👉Game Over screen with final score.
<br>👉Customizable grid size.
<br>👉Snake and food displayed using emojis (🧱, 🐲, 🐍, 🍎).

<h1>🔴 Requirements</h1>
To run the game, you'll need
<br>👉A C++ compiler (e.g., GCC or MSVC).
<br>👉Windows operating system for the console-based UI (uses Windows-specific libraries like windows.h).
<br>👉An IDE or text editor like Visual Studio or Code::Blocks.

<h1>🔴Installation</h1>

<br>1.Clone or download the repository to your local machine.
<br>2.Open the project in your preferred C++ IDE or editor.
<br>3.Compile the code using your C++ compiler.

<h1>🔴Usage</h1>
<br>To play the game, follow these steps:
<br>1.Compile the SnakeGame.cpp file.
<br>2.Run the compiled program.
<h2>⛔️Controls:</h2>
<br>👉Use W to move UP.
<br>👉Use A to move LEFT.
<br>👉Use S to move DOWN.
<br>👉Use D to move RIGHT.
<br>👉Press X to quit the game.

<h1>🔴How the Game Works</h1>
<br>👉The snake starts at the center of the grid.
<br>👉Food (🍎) randomly appears on the grid, and the snake needs to "eat" it to grow.
<br>👉As the snake eats more food, its body length increases.
<br>👉The game ends when the snake collides with a wall or itself.

<h1>🔴Code Overview</h1>
<h2>⭕️Key Classes:</h2>
      <p>🟡SnakeGame: The base class responsible for managing the grid, food, score, and the snake.</p>
<br>🔺Functions:
generateFood(): Generates new food at a random position.
draw(): Draws the game grid, snake, and food.
snackrun: A derived class that handles game input, logic, and game loop.
Functions:
input(): Handles player input for controlling the snake.
logic(): Handles snake movement, collision detection, and growth.
run(): Starts and runs the game loop.
