#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

class ExpressionEvaluator {
private:
    stack<int> valueStack;

public:
    int applyOperator(int firstValue, int secondValue, char operation) {
        switch (operation) {
            case '+':
                return firstValue + secondValue;
            case '-':
                return firstValue - secondValue;
            case '*':
                return firstValue * secondValue;
            case '/':
                if (secondValue != 0) {
                    return firstValue / secondValue;
                } else {
                    cout << "Error: Division by zero." << endl;
                    return 0;
                }
            case '%':
                return firstValue % secondValue;
            default:
                cout << "Error: Invalid operator!" << endl;
                return 0;
        }
    }

    void evaluateInput(const string& input) {
        stringstream ss(input);
        string symbol;

        while (ss >> symbol) {
            if (isdigit(symbol[0]) || (symbol.length() > 1 && symbol[0] == '-' && isdigit(symbol[1]))) {
                int number = stoi(symbol);
                valueStack.push(number);
            } else if (symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/" || symbol == "%") {
                if (valueStack.size() < 2) {
                    cout << "Error: Insufficient values in stack." << endl;
                    return;
                }
                int secondValue = valueStack.top(); valueStack.pop();
                int firstValue = valueStack.top(); valueStack.pop();
                int result = applyOperator(firstValue, secondValue, symbol[0]);
                valueStack.push(result);
            } else if (symbol == "?") {
                showStack();
            } else if (symbol == "^") {
                if (!valueStack.empty()) {
                    cout << valueStack.top() << endl;
                    valueStack.pop();
                } else {
                    cout << "Error: Stack is empty." << endl;
                }
            } else if (symbol == "!") {
                cout << "Terminating program." << endl;
                exit(0);
            } else {
                cout << "Error: Invalid input - " << symbol << endl;
            }
        }
    }

    void showStack() {
        stack<int> tempStack = valueStack;
        if (tempStack.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }

        while (!tempStack.empty()) {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
};

int main() {
    ExpressionEvaluator evaluator;
    string input;

    cout << "Enter postfix expressions (operands and operators) or commands (! to exit, ? to display stack, ^ to show top and remove it):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, input);
        evaluator.evaluateInput(input);
    }

    return 0;
}
