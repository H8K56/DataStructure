#include <iostream>
#include "Telephone.h"
#include "linkedLists.h"

using namespace std;

int main() {
    Telephone<Contact> phoneBook;
    phoneBook.displayMenu();
    return 0;
}