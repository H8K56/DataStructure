#include "../HeaderFiles/Life.h"
#include "../HeaderFiles/Util.h"

using namespace std;

int main(){
    Life configuration;
    configuration.initialise();

    cout << "An initial configuration" << endl;
    configuration.print();

    cout << "Continue viewing new generations?" << endl;
    while(userSaysYes()){
        configuration.update();
        configuration.print();
        cout << "Continue viewing new generations?" << endl;
    }
    return 0;
}