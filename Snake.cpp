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
    int difficultySpeed;  
int maxscore;

public:
    SnakeGame(int w, int h) :maxscore(0), width(w), height(h), gameOver(false), score(0), dir(STOP), difficultySpeed(100) { 
        x = width / 2; 
        y = height / 2;
        generateFood();
        snakeBody.push_back({x, y}); 
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

  void generateFood() { //ensure food not generate on snake body
    bool overlap;
    do {
        overlap = false;
        foodX = rand() % width;
        foodY = rand() % height;

        for (const auto& bodyPart : snakeBody) {
            if (bodyPart.first == foodX && bodyPart.second == foodY) {
                overlap = true;
                break;
            }
        }
    } while (overlap); 
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
                    cout << "🐁"; 
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
        
        cout << "\nScore: " << (score < 10 ? "0" : "") << score << endl;  
        cout<<"MAXSCORE:"<<maxscore<<" "<<endl;
    }

    void resetGame() { 
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
        }

        if (dir == STOP) dir = RIGHT; 
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

        snakeBody.push_back({x, y});
    
        if (x == foodX && y == foodY) { 
            score += 1;  
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
            if(difference>5){ 
                difficultySpeed-=10;
                previousscore=score;
            } 
            
            Sleep(difficultySpeed); 
        }
        showCursor(); 
        if(score>=maxscore)maxscore=score;
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
