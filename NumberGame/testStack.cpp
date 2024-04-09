#include "../../DataStructure/NumberGame/Stack.h" // Assuming Stack.h is in this directory
#include <iostream>

int main()
{
    Stack s;
    Position p1(1, 2), x(0, 0);

    // Check if push operation was successful
    if (s.push(p1) == success)
    {
        // Check if top operation was successful
        if (s.top(x) == success)
        {
            std::cout << "Size: " << s.size() << std::endl;
            std::cout << "Top element: " << x.row << " " << x.col << std::endl;
        }
        else
        {
            std::cerr << "Failed to get top element." << std::endl;
            return 1; // Return an error code indicating failure
        }
    }
    else
    {
        std::cerr << "Failed to push element onto the stack." << std::endl;
        return 1; // Return an error code indicating failure
    }

    return 0;
}
