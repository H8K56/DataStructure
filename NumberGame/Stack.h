enum errorCode {underflow,overflow,success};

struct Position{
    const int row;
    const int col;

    Position(int r, int c) : row(r), col(c) {}
};


struct Node {
    Position position;
    Node *next;
    
    Node(Position p, Node *n = nullptr) : position(p), next(n) {}
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