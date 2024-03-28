#include <iostream>

using namespace std;

const int MAXROWS = 20;
const int MAXCOLS = 60;

enum State {DEAD, ALIVE};

class Life {
    public:
        void initialise();
        void print() const;
        void update();
    private:
        int neighbourCount(int row, int col) const;
        State grid[MAXROWS][MAXCOLS];
};