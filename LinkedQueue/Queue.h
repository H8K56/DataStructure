typedef double Entry;

enum errorCode {success, overflow, underflow};

class Queue{
public:
    Queue();
    bool empty() const;
    errorCode append(const Entry &item);
    errorCode serve();
    errorCode retrieve(Entry &item) const;
    int size() const;
    bool full() const;
    void print() const;
    void clear();   
private:
    struct Node{
        Entry entry;
        Node *next;
    };
    Node *frontNode;
    Node *rearNode;
    int count;
};