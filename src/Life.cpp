#include "../HeaderFiles/Life.h"
#include <iostream> // Include <iostream> for cout and endl
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()

using namespace std; // Use the std namespace

void Life::initialise() {
    srand(time(0)); // Seed the random number generator inside a function

    for (int row = 0; row < MAXROWS; row++) {
        for (int col = 0; col < MAXCOLS; col++) {
            // Generate a random number between 0 and 1
            int random = rand() % 2; // Generate random integer in range [0, 1]

            // Set the cell to ALIVE if the random number is 0, otherwise set it to DEAD
            if (random == 0) {
                grid[row][col] = ALIVE;
            } else {
                grid[row][col] = DEAD;
            }
        }
    }
}

void Life::print() const {
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            if (grid[i][j] == DEAD) {
                cout << ".";
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
}

int Life::neighbourCount(int row,int col) const{
    int count = 0;
    for(int i = max(0, row - 1); i <= min(MAXROWS - 1, row + 1); i++){
        for(int j = max(0, col - 1); j <= min(MAXCOLS - 1, col + 1); j++){
            // if the cell is not the current cell
            if(i != row || j != col){
                if(grid[i][j] == ALIVE){
                    count++;
                }
            }
        }
    }
    return count;
}

void Life::update(){
    State newGrid[MAXROWS][MAXCOLS]; // Define a new grid to store the updated values
    for(int i = 0; i < MAXROWS; i++){
        for(int j = 0; j < MAXCOLS; j++){
            int count = neighbourCount(i, j);
            switch(count){
                case 2:
                    newGrid[i][j] = grid[i][j];
                    break;
                case 3:
                    newGrid[i][j] = ALIVE;
                    break;
                default:
                    newGrid[i][j] = DEAD;
            }
        }
    }
    // Copy the contents of newGrid back to grid
    for(int i = 0; i < MAXROWS; i++){
        for(int j = 0; j < MAXCOLS; j++){
            grid[i][j] = newGrid[i][j];
        }
    }
}
