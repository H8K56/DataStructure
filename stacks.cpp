#include <iostream>
#include <stack>

int main() {
    // Creating a stack
    std::stack<int> myStack;

    // Pushing elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Checking if the stack is empty
    if (myStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    // Accessing the top element of the stack
    std::cout << "Top element of the stack: " << myStack.top() << std::endl;

    // Popping elements from the stack
    myStack.pop();
    myStack.pop();

    // Checking the size of the stack
    std::cout << "Size of the stack: " << myStack.size() << std::endl;
    std::cout << "Version" << __cplusplus << std::endl;

    return 0;
}