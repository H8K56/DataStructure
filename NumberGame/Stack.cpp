#include "./Stack.h"
#include <iostream>
using namespace std;

Stack::~Stack()
{
    clear();
}

bool Stack::empty() const
{
    return topNode == nullptr;
}

errorCode Stack::push(const Position &x)
{
    Node *newNode = new Node();
    if (newNode == nullptr)
    {
        return overflow;
    }
    newNode->position = x;
    newNode->next = topNode;

    topNode = newNode;
    return success;
}

errorCode Stack::pop()
{
    if (empty())
    {
        return underflow;
    }
    Node *temp = topNode;
    topNode = topNode->next;
    delete temp;
    return success;
}

errorCode Stack::top(Position &x) const
{
    if (empty())
    {
        return underflow;
    }
    x = topNode->position;
    return success;
}

int Stack::size() const
{
    int count = 0;
    Node *current = topNode;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

void Stack::print() const
{
    Node *current = topNode;
    while (current != nullptr)
    {
        cout << "(" << current->position.row << ", " << current->position.col << ") ";
        current = current->next;
    }
    cout << endl;
}

void Stack::clear()
{
    while (!empty())
    {
        pop();
    }
}