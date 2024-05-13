#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>
using namespace std;

enum errorCode{success,fail};
class DLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    DLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DLinkedList() {
        // TODO: Implement destructor to free memory
    }

    void insertFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    void insertBack(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = tail;
        newNode->next = nullptr;

        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }

        tail = newNode;
    }

    // TODO: Implement other member functions such as deleteFront, deleteBack, etc.
};