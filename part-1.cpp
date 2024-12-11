#include <iostream>
using namespace std;

class Element
{
public:
    int value;
    Element *nextElement;
};

class Sequence
{
private:
    Element *start;

public:
    Sequence()
    {
        start = nullptr;
    }

    ~Sequence()
    {
        Element *temp;
        while (start)
        {
            temp = start;
            start = start->nextElement;
            delete temp;
        }
    }

    bool isEmpty()
    {
        return start == nullptr;
    }

    void addElement(int position, int val)
    {
        if (position < 0)
            return;

        Element *newElement = new Element;
        newElement->value = val;
        newElement->nextElement = nullptr;

        if (position == 0)
        {
            newElement->nextElement = start;
            start = newElement;
        }
        else
        {
            Element *p = start;
            for (int i = 0; i < position - 1 && p; i++)
            {
                p = p->nextElement;
            }
            if (p)
            {
                newElement->nextElement = p->nextElement;
                p->nextElement = newElement;
            }
        }
    }

    void addAtBeginning(int val)
    {
        addElement(0, val);
    }

    void addAtEnd(int val)
    {
        Element *newElement = new Element;
        newElement->value = val;
        newElement->nextElement = nullptr;

        if (start == nullptr)
        {
            start = newElement;
        }
        else
        {
            Element *p = start;
            while (p->nextElement)
            {
                p = p->nextElement;
            }
            p->nextElement = newElement;
        }
    }

    bool findElement(int val)
    {
        Element *p = start;
        while (p)
        {
            if (p->value == val)
                return true;
            p = p->nextElement;
        }
        return false;
    }

    bool removeElement(int val)
    {
        Element *p = start;
        Element *q = nullptr;

        bool found = false;

        while (p)
        {
            if (p->value == val)
            {
                if (p == start)
                {
                    start = start->nextElement;
                    delete p;
                    p = start;
                }
                else
                {
                    q->nextElement = p->nextElement;
                    delete p;
                    p = q->nextElement;
                }
                found = true;
            }
            else
            {
                q = p;
                p = p->nextElement;
            }
        }
        return found;
    }

    bool removeFromStart()
    {
        if (start == nullptr)
            return false;

        Element *temp = start;
        start = start->nextElement;
        delete temp;
        return true;
    }

    bool removeFromEnd()
    {
        if (start == nullptr)
            return false;

        if (start->nextElement == nullptr)
        {
            delete start;
            start = nullptr;
            return true;
        }

        Element *p = start;
        Element *q = nullptr;
        while (p->nextElement)
        {
            q = p;
            p = p->nextElement;
        }
        q->nextElement = nullptr;
        delete p;
        return true;
    }

    void showSequence()
    {
        Element *p = start;
        while (p)
        {
            cout << p->value << " ";
            p = p->nextElement;
        }
        cout << endl;
    }

    void reverseSequence()
    {
        Element *p = start;
        Element *q = nullptr;
        Element *r = nullptr;

        while (p)
        {
            r = q;
            q = p;
            p = p->nextElement;
            q->nextElement = r;
        }
        start = q;
    }

    Element *combineSequences(Element *seq1, Element *seq2)
    {
        Element *combined = nullptr;
        Element **lastPtrRef = &combined;

        while (seq1 && seq2)
        {
            if (seq1->value <= seq2->value)
            {
                *lastPtrRef = seq1;
                seq1 = seq1->nextElement;
            }
            else
            {
                *lastPtrRef = seq2;
                seq2 = seq2->nextElement;
            }
            lastPtrRef = &((*lastPtrRef)->nextElement);
        }

        if (seq1)
            *lastPtrRef = seq1;
        else
            *lastPtrRef = seq2;

        return combined;
    }

    Element *intersectSequences(Element *seq1, Element *seq2)
    {
        Element *result = nullptr;
        Element **lastPtrRef = &result;

        while (seq1 && seq2)
        {
            if (seq1->value == seq2->value)
            {
                Element *temp = new Element;
                temp->value = seq1->value;
                temp->nextElement = nullptr;
                *lastPtrRef = temp;
                lastPtrRef = &((*lastPtrRef)->nextElement);

                seq1 = seq1->nextElement;
                seq2 = seq2->nextElement;
            }
            else if (seq1->value < seq2->value)
            {
                seq1 = seq1->nextElement;
            }
            else
            {
                seq2 = seq2->nextElement;
            }
        }
        return result;
    }
};

int main()
{
    Sequence seq;

    int arr[] = {20, 40, 60, 80};
    for (int i = 0; i < 4; i++)
    {
        seq.addAtEnd(arr[i]);
    }

    cout << "Initial Sequence: ";
    seq.showSequence();

    seq.reverseSequence();
    cout << "Reversed Sequence: ";
    seq.showSequence();

    return 0;
}
