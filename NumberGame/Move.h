class Move {
private:
    int row, col;
    int difficulty;
    int size;
    int numOfMoves;
    int grid[3][3];

public:
    // Constructor
    Move();

    // Initialization and game setup
    void Initialize();
    void NewGame();

    // Game actions
    void ReverseGrid(int row, int col);
    void SetMove(int row, int col);
    void Undo();
    void Redo();

    // Difficulty settings
    void SetDifficulty(int difficultyLevel);

    // Game status checks
    bool CheckWinStatus() const;

    // Getter
    int GetNumOfMoves() const;

    // Game logic and display
    void GameLogic() const;
    void GamePlay();
    void DisplayGrid() const;
};

