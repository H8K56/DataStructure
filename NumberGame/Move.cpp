#include "./Move.h"
#include "./Stack.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//New Game is left to do
//Undo and Redo is left to do (use a linked stack)

const int GRID_SIZE = 3;
const int TARGET_VALUE = 9;

Move::Move()
{
    row = 0;
    col = 0;
    numOfMoves = 0;
    difficulty = 0;
    size = GRID_SIZE;
}

void Move::Initialize()
{
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = rand() % 9 + 1;
        }
    }
}

void Move::SetDifficulty(int difficulty)
{
    this->difficulty = difficulty;

    switch (this->difficulty)
    {
    case 1:
        this->numOfMoves = 10;
        break;
    case 2:
        this->numOfMoves = 8;
        break;
    case 3:
        this->numOfMoves = 7;
        break;
    case 4:
        this->numOfMoves = 6;
        break;
    case 5:
        this->numOfMoves = 5;
        break;
    case 6:
        this->numOfMoves = 4;
        break;
    case 7:
        this->numOfMoves = 3;
        break;
    case 8:
        this->numOfMoves = 2;
        break;
    case 9:
        this->numOfMoves = 1;
        break;
    default:
        break;
    }
}

int Move::GetNumOfMoves() const
{
    return this->numOfMoves;
}


void Move::DisplayGrid() const
{
    cout << "Number of moves left: " << numOfMoves << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void Move::SetMove(int row, int col)
{
    this->row = row;
    this->col = col;
    for (int i = 0; i < size; ++i)
    {
        if(i != col)
        {
            grid[i][col] = (grid[i][col] == 1) ? TARGET_VALUE : ++grid[i][col];
        }
        if (i != row)
        {
            grid[row][i] = (grid[row][i] == 1) ? TARGET_VALUE : ++grid[row][i];
        }
    }

    grid[row][col] = (grid[row][col] == 1) ? TARGET_VALUE :++grid[row][col];

    this->numOfMoves--;
}

void Move::GamePlay()
{
    int row, col;
    cout << "Enter the row: ";
    cin >> row;
    cout << "\n Enter the column: ";
    cin >> col;
    
    SetMove(row, col);

    DisplayGrid();

    if (CheckWinStatus() && numOfMoves > 0)
    {
        cout << "Congratulations! You've won the game!" << endl;
        return;
    }else if (numOfMoves == 0)
    {
        cout << "You've run out of moves! Game over!" << endl;
        return;
    }
}

bool Move::CheckWinStatus() const
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (grid[i][j] != TARGET_VALUE)
            {
                return false;
            }
        }
    }
    return true;
}

void Move::GameLogic() const
{
    cout << "The objective of the game is to make all the numbers in the grid equal to 9." << endl;
    cout << "You can do this by selecting a row and column, which will increment all the numbers in that row and column by 1." << endl;
    cout << "You have a limited number of moves to complete the game." << endl;
    cout << "Good luck!" << endl;
}

void Move::Undo()
{
    cout << "Undoing the last move..." << endl;

    

    this->numOfMoves++;
}

void Move::Redo()
{
    cout << "Redoing the last move..." << endl;

    

    this->numOfMoves++;
}