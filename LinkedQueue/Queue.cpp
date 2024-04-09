#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    frontNode = rearNode = nullptr;
    count = 0;
}

bool Queue::empty() const{
    return frontNode == nullptr;
}

errorCode Queue::append(const Entry &item){
    Node *newNode = new Node;
    if(newNode == nullptr) return overflow;
    newNode->entry = item;
    newNode->next = nullptr;
    if(frontNode == nullptr){
        frontNode = newNode;
    } else {
        rearNode->next = newNode;
    }
    rearNode = newNode;
    count++;
    return success;
}

errorCode Queue::serve(){
    if(empty()) return underflow;
    Node *temp = frontNode;
    frontNode = frontNode->next;
    if(frontNode == nullptr) rearNode = nullptr;
    delete temp;
    count--;
    return success;
}

errorCode Queue::retrieve(Entry &item) const{
    if(empty()) return underflow;
    item = frontNode->entry;
    return success;
}

int Queue::size() const{
    return count;
}

bool Queue::full() const{
    Node *temp = new Node;
    if(temp == nullptr) return true;
    delete temp;
    return false;
}

void Queue::print() const{
    Node *temp = frontNode;
    while(temp != nullptr){
        cout << temp->entry << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Queue::clear(){
    while(!empty()){
        serve();
    }
}