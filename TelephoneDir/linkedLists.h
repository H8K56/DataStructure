#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <string>
#include <vector>
#include "../TelephoneDir/errorCode.h"

struct Contact {
    std::string f_name, l_name;
    std::vector<std::string> phoneNumbers;

    Contact(const std::string& f_name = "", const std::string& l_name = "", const std::vector<std::string>& phoneNumbers = {}) 
        : f_name(f_name), l_name(l_name), phoneNumbers(phoneNumbers) {}
};

struct Node {
    Contact contact;
    Node* next;
};

template <typename T>
class LinkedList {
private:
    Node* head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    errorCode insert(T&);
    errorCode remove(T);
    errorCode search(T&);
    errorCode saveToFile();
    errorCode loadFromFile();
    void display();
};

#endif // LINKEDLISTS_H