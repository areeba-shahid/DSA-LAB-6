#include <iostream>
using namespace std;

struct SimpleQueue
{
    int capacity;
    int start;
    int end;
    int *arr;
};

void initialize(SimpleQueue *q)
{
    cout << "Enter the capacity: ";
    cin >> q->capacity;
    q->arr = new int[q->capacity];
    q->start = q->end = -1;
}

bool isQueueEmpty(const SimpleQueue &q)
{
    return q.start == q.end;
}

bool isQueueFull(const SimpleQueue &q)
{
    return q.end == q.capacity - 1;
}

void addToQueue(SimpleQueue *q, int value)
{
    if (isQueueFull(*q))
    {
        cout << "Queue is at maximum capacity" << endl;
    }
    else
    {
        q->end++;
        q->arr[q->end] = value;
    }
}

int removeFromQueue(SimpleQueue *q)
{
    int removedValue = -1;
    if (isQueueEmpty(*q))
    {
        cout << "Queue has no elements" << endl;
    }
    else
    {
        q->start++;
        removedValue = q->arr[q->start];
    }
    return removedValue;
}

void showQueue(const SimpleQueue &q)
{
    if (isQueueEmpty(q))
    {
        cout << "Queue is currently empty" << endl;
        return;
    }

    for (int i = q.start + 1; i <= q.end; i++)
    {
        cout << q.arr[i] << " ";
    }
    cout << endl;
}

void freeMemory(SimpleQueue *q)
{
    delete[] q->arr;
    q->arr = nullptr;
}

int main()
{
    SimpleQueue q;
    initialize(&q);

    addToQueue(&q, 10);
    addToQueue(&q, 20);
    addToQueue(&q, 30);

    cout << "Queue with 3 elements: ";
    showQueue(q);

    cout << "Removing an element: " << removeFromQueue(&q) << endl;

    cout << "Queue after removal: ";
    showQueue(q);

    freeMemory(&q);

    return 0;
}
