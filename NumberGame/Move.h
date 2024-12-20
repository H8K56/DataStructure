#ifndef MOVE_H
#define MOVE_H

#include "../../DataStructure/NumberGame/Stack.h"

const int MAX = 3;
class Move
{
private:
    int row, col;
    int difficulty;
    int size;
    int numOfMoves;
    int grid[MAX][MAX];

public:
    // Constructor
    Move();

    // Initialization and game setup
    void Initialize();
    void NewGame();

    // Game actions
    void ReverseGrid(int row, int col);
    void PushMoveToUndoStack(Position &undo);
    void PushMoveToRedoStack(Position &redo);
    void SetMove(int row, int col);
    void ApplyMove(int row, int col);
    void Undo();
    void Redo();

    // Difficulty settings
    void SetDifficulty(int difficultyLevel);

    // Game status checks
    bool CheckWinStatus();
    

    // Getter
    int GetNumOfMoves();

    // Game logic and display
    void GameOptions(int choice);
    void GameLogic();
    void GamePlay();
    void DisplayGrid();
    void DisplayOptions();
};

#endif // MOVE_H