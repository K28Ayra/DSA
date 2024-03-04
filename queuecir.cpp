#include<iostream>
using namespace std;
class que{
private: 
 static const int max=10;
int arr[max];
int front;
int rear;
int capacity;

public:
que(int size){
if(size<=max){
    capacity=size+1;
    front=rear=0;
}else{
    capacity=max;
    front=rear=0;
}

}

bool isempty(){
return rear==front;
}

bool isfull(){
    return (rear+1)%capacity==front;
}

void enq(int value){
if(!isfull()){
    arr[rear]=value;
    rear=(rear+1)%capacity;
}
else{
    cout<<"array is full"<<endl;;
}

}

void deq(){
int elem;
if(!isempty()){
    elem=arr[front];
    front=(front+1)%capacity;
}
else
{
    cout<<"its empty"<<endl;
}
}

void display(){
int current=front;
while(current!=rear){
    cout<<arr[current]<<" ";
    current=(current+1)%capacity;
}
cout<<endl;

}

};



int main(){

que cq(5);

    cq.enq(1);
    cq.enq(2);
    cq.enq(3);

    cq.display();

    cq.deq();

    cq.display();

    cq.enq(4);
    cq.enq(5);

    cq.display();

    cq.enq(6);



    return 0;
}