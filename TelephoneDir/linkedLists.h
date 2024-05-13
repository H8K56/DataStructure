#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../TelephoneDir/errorCode.h"

using namespace std;

struct Contact
{
    string f_name, l_name;
    vector<string> phoneNumbers;

    Contact(const string f_name = "", const string l_name = "", const vector<string> phoneNumbers = {})
        : f_name(f_name), l_name(l_name), phoneNumbers(phoneNumbers) {}
};

template <typename T>
struct Node
{
    Contact contact;
    Node *next;
};

template <typename T>
class LinkedList
{
private:
    Node<T> *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }

    errorCode insert(T &contact)
    {
        Node<T> *newNode = new Node<T>;
        if (newNode == nullptr)
        {
            return errorCode::FAIL;
        }
        newNode->contact = contact;
        newNode->next = nullptr;
        if(head == nullptr){ head = newNode;}
        else{
            Node<T> *prev = head;
            Node<T> *current = head->next;

            while(current != nullptr){
                if(current->contact.l_name > contact.l_name){
                    newNode->next = current;
                    size++;
                    break;
                }
                prev = current;
                current = current->next;
            }
            prev->next = newNode;
        }
        return errorCode::SUCCESS;
    }

    errorCode remove(T &contact)
    {
        Node<T> *curr = head;
        if(head == nullptr) return errorCode::FAIL;
        if(head->contact.l_name == contact.l_name){
            head = head->next;
            delete curr;
            return errorCode::SUCCESS;
        }else{
            Node<T> *prev = curr;
            Node<T> *current = curr->next;

            while(current != nullptr){
                if(current->contact.l_name < contact.l_name) break;
                if(current->contact.l_name == contact.l_name){
                    prev->next = current->next;
                    delete current;
                    return errorCode::SUCCESS;
                }
                prev = current;
                current = current->next;
            }
        }
        return errorCode::FAIL; // Contact not found
    }

    errorCode search(T &contact)
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            if (current->contact.l_name == contact.l_name)
            {
                contact = current->contact;
                return errorCode::SUCCESS;
            }
            current = current->next;
        }
        return errorCode::NOT_FOUND;
    }

    errorCode saveToFile()
    {
        ofstream file("teldir.txt");
        if (!file.is_open())
        {
            return errorCode::FAIL;
        }
        Node<T> *current = head;
        while (current != nullptr)
        {
            file << current->contact.f_name << "\t" << current->contact.l_name << endl;
            for (const string &phone : current->contact.phoneNumbers)
            {
                file << phone << endl;
            }
            current = current->next;
            file << endl;
        }
        file.close();
        return errorCode::SUCCESS;
    }

    errorCode loadFromFile()
    {
        ifstream file("teldir.txt");
        if (!file.is_open())
        {
            return errorCode::FAIL;
        }
        string f_name, l_name, phone;
        while (file >> f_name >> l_name)
        {
            Contact contact;
            contact.f_name = f_name;
            contact.l_name = l_name;
            contact.phoneNumbers.clear();
            while (file >> phone)
            {
                contact.phoneNumbers.push_back(phone);
            }
            if (!file.fail())
            {
                insert(contact);
            }
        }
        file.close();
        return errorCode::SUCCESS;
    }

    void display()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            cout << "Name: \n"
                 << current->contact.f_name << "\t" << current->contact.l_name << endl;
            cout << "Phone Numbers: " << endl;
            for (const string &phone : current->contact.phoneNumbers)
            {
                cout << phone << endl;
            }
            cout << endl;
            current = current->next;
        }
        cout << "Size: " << size << endl;
    }
};

#endif // LINKEDLISTS_H