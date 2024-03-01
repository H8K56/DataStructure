typedef double stackEntry;
enum errorCode { success, overflow, underflow };
const int maxStack = 10;

class Stack {
public:
    Stack();
    errorCode push(stackEntry &item);
    errorCode pop();
    errorCode top(stackEntry &item) const;
    bool empty() const;
    bool full() const;
    int size() const;
    void print() const;
    void clear();
private:
    int count;
    stackEntry entry[maxStack];
};