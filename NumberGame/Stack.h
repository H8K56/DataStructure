#ifndef STACK_H
#define STACK_H

enum errorCode { underflow, overflow, success };

struct Position {
    int row;
    int col;

    // Provide default values for row and col parameters
    Position(int r = 0, int c = 0) : row(r), col(c) {}
};

struct Node {
    Position position;
    Node* next;

    Node() : next(nullptr) {} // Explicitly defined default constructor
    Node(const Position& p, Node* n = nullptr) : position(p), next(n) {}
};

class Stack {
public:
    Stack() : topNode(nullptr) {}
    ~Stack();

    bool empty() const;
    errorCode push(const Position& x);
    errorCode pop();
    errorCode top(Position& x) const;
    int size() const;
    void print() const;
    void clear();

private:
    Node* topNode;
};

#endif // STACK_H
