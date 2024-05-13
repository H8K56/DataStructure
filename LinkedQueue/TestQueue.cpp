#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    frontNode = rearNode = nullptr;
    count = 0;
}

bool Queue::empty(){
    return frontNode == nullptr;
}

errorCode Queue::append(const Entry &item){
    Node* temp = new Node;
    if(temp == nullptr) return overflow;
    temp->entry  = item;
    temp->next = nullptr;

    if(frontNode == nullptr){
        frontNode = temp;
    }else{
        rearNode->next = temp;
    }

    rearNode = temp;
    count++;
    return success;
}

errorCode Queue::serve(){
    if(frontNode == nullptr) return underflow;

    Node* temp = frontNode;

    frontNode = frontNode->next;   
    if(frontNode == nullptr) rearNode = nullptr; 
    delete temp;
    count--;
    return success
}