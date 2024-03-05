#include <iostream>
#include "Queue.cpp"
using namespace std;

int main()
{
    Queue lineQueue;
    queueEntry item = 0.0;
    errorCode result;

    for(int i = 0;i < 3;i++)
    {
        try{
            cin >> item;
            lineQueue.append(item);
        }catch(errorCode error){
            cout << "Error: " << error << endl;
        }
    }

    lineQueue.print();

    lineQueue.serve();
    lineQueue.serve();

    lineQueue.print();
    return 0;
}