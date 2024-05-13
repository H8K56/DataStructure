#ifndef TELEPHONE_H
#define TELEPHONE_H

#include "../TelephoneDir/linkedLists.h"
#include "../TelephoneDir/errorCode.h"


#include <iostream>
#include <string>
#include <vector>


template <typename T>
class Telephone {
    private:
        LinkedList<T> directory;
    public:
        Telephone();
        ~Telephone();
        errorCode addContact(T);
        errorCode editContact(T&);
        errorCode removeContact(T);
        errorCode searchContact(T);
        errorCode saveContacts();
        errorCode loadContacts();
        void displayContacts();
        void displayContact(T&);
        void displayOptions();
        void displayMenu();
};

#include "Telephone.cpp"
#endif