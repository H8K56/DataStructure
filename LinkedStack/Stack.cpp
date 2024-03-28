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

Stack::Stack(){
    topNode = nullptr;
}

bool Stack::empty(){
    return topNode == nullptr;
}

errorCode Stack::top(Entry &item) const{
    if(empty()) return underflow;
    item = topNode->entry;
    return success;
}

errorCode Stack::push(const Entry &item){
    Node *newNode = new Node(item);
    if(topNode == nullptr){
        topNode = newNode;
    } else {
        newNode->next = topNode;
        topNode = newNode;
    }
    return success;
}

errorCode Stack::pop(){
    if(empty()) return underflow;

    Node *temp = topNode;
    topNode = topNode->next;
    delete temp;
    return success;
}

int Stack::size() const{
    int count = 0;
    Node *temp = topNode;

    while(temp != nullptr){
        count++;
        temp = temp->next;
    }

    return count;
}

void Stack::print() const{
    Node *temp = topNode;

    while(temp != nullptr){
        cout << temp->entry << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Stack::clear(){
    while(!empty()){
        pop();
    }
}