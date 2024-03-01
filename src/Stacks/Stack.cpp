#include "Stack.h";
#include <iostream>;
using namespace std;

Stack::Stack() {
    count = 0;
}

Stack::errorCode push(stackEntry &item) {
    if (count >= maxStack) {
        return overflow;
    }
    entry[count++] = item;

    return success;
}

Stack::errorCode pop(){
    if(count == 0 ) return underflow;

    entry[--count];

    return success;
}

Stack::errorCode top(stackEntry &item) const {
    if(count == 0) return underflow;

    item = entry[count - 1];

    return success;
}

bool Stack::empty() const {
    return count == 0;
}

bool Stack::full() const {
    return count == maxStack;
}

int Stack::size() const {
    return count;
}