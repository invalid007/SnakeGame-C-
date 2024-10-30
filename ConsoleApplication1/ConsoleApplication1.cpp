#include <iostream>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <ctime> // for seeding rand

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    srand(time(0)); // seed rand
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    // Use SetConsoleCursorPosition to move the cursor to the top-left corner
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPos = { 0, 0 };
    SetConsoleCursorPosition(hConsole, cursorPos);

    // Use a string buffer to store the entire screen content
    std::ostringstream screenBuffer;

    // Top border
    for (int i = 0; i < width + 2; i++)
        screenBuffer << "#";
    screenBuffer << "\n";

    // Map and snake drawing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                screenBuffer << "#";

            if (i == y && j == x)
                screenBuffer << "O";  // Snake head
            else if (i == fruitY && j == fruitX)
                screenBuffer << "F";  // Fruit
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        screenBuffer << "o";  // Snake tail
                        print = true;
                        break;
                    }
                }
                if (!print)
                    screenBuffer << " ";
            }

            if (j == width - 1)
                screenBuffer << "#";
        }
        screenBuffer << "\n";
    }

    // Bottom border
    for (int i = 0; i < width + 2; i++)
        screenBuffer << "#";
    screenBuffer << "\n";

    // Score display
    screenBuffer << "Score: " << score << "\n";

    // Output the buffer to the console all at once
    std::cout << screenBuffer.str();  // Explicitly use std::cout here
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
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
}

void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    // Uncomment the following to check for boundary collision instead of wrapping:
    // if (x >= width || x < 0 || y >= height || y < 0)
    //     gameOver = true;

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100); // Control game speed
    }
    return 0;
}
