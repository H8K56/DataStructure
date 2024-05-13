#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    count = 0;
    front = 0;
    rear = MAX - 1;
}

bool Queue::empty() const
{
    return count == 0;
}

bool Queue::full() const
{
    return count == MAX;
}

int Queue::size() const
{
    return count;
    bool Queue::full() const
    {
        return (rear + 1) % MAX == front;
    }
    int Queue::size() const
    {
        return (rear - front + MAX) % MAX;
    }
}

int Queue::next(int &n)
{
    n = (n + 1) % MAX; // Circular queue

    return n;
}

errorCode Queue::retrieve(queueEntry &item)
{
    if (empty())
        return underflow;

    item = entry[front];

    return success;
}

errorCode Queue::append(queueEntry item)
{
    if (full())
        throw overflow;

    entry[next(rear)] = item;
    count++;

    return success;
}

errorCode Queue::serve()
{
    if (empty())
        throw underflow;

    next(front);
    count--;

    return success;
}

void Queue::print()
{
    int pos = front;

    for (int i = 0; i < count; i++)
    {
        cout << entry[pos] << " ";
        next(pos);
    }
    cout << endl;
}

void Queue::clear()
{
    count = 0;
    front = 0;
    rear = MAX - 1;
}
