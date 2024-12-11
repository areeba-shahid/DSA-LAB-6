Week 6: Queue and Stack
Objective
In this week, we will be working with Stacks and Queues, two important data structures. The goal is to understand their operations, applications, and how to implement them in a programming language of your choice.

Stack
Definition
A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. The last element inserted is the first one to be removed.

Common Operations
push(): Adds an element to the top of the stack.
pop(): Removes the top element from the stack.
peek() or top(): Returns the top element without removing it.
isEmpty(): Returns true if the stack is empty.
size(): Returns the number of elements in the stack.
Example: Implementing a Stack (C++)
cpp
Copy code
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);   // Adds 10 to the stack
    s.push(20);   // Adds 20 to the stack
    s.push(30);   // Adds 30 to the stack

    cout << "Top element: " << s.top() << endl; // Prints 30
    s.pop();      // Removes 30
    cout << "Top element after pop: " << s.top() << endl; // Prints 20

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl; // No
}
Applications of Stack
Undo/Redo functionality in software.
Expression evaluation (e.g., postfix and prefix expressions).
Backtracking problems, such as maze solving.
Queue
Definition
A queue is a linear data structure that follows the First In, First Out (FIFO) principle. The first element inserted is the first one to be removed.

Common Operations
enqueue(): Adds an element to the back of the queue.
dequeue(): Removes the front element from the queue.
front(): Returns the front element without removing it.
isEmpty(): Returns true if the queue is empty.
size(): Returns the number of elements in the queue.
Example: Implementing a Queue (C++)
cpp
Copy code
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);  // Adds 10 to the queue
    q.push(20);  // Adds 20 to the queue
    q.push(30);  // Adds 30 to the queue

    cout << "Front element: " << q.front() << endl; // Prints 10
    q.pop();     // Removes 10
    cout << "Front element after pop: " << q.front() << endl; // Prints 20

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl; // No
}
Applications of Queue
Job scheduling in operating systems.
Breadth-First Search (BFS) in graphs.
Buffering and streaming data.
Comparison: Stack vs Queue
Feature	Stack	Queue
Type	LIFO (Last In, First Out)	FIFO (First In, First Out)
Insertions	push() at the top	enqueue() at the back
Removals	pop() from the top	dequeue() from the front
Access	top() or peek()	front()
Empty Check	isEmpty()	isEmpty()
Size	size()	size()
Example Problem: Implementing a Stack to Reverse a String
Problem:
Given a string, implement a function to reverse the string using a stack.

Approach:
Push each character of the string onto the stack.
Pop each character from the stack and append it to a new string.
C++ Code:
cpp
Copy code
#include <iostream>
#include <stack>
using namespace std;

string reverseString(string s) {
    stack<char> stack;
    string result = "";
    
    // Push each character onto the stack
    for (char c : s) {
        stack.push(c);
    }
    
    // Pop each character and append to result
    while (!stack.empty()) {
        result += stack.top();
        stack.pop();
    }
    
    return result;
}

int main() {
    string s = "Hello";
    cout << "Reversed string: " << reverseString(s) << endl; // Output: "olleH"
}
Conclusion
In this week, we explored two fundamental data structures: Stacks and Queues. Both have wide-ranging applications in computer science, from solving algorithmic problems to implementing core features in software. Understanding these structures will help in solving more complex problems efficiently.
