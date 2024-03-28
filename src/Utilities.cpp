#include "../HeaderFiles/Util.h"
using namespace std;

bool userSaysYes() {
    char c;
    bool initialResponse = true;
    do {
        if (initialResponse) {
            cout << "(y,n)?";
        } else {
            cout << "Respond with either y or n:";
        }
        do {
            cin>>c;
        } while (c == '\n' || c == ' ' || c == '\t');
        initialResponse = false;
    } while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
    return (c == 'y' || c == 'Y');
}