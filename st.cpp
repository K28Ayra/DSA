#include <iostream>
using namespace std;
#define MAX_SIZE 100
class Stack {
private:
    int arr[MAX_SIZE]; //the datatypes are privte and cant be chnged
    int top;

//all the functions of operations are created as public
public:
    Stack() {
        top = -1;  //initially top is -1; 
    }

//push
    void push(int digit) {
        if (top < MAX_SIZE) {
            arr[++top] = digit;
        } else {
            cout << "Stack is full. Cannot push." << endl;
        }
    }

//pop
    int pop() {
        if (top >= 0) {
            return arr[top--];
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
            return -1; // Return a default value indicating an error
        }
    }

//check if stack empty
    bool isEmpty() {
        return top == -1;
    }
};

class IntegerReverser {
private:
    int number;
    Stack digitStack;

public:
    IntegerReverser(int num) {
        number = num;
    }

    int reverse() {
        int temp = number;
        while (temp != 0) {
            int digit = temp % 10;
            digitStack.push(digit);
            temp /= 10;
        }

        int reversedNumber = 0;
        int multiplier = 1;

        while (!digitStack.isEmpty()) {
            int digit = digitStack.pop();
            reversedNumber += digit * multiplier;
            multiplier *= 10;
        }

        return reversedNumber;
    }
};

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    IntegerReverser reverser(num);
    int reversedNum = reverser.reverse();
    
    cout<<"-----------------------------"<< endl;
    cout << "Reversed Integer: " << reversedNum << endl;

    return 0;
}
