using namespace std;

typedef double queueEntry;

enum errorCode
{
    success,
    underflow,
    overflow
};

const int MAX = 16;

class Queue
{
public:
    Queue();
    errorCode retrieve(queueEntry &item);
    errorCode append(queueEntry item);
    errorCode serve();
    bool empty() const;
    bool full() const;
    int size() const;
    void print();
    void clear();

private:
    int front, rear;
    int next(int &n);
    int count;
    queueEntry entry[MAX];
};