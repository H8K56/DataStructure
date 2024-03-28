#include "./Move.h"
using namespace std;

int main()
{
    Move game;

    game.Initialize();
    game.DisplayGrid();
    game.GamePlay();

    return 0;
}