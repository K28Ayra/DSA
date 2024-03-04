#include <iostream>
#include <stack> //to try using built in functions of stack like push pop length etc
#include <string>

using namespace std;

int comparisons = 0; // Initialize a counter for comparisons
// Function to determine the precedence of operators
int precedence(char op)
{
    if (op == '^')
    {
        return 3;
    }
    else if (op == '+' || op == '-')
    {
        return 2;
    }
    else if (op == '*' || op == '/')
    {
        return 3;
    }
    return 0; // Lower precedence for non-operators
}

// Function to convert infix expression to postfix
string infixToPostfix(const string &infix)
{
    stack<char> st; // to hold operators
    string postfix; // to hold postfix expression

    for (char ch : infix)
    {
        if (isalnum(ch)) // alphanumeric character
        {
            // If it's an operand (letter or digit), add it to the postfix string
            postfix += ch;
        }
        else if (ch == '(')
        {
            // If it's an opening parenthesis, push it onto the stack
            st.push(ch);
        }
        else if (ch == ')')
        {
            // If it's a closing parenthesis, pop operators from the stack and add them to the postfix string
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // Pop the opening parenthesis
        }
        else
        {
            // If it's an operator, pop operators from the stack with higher or equal precedence and add them to postfix
            while (!st.empty() && precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(ch); // Push the current operator onto the stack
        }
        // Print the current state in each step

        cout << "Current : " << ch << "\tCurrent Postfix: " << postfix << "\t\t st Stack: ";
        stack<char> tempStack = st;  //making a temp stack  to print the contents of the stack without actually modifying it
        while (!tempStack.empty())
        {
            cout << tempStack.top();
            tempStack.pop();
        }
        cout << endl;
    }

    // Pop any remaining operators from the stack and add them to postfix
    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}

// (a-b/c)*(a/k-l)