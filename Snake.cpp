#include <iostream>
#include <vector>
#include <conio.h>  //it has _khbit() to detect new input and continue previous input untill new input, _getch() to take input without enter
#include <cstdlib>  
#include <ctime>    
#include <windows.h> 

using namespace std;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN }; //enumaration for direction

void setCursorPosition(int x, int y) { // used to move cursor at given coordinate using coord it is part of <window.h>
    COORD coord; // to avoid flicker
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);//move at that point
}

void hideCursor() { // function is made to hide cursor whike showing boundary and snake units, all the element are built
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; 
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void showCursor() { // to show cursor when needed mostly at the end of game
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

class SnakeGame { // main logic
protected:
    int width, height; //all variable for gametrack,score,speed,snake body coordinate
    bool gameOver;
    int x, y; // snake head at initial stage
    int foodX, foodY; 
    int score;
    Direction dir;
    vector<pair<int, int>> snakeBody; 
    int difficultySpeed;

public:
    SnakeGame(int w, int h) : width(w), height(h), gameOver(false), score(0), dir(STOP), difficultySpeed(100) { //initial value assigned
        x = width / 2; //everytime snake starts from middle 
        y = height / 2;
        generateFood();
        snakeBody.push_back({x, y}); //inital 3 unit body 
        snakeBody.push_back({x-1, y}); 
        snakeBody.push_back({x-2, y}); 
    }

    void setDifficulty(int level) {
        switch(level) {
            case 1: difficultySpeed = 150; break; 
            case 2: difficultySpeed = 100; break; 
            case 3: difficultySpeed = 50; break; 
            default: difficultySpeed = 100; break; 
        }
    }

    void generateFood() {
        foodX = rand() % width;  //modulo because to take the random number  genrated into the range of grid
        foodY = rand() % height;
    }

    void draw() {
        setCursorPosition(0, 0);
        
        for (int i = 0; i < width + 2; ++i) cout << "🧱"; // +2 because boundary is for snake wall is just touching to show the boundary
        cout << endl;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width + 2; ++j) {
                if (j == 0 || j == width + 1) {
                    cout << "🧱"; //left and right borders
                } else if (i == y && j == x + 1) {
                    cout << "🐲"; //snake's head
                } else if (i == foodY && j == foodX + 1) {
                    cout << "🍎"; //food
                } else {
                    bool isBody = false;
                    for (const auto& bodyPart : snakeBody) {
                        if (bodyPart.first == j - 1 && bodyPart.second == i) {
                            cout << "🐍"; //snake's body
                            isBody = true;
                            break;
                        }
                    }
                    if (!isBody) cout << "  "; // empty space
                }
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; ++i) cout << "🧱"; // print the bottom of the border
        
        cout << "\nScore: " << (score < 10 ? "0" : "") << score << endl;  //display score
    }

    void resetGame() { // default value assigned to each parameter
        gameOver = false;
        score = 0;
        x = width / 2;
        y = height / 2;
        dir = STOP;
        snakeBody.clear();
        snakeBody.push_back({x, y});
        snakeBody.push_back({x-1, y});
        snakeBody.push_back({x-2, y});
        generateFood();
    }
};

class SnackRun : public SnakeGame {
public:
    SnackRun(int w, int h) : SnakeGame(w, h) {} 

    void input() {
        if (_kbhit()) {   // to detect the input by user 
            switch (_getch()) { //detect that input and changes direction according 
            case 'a':
                if (dir != RIGHT) dir = LEFT;
                break;
            case 'd':
                if (dir != LEFT) dir = RIGHT;
                break;
            case 'w':
                if (dir != DOWN) dir = UP;
                break;
            case 's':
                if (dir != UP) dir = DOWN;
                break;
            case 'x':
                gameOver = true; 
                break;
            }
        }

        if (dir == STOP) dir = RIGHT; 
    }

    void logic() {
        pair<int, int> prevHead = {x, y};
        
        // Move the snake's head according input direction
        switch (dir) {
            case LEFT:  --x; break;
            case RIGHT: ++x; break;
            case UP:    --y; break; //-- because as per computer coordinate system y-- than point moves up
            case DOWN:  ++y; break; // vice versa
            default:    break;
        }

        if (x < 0 || x >= width || y < 0 || y >= height) { //game gets over when snake touches boundary
            gameOver = true;
            return;
        }

        for (const auto& bodyPart : snakeBody) {
            if (bodyPart.first == x && bodyPart.second == y) {
                gameOver = true;
                return;
            }
        }

        snakeBody.push_back({x, y});
    
        if (x == foodX && y == foodY) {
            score += 10;  // Increase score by 1
            generateFood();
        } else {
            snakeBody.erase(snakeBody.begin());
        }
    }

    void run() {
        hideCursor();
        int difference=0;
        int previousscore=0;
        while (!gameOver) {
            draw();
            input();
            if (dir != STOP) logic();
            difference=score-previousscore;
            if(difference>5){ //at each inrease of 5 score speed of snake increase
                difficultySpeed-=15;
                previousscore=score;
            } 
            
            Sleep(difficultySpeed); 
        }
        showCursor();
        cout << "Game Over! Final Score: " << score << endl;

        char choice;
        cout << "Press 'R' to restart or any other key to exit: ";
        cin >> choice;
        if (choice == 'R' || choice == 'r') {
            resetGame(); 
            run(); 
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned>(time(0))); 
    string s;
    cout<<"Enter the name of the player:"<<endl;
    cin>>s;

    int difficulty;
    cout << "Choose difficulty level (1: Easy, 2: Medium, 3: Hard): ";
    cin >> difficulty;

    SnackRun game(25, 25); 
    game.setDifficulty(difficulty); 
    game.run();
    cout<<"Thanks "<<s<<" for playing"<<endl;
    return 0;
}
