#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

enum errorCode{success,fail}
template <class T>

// struct Contact{
//     T fname;
//     T surname;
//     T number;
//     Contact(const T &fname,const T &surname, const T &number);
// };

struct Node{
    T data;
    Node<T> *next;
    Node(const T &item, Node<T> *nextNode = nullptr);
};

class List{
    public:
        List();
        void clear();
        bool empty() const;
        int size() const;
        errorCode remove(const T &item);
        errorCode insert(const T &item);
        void show();
        //Safeguards
        ~List();
        void operator=(const List<T> &original);
    protected:
        Node<T> *head;
}

#endif // LINKEDLISTS_H