#include "linkedLists.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    size = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}


template<typename T>
errorCode LinkedList<T>::insert(T& contact) {
    Node* newNode = new Node;
    if (newNode == nullptr) {
        return errorCode::FAIL;
    }
    newNode->contact = contact;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        if (search(contact) == errorCode::SUCCESS) {
            return errorCode::DUPLICATE;
        } else {
            if (head->contact.l_name > contact.l_name) {
                newNode->next = head;
                head = newNode;
            } else {
                Node* previous = nullptr;
                Node* current = head;
                while (current != nullptr) {
                    if (current->contact.l_name > contact.l_name) {
                        newNode->next = current;
                        break;
                    }
                    previous = current;
                    current = current->next;
                }
                previous->next = newNode;
            }
        }
    }
    return errorCode::SUCCESS;
}

template<typename T>
errorCode LinkedList<T>::remove(T contact) {
    if (head == nullptr) {
        return errorCode::FAIL;
    }
    Node* current = head;
    Node* previous = nullptr;
    while (current != nullptr) {
        if (current->contact.l_name == contact.l_name) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return errorCode::SUCCESS;
        }
        previous = current;
        current = current->next;
    }
    return errorCode::SUCCESS;
}

template<typename T>
void LinkedList<T>::display() {
    Node* current = head;
    while (current != nullptr) {
        cout <<"Name: \n"<< current->contact.f_name << "\t" << current->contact.l_name << endl;
        cout << "Phone Numbers: " << endl;
        for (string phone : current->contact.phoneNumbers) {
            cout << phone << endl;
        }
        cout << endl;
        current = current->next;
    }
}

template<typename T>
errorCode LinkedList<T>::search(T& contact) {
    Node* current = head;
    while (current != nullptr) {
        if (current->contact.l_name == contact.l_name){
            contact = current->contact;
            return errorCode::SUCCESS;
        }
        current = current->next;
    }
    return errorCode::NOT_FOUND;
}

template<typename T>
errorCode LinkedList<T>::saveToFile() {
    ofstream file("teldir.txt");
    if (file.is_open()) {
        Node* current = head;
        while (current != nullptr) {
            file << current->contact.f_name << "\t" << current->contact.l_name << endl;
            for (string phone : current->contact.phoneNumbers) {
                file << phone << endl;
            }
            current = current->next;
            file << endl;
        }
        file.close();
    }else{
        return errorCode::FAIL;
    }

    return errorCode::SUCCESS;
}

template<typename T>
errorCode LinkedList<T>::loadFromFile() {
    ifstream file("teldir.txt");
    if (file.is_open()) {
        string f_name, l_name, phone;
        while (file >> f_name >> l_name) {
            Contact contact;
            contact.f_name = f_name;
            contact.l_name = l_name;
            while (file >> phone) {
                contact.phoneNumbers.push_back(phone);
            }
            insert(contact);
        }
        file.close();
    }else{
        return errorCode::FAIL;
    }

    return errorCode::SUCCESS;
}