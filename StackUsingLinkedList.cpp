#include <iostream>
using namespace std; 

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    ~Stack(); 
    void push(int x);
    int pop();
    void display();
    bool isEmpty();
    bool isFull();
    int stackTop();
};

bool Stack::isEmpty()
{
    return top == NULL;
}

bool Stack::isFull()
{
    Node *t = new Node;
    if (t == NULL)  
        return true;
    delete t;
    return false;
}

void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        Node *t = new Node;
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;
    if (isEmpty())
    {
        cout << "Stack Underflow!" << endl;
    }
    else
    {
        Node *p = top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}

int Stack::stackTop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        return top->data;
    }
}

void Stack::display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Stack::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.display();

    cout << "Pop element: " << st.pop() << endl;
    st.display();

    return 0;
}
