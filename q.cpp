#include <iostream>
using namespace std;


class cq {
private:
    int front, rear, max;
    int q[10];

public:

    cq(int maxsize) {
        front = rear = -1;
        max=maxsize;  //initialise with user defined value.
    }

   
void enQ(int val) {
    if ((front == 0 && rear == max - 1) || (front == rear + 1) || (front == rear == -1)) {
        cout << "Queue is Overflowed" << endl;
    } else {
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == max - 1) {     //since it circular once it reaches to the end, it wraps around to index 0
            rear = 0;
        } else {
            rear += 1;   //increment rear to insert the element
        }
        q[rear] = val;
    }
}



    void deQ() {
        if (front == -1) {
            cout << "Queue is underflowed/empty." << endl;
        } else {
            cout << "Value deleted from the queue is " << q[front] << endl;
            if (front == rear) {   //means one element and after deletion, it becomes empty
                front = rear = -1;  //hence reset r and f to -1
            } else {
                if (front == max - 1) {
                    front = 0;   //wraps around to beginning if it reaches to the end
                } else {
                    front += 1;   //increment front 
                }
            }
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "The Queue is -----------------------------" << endl;
            if (front <= rear) {    //elements are in contiguous manner and thers no wrap ups
                for (int i = front; i <= rear; i++) {
                    cout << q[i] << "  " ;
                }
            } else {   //if elements are in the non-contiguous manner...iterate as:
                for (int i = front; i < max; i++) {   //strt from front till the end
                    cout  << q[i] << "  ";
                }
                for (int i = 0; i <= rear; i++) {    //strt from index 0 till the rear+
                    cout  << q[i] << "  " ;
                }
            }
            cout<<"\n";
            cout << "--------------------------------" << endl;
        }
    }
};

int main() {
    int max;
    cout<<"Enter the size of the queue: ";
    cin>> max;
    cq q(max);
    int val, op;
    char ch;
   
    do {
        cout << "1. Insertion." << endl;
        cout << "2. Deletion." << endl;
        cout << "3. Display." << endl;
        cout << "4. Exit." << endl;
        cin >> op;

        switch (op) {
            case 1:
                cout << "Enter a value to insert in the queue: ";
                cin >> val;
                q.enQ(val);
                break;

            case 2:
                q.deQ();
                break;

            case 3:
                q.display();
                break;

            case 4:
                exit(0);

            default:
                cout << "Invalid option chosen." << endl;
        }

        cout << "Do you wanna continue [YES/NO]" << endl;
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return 0;
}
