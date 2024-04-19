#include "../../DataStructure/NumberGame/Move.h"
#include "../../DataStructure/NumberGame/Stack.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

const int GRID_SIZE = 3;
const int TARGET_VALUE = 9;
Stack undoStack, redoStack;
Position currentPos;

Move::Move() : row(0), col(0), numOfMoves(0), difficulty(0), size(GRID_SIZE) { Initialize(); }

void Move::Initialize()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = TARGET_VALUE;
        }
    }
}

void Move::NewGame()
{
    srand(time(0));
    int count = GetNumOfMoves();

    while (count > 0)
    {
        int randomRow = rand() % size;
        int randomCol = rand() % size;

        ReverseGrid(randomRow, randomCol);
        count--;
    }
}

void Move::ReverseGrid(int row, int col)
{
    for (int i = 0; i < size; ++i)
    {
        if (i != col && i != row)
        {
            grid[i][col] = (grid[i][col] == 1) ? TARGET_VALUE : --grid[i][col];
        }
        if (i != row && i != col)
        {
            grid[row][i] = (grid[row][i] == 1) ? TARGET_VALUE : --grid[row][i];
        }
    }

    grid[row][col] = (grid[row][col] == 1) ? TARGET_VALUE : --grid[row][col];
}

void Move::SetDifficulty(int difficulty)
{
    this->difficulty = difficulty;

    switch (this->difficulty)
    {
    case 1:
        this->numOfMoves = 1;
        break;
    case 2:
        this->numOfMoves = 2;
        break;
    case 3:
        this->numOfMoves = 3;
        break;
    case 4:
        this->numOfMoves = 4;
        break;
    case 5:
        this->numOfMoves = 5;
        break;
    case 6:
        this->numOfMoves = 6;
        break;
    case 7:
        this->numOfMoves = 7;
        break;
    case 8:
        this->numOfMoves = 8;
        break;
    case 9:
        this->numOfMoves = 10;
        break;
    default:
        break;
    }
}

int Move::GetNumOfMoves()
{
    return this->numOfMoves;
}

void Move::DisplayGrid()
{
    cout << "Number of moves left: " << GetNumOfMoves() << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(2) << grid[i][j] << " | ";
        }
        cout << endl;
        if (i != size - 1)
        {
            for (int k = 0; k < size; k++)
            {
                cout << setw(2) << "----";
                if (k != size - 1)
                {
                    cout << "+";
                }
            }
            cout << endl;
        }
    }
}

void Move::SetMove(int r, int c)
{
    this->row = r;
    this->col = c;

    ApplyMove(r, c);

    currentPos.row = r;
    currentPos.col = c;

    PushMoveToUndoStack(currentPos);

    numOfMoves--;
}

void Move::ApplyMove(int row, int col)
{
    for (int i = 0; i < size; ++i)
    {
        if (i != col && i != row)
        {
            grid[i][col] = (grid[i][col] == TARGET_VALUE) ? 1 : ++grid[i][col];
        }
        if (i != row && i != col)
        {
            grid[row][i] = (grid[row][i] == TARGET_VALUE) ? 1 : ++grid[row][i];
        }
    }

    grid[row][col] = (grid[row][col] == TARGET_VALUE) ? 1 : ++grid[row][col];
}

void Move::GameOptions(int choice)
{
    switch (choice)
    {
    case 1:
        Undo();
        DisplayGrid();
        break;
    case 2:
        Redo();
        DisplayGrid();
        break;
    case 3:
        GameLogic();
        GameOptions(5);
        DisplayGrid();
        break;
    case 4:
        cout << "Exiting game..." << endl;
        exit(0); // Exit the game
        break;
    case 5:
        break;
    default:
        cout << "Invalid choice! Please choose a valid option." << endl;
        break;
    }
}

void Move::DisplayOptions()
{
    cout << "\nCurrent Position: "
         << "[" << row << ", " << col << "]" << endl;
    cout << "1. Undo" << endl;
    cout << "2. Redo" << endl;
    cout << "3. Game Logic" << endl;
    cout << "4. Exit" << endl;
    cout << "5. Continue" << endl;
    cout << "Enter your choice: ";
}

void Move::GamePlay()
{
    int difficulty;
    int choice;

    cout << "Choose a difficulty level between 1 (easy) and 9 (hard): ";
    cin >> difficulty;
    while (difficulty < 1 || difficulty > 9)
    {
        cout << "Invalid input. Please enter a number between 1 and 9: ";
        cin >> difficulty;
    }

    SetDifficulty(difficulty);

    NewGame();
    do
    {
        DisplayGrid();

        cout << "Enter row: ";
        cin >> this->row;
        while (this->row < 0 || this->row >= GRID_SIZE)
        {
            cout << "Invalid row. Please enter a number between 0 and " << GRID_SIZE - 1 << ": ";
            cin >> this->row;
        }

        cout << "Enter column: ";
        cin >> this->col;
        while (this->col < 0 || this->col >= GRID_SIZE)
        {
            cout << "Invalid column. Please enter a number between 0 and " << GRID_SIZE - 1 << ": ";
            cin >> this->col;
        }

        SetMove(this->row, this->col);
        DisplayGrid();

        if (CheckWinStatus())
        {
            cout << "Congratulations! You won the game!\n";
            break;
        }

        do
        {
            DisplayOptions();
            cin >> choice;
            while (choice < 1 || choice > 5)
            {
                cout << "Invalid choice. Please enter a number between 1 and 4: ";
                cin >> choice;
            }
            GameOptions(choice);
        } while (choice != 5);

    } while (choice != 6); // Continue until the user chooses to view game instructions
}

bool Move::CheckWinStatus()
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

void Move::GameLogic()
{
    cout << "The objective of the game is to make all the numbers in the grid equal to 9." << endl;
    cout << "You can do this by selecting a row and column, which will increment all the numbers in that row and column by 1." << endl;
    cout << "You have a limited number of moves to complete the game." << endl;
    cout << "Good luck!" << endl;
}

// Check this issue
void Move::Undo()
{
    Position lastMove;

    if (undoStack.empty())
    {
        cout << "No moves to undo!" << endl;
        return;
    }

    if (!undoStack.empty())
    {
        undoStack.top(lastMove);
        ReverseGrid(lastMove.row, lastMove.col);
        currentPos = lastMove;
        undoStack.pop();
        PushMoveToRedoStack(lastMove);
    }
}

void Move::Redo()
{
    Position lastMove;

    if (redoStack.empty())
    {
        cout << "No moves to redo!" << endl;
        return;
    }

    if (!redoStack.empty())
    {
        redoStack.top(lastMove);
        ApplyMove(lastMove.row, lastMove.col);
        currentPos = lastMove;
        redoStack.pop();
        PushMoveToUndoStack(lastMove);
    }
}

void Move::PushMoveToUndoStack(Position &undoPos)
{
    undoStack.push(undoPos);
}

void Move::PushMoveToRedoStack(Position &redoPos)
{
    redoStack.push(redoPos);
}