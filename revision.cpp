#include <iostream>
#include <typeinfo>
using namespace std;

void display () {
    static int x = 0;
    cout << x << endl;
}

int main() {
    enum Day {SUN, MON, TUE, WED, THU, FRI, SAT};

    Day d = MON;

    cout << d << endl;

    cout << (Day)(d + 1) << endl;

    int x = 5,y = 3;
    int num = 10;

    //display();

    return 0;
}