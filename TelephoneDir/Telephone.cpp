#include "../TelephoneDir/Telephone.h"
#include "../TelephoneDir/errorCode.h"
#include "../TelephoneDir/linkedLists.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
Telephone<T>::Telephone() {
    directory = LinkedList<T>();
}

template <typename T>
Telephone<T>::~Telephone() {
    directory.~LinkedList();
}

template <typename T>
void Telephone<T>::displayOptions() {
    cout << "1. Add contact\n2. Edit contact\n3. Remove contact\n4. Search contact\n5. Display contacts\n6. Save contacts\n7. Load contacts\n8. Exit\n";
}

template <typename T>
void Telephone<T>::displayMenu() {
    T contact;
    int choice;
    do {
        displayOptions();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter first name: ";
                cin >> contact.f_name;
                cout << "Enter last name: ";
                cin >> contact.l_name;
                cout << "Enter phone number: ";
                string phone;
                cin >> phone;
                contact.phoneNumbers.push_back(phone);
                addContact(contact);
                break;
            }
            case 2: {
                editContact(contact);
                break;
            }
            case 3: {
                cout << "Enter first name: ";
                cin >> contact.f_name;
                cout << "Enter last name: ";
                cin >> contact.l_name;
                removeContact(contact);
                break;
            }
            case 4: {
                cout << "Enter first name: ";
                cin >> contact.f_name;
                cout << "Enter last name: ";
                cin >> contact.l_name;
                cout << "Enter phone number: ";
                string phone;
                cin >> phone;
                contact.phoneNumbers.push_back(phone);
                searchContact(contact);
                break;
            }
            case 5: {
                displayContacts();
                break;
            }
            case 6: {
                saveContacts();
                break;
            }
            case 7: {
                loadContacts();
                break;
            }
            case 8: {
                cout << "Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    } while (choice != 8);
}

template <typename T>
errorCode Telephone<T>::addContact(T contact) {
    return directory.insert(contact);
}

//fix this (fixed maybe not)
template <typename T>
errorCode Telephone<T>::editContact(T& contact) {
    if(searchContact(contact) == errorCode::SUCCESS) {
        cout << "Contact found!" << endl;
        cout << contact.f_name << " " << contact.l_name << endl;
        cout << "1. Edit phone number\n2. Add new number";
        int choice;
        cin >> choice;

        if(choice == 1){
           cout << "Tel: " << endl;
            int i = 0;
            for (string phone : contact.phoneNumbers) {
                cout << i + 1 << ". " << phone << endl;
                i++;
            }
            cout << "Enter the index of the phone number you want to edit: ";
            int index;
            cin >> index;
            string oldNumber = contact.phoneNumbers[index - 1];

            cout << "Enter the new phone number: ";
            string newNumber = "";
            cin >> newNumber;

            for(int i = 0; i < contact.phoneNumbers.size(); i++){
                if(contact.phoneNumbers[i] == oldNumber){
                    contact.phoneNumbers[i] = newNumber;
                    break;
                }
            }
        } else if(choice == 2){
            cout << "Enter the new phone number: ";
            string newNumber = "";
            cin >> newNumber;
            contact.phoneNumbers.push_back(newNumber);
        }
    } else {
        return errorCode::NOT_FOUND;
    }
    return errorCode::SUCCESS;
}

template <typename T>
errorCode Telephone<T>::removeContact(T contact) {
    return directory.remove(contact);
}

template <typename T>
errorCode Telephone<T>::searchContact(T contact) {
    return directory.search(contact);
}

template <typename T>
void Telephone<T>::displayContacts() {
    directory.display();
}

template <typename T>
void Telephone<T>::displayContact(T& contact) {
    directory.search(contact);
}

template <typename T>
errorCode Telephone<T>::saveContacts() {
    return directory.saveToFile();
}

template <typename T>
errorCode Telephone<T>::loadContacts() {
    return directory.loadFromFile();
}

template class Telephone<Contact>;