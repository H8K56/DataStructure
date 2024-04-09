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

Move::Move() : row(0), col(0), numOfMoves(0), difficulty(0), size(GRID_SIZE) {}

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
        if (i != col)
        {
            grid[i][col] = (grid[i][col] == 1) ? TARGET_VALUE : --grid[i][col];
        }
        if (i != row)
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
    cout << "Number of moves left: " << numOfMoves << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << setw(3) << grid[i][j] << " | ";
        }
        cout << endl;
        if (i != size - 1)
        {
            for (int k = 0; k < size; k++)
            {
                cout << "----";
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
    row = r;
    col = c;

    PushMoveToUndoStack();

    ApplyMove(r, c);

    numOfMoves--;
}

void Move::ApplyMove(int row, int col)
{
    for (int i = 0; i < size; ++i)
    {
        if (i != col)
        {
            grid[i][col] = (grid[i][col] == 1) ? TARGET_VALUE : ++grid[i][col];
        }
        if (i != row)
        {
            grid[row][i] = (grid[row][i] == 1) ? TARGET_VALUE : ++grid[row][i];
        }
    }
    grid[row][col] = (grid[row][col] == 1) ? TARGET_VALUE : ++grid[row][col];
}

void Move::GameOptions(int choice) 
{
    cout << "1. Start a new game" << endl;
    cout << "2. Undo" << endl;
    cout << "3. Redo" << endl;
    cout << "4. View game instructions" << endl;
    switch (choice)
    {
    case 1:
        NewGame();
        break;
    case 2:
        Undo();
        break;
    case 3:
        Redo();
        break;
    case 4:
        GameLogic();
        break;
    default:
        break;
    }
}

void Move::GamePlay()
{
    int row, col, choice;
    char continueGame;

    do
    {
        NewGame();
        DisplayGrid();

        cout << "Options: ";
        cin >> choice;
        GameOptions(choice);

        cout << "\nChoose a difficulty level between (easy)1 and 9(hard): ";
        cout << "\nEnter the row: ";
        cin >> row;
        cout << "\n Enter the column: ";
        cin >> col;

        SetMove(row, col);

        DisplayGrid();

        if (CheckWinStatus() && numOfMoves > 0)
        {
            cout << "Congratulations! You've won the game!" << endl;
            return;
        }
        else
        {
            cout << "You lose! Good day person!" << endl;
            return;
        }

        if (numOfMoves == 0)
        {
            cout << "You've run out of moves! Game over!" << endl;
            return;
        }

        cout << "Do you want to continue playing? (Y/N): ";
        cin >> continueGame;
    } while (continueGame == 'Y' || continueGame == 'y');
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

void Move::Undo()
{
    Stack lastMove;
    errorCode result = undoStack.top(lastMove); // Get the top Stack from undoStack
    if (result == success) {
        undoStack.pop(); // Pop the top element
        redoStack.push(lastMove); // Push the last move to redoStack
        ApplyMove(lastMove.row, lastMove.col); // Apply the move
        numOfMoves++; // Increment the number of moves
    } else {
        cout << "Nothing to undo!" << endl; // Print error message
    }
}

void Move::Redo()
{
    Stack lastMove;
    errorCode result = redoStack.top(lastMove); // Get the top Stack from redoStack
    if (result == success) {
        redoStack.pop(); // Pop the top element
        undoStack.push(lastMove); // Push the last move to undoStack
        ApplyMove(lastMove.row, lastMove.col); // Apply the move
        numOfMoves--; // Decrement the number of moves
    } else {
        cout << "Nothing to redo!" << endl; // Print error message
    }
}

void Move::PushMoveToUndoStack()
{
    Stack move(row, col); // Create a Stack for the move
    undoStack.push(move); // Push the move to the undoStack
}
