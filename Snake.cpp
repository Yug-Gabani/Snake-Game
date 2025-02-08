#include <iostream>
#include <vector>
#include <conio.h>  
#include <cstdlib>  
#include <ctime>   
#include <windows.h> 

using namespace std;


enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };


void setCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


void showCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = true; 
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

class SnakeGame {
protected:
    int width, height;
    bool gameOver;
    int x, y; 
    int foodX, foodY;
    int score;
    Direction dir;
    vector<pair<int, int>> snakeBody; 

public:
    SnakeGame(int w, int h) : width(w), height(h), gameOver(false), score(0), dir(STOP) {
        x = width / 2;
        y = height / 2;
        generateFood();
        snakeBody.push_back({x, y});
    }

    void generateFood() {
        foodX = rand() % width;
        foodY = rand() % height;
    }

    void draw() {
        setCursorPosition(0, 0);

        
        for (int i = 0; i < width + 2; ++i) cout << "🧱";
        cout << endl;

        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width + 2; ++j) {
                if (j == 0 || j == width + 1) {
                    cout << "🧱"; 
                } else if (i == y && j == x + 1) {
                    cout << "🐲"; 
                } else if (i == foodY && j == foodX + 1) {
                    cout << "🍎"; 
                } else {
                    bool isBody = false;
                    for (const auto& bodyPart : snakeBody) {
                        if (bodyPart.first == j - 1 && bodyPart.second == i) {
                            cout << "🐍";
                            isBody = true;
                            break;
                        }
                    }
                    if (!isBody) cout << "  "; 
                }
            }
            cout << endl;
        }

        
        for (int i = 0; i < width + 2; ++i) cout << "🧱";
        cout << "\nScore: " << score << endl;
    }
};

class snackrun : public SnakeGame {
public:
    snackrun(int w, int h) : SnakeGame(w, h) {} 

    void input() {
        if (_kbhit()) { 
            switch (_getch()) {
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

            
            if (dir == STOP) dir = RIGHT; 
        }
    }

    void logic() {
        pair<int, int> prevHead = {x, y};
        switch (dir) {
        case LEFT:  --x; break;
        case RIGHT: ++x; break;
        case UP:    --y; break;
        case DOWN:  ++y; break;
        default:    break;
        }

        if (x < 0 || x >= width || y < 0 || y >= height) {
            gameOver = true;
            return;
        }

        for (const auto& bodyPart : snakeBody) {
            if (bodyPart.first == x && bodyPart.second == y) {
                gameOver = true;
                return;
            }
        }

        snakeBody.push_back(prevHead);

        if (x == foodX && y == foodY) {
            score += 10;
            generateFood();
        } else {
            snakeBody.erase(snakeBody.begin());
        }
    }

    void run() {
        hideCursor();
        while (!gameOver) {
            draw();
            input();
            if (dir != STOP) logic(); 
            Sleep(100); 
        }
        showCursor(); 
        cout << "Game Over! Final Score: " << score << endl;
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    srand(static_cast<unsigned>(time(0))); 
    snackrun game(25, 25); 
    game.run();
    return 0;
}
