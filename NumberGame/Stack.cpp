#include "./Stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : topNode(nullptr) {}

Stack::~Stack()
{
    clear();
}

Node::Node(Position p, Node *n) {
    position = p;
    next = n;
}

bool Stack::empty() const
{
    return topNode == nullptr;
}

errorCode Stack::top(Position &item) const
{
    if (empty())
        return underflow;
    item = topNode->position;
    return success;
}

errorCode Stack::push(const Position &item)
{
    Node *newNode = new Node(item, topNode);
    if (newNode == nullptr)
        return overflow;

    topNode = newNode;
    return success;
}

errorCode Stack::pop()
{
    if (empty())
        return underflow;

    Node *temp = topNode;
    topNode = topNode->next;

    delete temp;
    return success;
}

int Stack::size() const
{
    int count = 0;
    Node *temp = topNode;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void Stack::print() const
{
    Node *temp = topNode;
    while (temp != nullptr)
    {
        cout << "(" << temp->position.row << "," << temp->position.col << ") ";
        temp = temp->next;
    }
    cout << endl;
}

void Stack::clear()
{
    while (!empty()) pop();
}

