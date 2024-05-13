#include <iostream>
//#include "Telephone.h"
#include "linkedLists.h"

using namespace std;

int main() {
    LinkedList<Contact> directory;
    Contact contact;

    contact.f_name = "John";
    contact.l_name = "Doe";
    contact.phoneNumbers.push_back("1234567890");

    directory.insert(contact);
    // Create a new contact
    
    contact.f_name = "Jane";
    contact.l_name = "Doe";
    contact.phoneNumbers.push_back("0987654321");

    // Insert the new contact into the directory
    directory.insert(contact);
    directory.display();
    directory.saveToFile();
    directory.loadFromFile();

    // directory.display();

    // directory.search(contact);

    // directory.remove(contact);  
    // directory.display();

    return 0;
}