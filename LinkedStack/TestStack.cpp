#include "Stack.h"
#include <iostream>
using namespace std;

Node::Node(){
    next = nullptr;
}

Node::Node(int x,Node *n = nullptr){
    entry = x;
    next = n;
}

Stack::Stack()
{
    topNode = nullptr;
}

bool Stack::empty() const
{
    return topNode == nullptr;
}

errorCode Stack::push(const Entry &x){
    Node* temp = new Node(x);
    if(temp == nullptr) return overflow;
    
    if(topNode == nullptr){
        topNode = temp;
    }else{
        temp->next = topNode;
        topNode = temp
    }

    return success;
}

errorCode Stack::pop(){
    if(topNode == nullptr) return underflow;
    else{
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    return success;
}

errorCode Stack::top(Entry& x) const {
    if(topNode == nullptr) return underflow;

    x = topNode->entry;

    return success;
}

int Stack::size() const {
    int count = 0;
    Node* temp = topNode;

    while(temp != nullptr){
        count++;
        temp = temp->next; 
    }

    return count;
}