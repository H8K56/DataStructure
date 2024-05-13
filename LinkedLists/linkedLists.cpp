#include 'linkedLists.h'
#include <iostream>
using namespace std;

// Constructor
template <class T>
List<T>::List(){
    head = nullptr;
}

// Destructor
template <class T>
List<T>::~List(){
    clear();
}

// Node Constructor
template <class T>
Node<T>::Node(const T &item, Node<T> *nextNode){
    data = item;
    next = nextNode;
}

// Clear List
template <class T>
void List<T>::clear(){
    Node<T> *temp;
    while(head != nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
bool List<T>::empty() const{
    return head == nullptr;
}

template <class T>
int List<T>::size() const {
    int count = 0;
    Node<T> *temp = head;

    while(temp != nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

template <class T>
errorCode List<T>::insert(const T &item){
    Node<T> *temp = new Node<T>(item);

    if(temp == nullptr) return fail;
    if(empty()){
        head = temp;
    }else if(item < head->data){
        temp->next = head;
        head = temp;
    }else {
        Node<T> * prev = nullptr;
        Node<T> * curr = head;

        while(curr != nullptr){
            if(curr->data < item){
                temp->next = curr;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = temp;
    }

    return success;
}   

template <class T>
errorCode List<T>::remove(const T &item){
    Node<T> *current = head;
    if(empty()) return fail;
    if(head->data == item){
        head = head->next;
        delete current;
        return success;
    }else{
        Node<T> * prev = current;
        Node<T> * curr = current->next;

        while(curr != nullptr){
            if(item < curr->data) break;
            if(curr->data == item){
                prev->next = curr->next;
                delete curr;
                return success;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    return fail;
}

template <class T>
void List<T>::show(){
    Node<T> *temp = head;
    
    if(empty()){
        cout << "List is empty" << endl;
    else{
        while(temp != nullptr){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 }
}

template <class T>
List<T>::List(const List<T> &other){
    head = nullptr;
    Node<T> *temp = other.head;

    while(temp != nullptr){
        insert(temp->data);
        temp = temp->next;
    }
}

template <class T>
void List<T>::operator=(const List<T> &original){
    if(this != &original){
        clear();
        Node<T> *temp = original.head;

        while(temp != nullptr){
            insert(temp->data);
            temp = temp->next;
        }
    }
}