enum errorCode {underflow,overflow,success};
typedef int Entry;

struct Node{
    Entry entry;
    Node *next;
    Node();
    Node(int,Node* = nullptr);
};

struct Position{
    const int row;
    const int col;

    Position(int r, int c) : row(r), col(c) {}
};

class Stack{
    public:
        Stack();
        ~Stack();
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