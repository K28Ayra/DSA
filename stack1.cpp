#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

class InfixToPostfixEvaluator {
private:
    string infixExpression;
    string postfixExpression;

    bool isOperator(char c) {
        return (c == '+' || c == '-' || c == '*' || c == '/');
    }

    int precedence(char c) {
        if (c == '+' || c == '-')
            return 1;
        if (c == '*' || c == '/')
            return 2;
        return 0;
    }

public:
    InfixToPostfixEvaluator() {
        infixExpression = "";
        postfixExpression = "";
    }

    void inputInfixExpression() {
        cout << "Enter an infix expression: ";
        cin >> infixExpression;
    }

    void convertToPostfix() {
        stack<char> operatorStack;

        for (char c : infixExpression) {
            if (isalnum(c)) {
                postfixExpression += c; // Append operands directly to the postfix string
            } else if (c == '(') {
                operatorStack.push(c);
            } else if (c == ')') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    postfixExpression += operatorStack.top();
                    operatorStack.pop();
                }
                if (!operatorStack.empty() && operatorStack.top() == '(') {
                    operatorStack.pop(); // Remove the '(' from the stack
                }
            } else if (isOperator(c)) {
                while (!operatorStack.empty() && precedence(c) <= precedence(operatorStack.top())) {
                    postfixExpression += operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.push(c);
            }
        }

        // Pop any remaining operators from the stack and append to the postfix string
        while (!operatorStack.empty()) {
            postfixExpression += operatorStack.top();
            operatorStack.pop();
        }
    }

    double evaluatePostfix() {
        stack<double> operandStack;

        for (char c : postfixExpression) {
            if (isalnum(c)) {
                double operand;
                cout << "Enter the value of operand " << c << ": ";
                cin >> operand;
                operandStack.push(operand);
            } else if (isOperator(c)) {
                double operand2 = operandStack.top();
                operandStack.pop();
                double operand1 = operandStack.top();
                operandStack.pop();

                double result;
                if (c == '+')
                    result = operand1 + operand2;
                else if (c == '-')
                    result = operand1 - operand2;
                else if (c == '*')
                    result = operand1 * operand2;
                else if (c == '/')
                    result = operand1 / operand2;

                operandStack.push(result);
            }
        }

        return operandStack.top();
    }

    void displayPostfixExpression() {
        cout << "Postfix expression: " << postfixExpression << endl;
    }
};

int main() {
    InfixToPostfixEvaluator evaluator;
    evaluator.inputInfixExpression();
    evaluator.convertToPostfix();
    evaluator.displayPostfixExpression();

    double result = evaluator.evaluatePostfix();
    cout << "Result: " << result << endl;

    return 0;
}
