#include <iostream>
#include <string>
using namespace std;

class Stack
{
private:
    string *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        arr = new string[size];
        capacity = size;
        top = -1;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(string word)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = word;
    }

    string pop()
    {
        if (top == -1)
        {
            cout << "Stack empty!" << endl;
            return "";
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

void reverseWords(string sentence)
{
    Stack wordStack(sentence.length());
    string word = "";

    for (char ch : sentence)
    {
        if (ch != ' ')
        {
            word += ch;
        }
        else
        {
            if (!word.empty())
            {
                wordStack.push(word);
                word = "";
            }
        }
    }

    if (!word.empty())
    {
        wordStack.push(word);
    }
 
    string result = "";
    while (!wordStack.isEmpty())
    {
        result += wordStack.pop();
        if (!wordStack.isEmpty())
        {
            result += ' ';
        }
    }

    cout << result << endl;
}

int main()
{
    string sentence = "I am from University of Engineering and Technology Lahore";
    reverseWords(sentence);

    return 0;
}
