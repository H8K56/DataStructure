typedef double Entry;
enum errorCode {underflow,overflow,success};

struct Node{
    Entry entry;
    Node *next;
    Node();
    Node(int,Node* = nullptr);
};

class Stack{
    public:
        Stack();
        bool empty() const;
        errorCode push(const Entry &x);
        errorCode pop();
        errorCode top(Entry &x) const;
        int size() const;
        void print() const;
        void clear();
    private:
        Node *topNode;
};