#include <iostream>
using namespace std;
struct Element
{
    int value;
    Element *nextElement;
    Element *previousElement;

    Element(int v) : value(v), nextElement(nullptr), previousElement(nullptr) {}
};

class DoubleList
{
public:
    DoubleList() : start(nullptr), end(nullptr) {}
    ~DoubleList();

    bool isEmpty() { return start == nullptr; }
    Element *addAtStart(int v);
    Element *addAtEnd(int v);
    bool removeFromStart();
    bool removeFromEnd();
    void showList();
    Element *invertList();

private:
    Element *start;
    Element *end;
};

Element *DoubleList::addAtStart(int v)
{
    Element *newElement = new Element(v);
    if (isEmpty())
    {
        start = end = newElement;
    }
    else
    {
        newElement->nextElement = start;
        start->previousElement = newElement;
        start = newElement;
    }
    return newElement;
}

Element *DoubleList::addAtEnd(int v)
{
    Element *newElement = new Element(v);
    if (isEmpty())
    {
        start = end = newElement;
    }
    else
    {
        newElement->previousElement = end;
        end->nextElement = newElement;
        end = newElement;
    }
    return newElement;
}

bool DoubleList::removeFromStart()
{
    if (isEmpty())
        return false;
    Element *temp = start;
    if (start == end)
    {
        start = end = nullptr;
    }
    else
    {
        start = start->nextElement;
        start->previousElement = nullptr;
    }
    delete temp;
    return true;
}

bool DoubleList::removeFromEnd()
{
    if (isEmpty())
        return false;
    Element *temp = end;
    if (start == end)
    {
        start = end = nullptr;
    }
    else
    {
        end = end->previousElement;
        end->nextElement = nullptr;
    }
    delete temp;
    return true;
}

Element *DoubleList::invertList()
{
    Element *current = start;
    Element *temp = nullptr;
    while (current != nullptr)
    {
        temp = current->previousElement;
        current->previousElement = current->nextElement;
        current->nextElement = temp;
        current = current->previousElement;
    }
    if (temp != nullptr)
    {
        start = temp->previousElement;
    }
    return start;
}

void DoubleList::showList()
{
    Element *current = start;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->nextElement;
    }
    cout << endl;
}

DoubleList::~DoubleList()
{
    Element *current = start;
    while (current != nullptr)
    {
        Element *nextItem = current->nextElement;
        delete current;
        current = nextItem;
    }
}

int main()
{
    DoubleList myList;

    myList.addAtStart(10);
    myList.addAtStart(20);
    myList.addAtStart(30);

    myList.addAtEnd(40);
    myList.addAtEnd(50);

    cout << "Initial list: ";
    myList.showList();

    myList.removeFromStart();
    cout << "After removal from start: ";
    myList.showList();

    myList.removeFromEnd();
    cout << "After removal from end: ";
    myList.showList();

    myList.invertList();
    cout << "After inversion: ";
    myList.showList();

    return 0;
}
