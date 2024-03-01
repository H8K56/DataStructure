#include "Stack.h";
#include <iostream>;
using namespace std;

int main() {
    Stack s;
    stackEntry item;
    errorCode result;

    for (double i = 0; i < 10; i++) {
        s.push(i);
    }

    s.print();

    s.pop();
    s.pop();
    s.pop();

    s.print();

    s.top(item);
    cout << "Top: " << item << endl;

    return 0;
}