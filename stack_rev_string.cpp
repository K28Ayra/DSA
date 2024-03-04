#include <iostream>
using namespace std;
class Stack {
private:
    char arr[100]; // Assuming a maximum string length of 100 for simplicity
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char character) {
        if (top < 99) {
            arr[++top] = character;
        } else {
            cout << "Stack is full. Cannot push." << endl;
        }
    }

    char pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
            return '\0'; // Return a default value indicating an error
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

class StringReverser {            //class
private:
    string inputString;
    Stack charStack;

public:
    StringReverser(const string str) {       //a constructor taking input string and initialises it
        inputString = str;
    }

    string reverse() {           //reverse method :pushes each charater into stack as for now
        for (char character : inputString) {
            charStack.push(character);
        }

        string reversedString = "";   //here initialise a empty string to store the reversed string later

        while (!charStack.isEmpty()) {   //reversing the string by popping the characters from the stack
            char character = charStack.pop();
            reversedString += character;
        }

        return reversedString;
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    StringReverser reverser(input);
    string reversedString = reverser.reverse();      //instance of stringreverser class which passes the user's input to its construictor
                                                  //and calling reverse() function on the reverser object
    cout << "Reversed String: " << reversedString << endl;

    return 0;
}
