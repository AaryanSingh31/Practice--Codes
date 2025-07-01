#include <iostream>
using namespace std;
class CircularQueue{
 public:
    static const int size = 4;
    int arr[size];
    int front, rear;
CircularQueue(){
    front = -1;
    rear = -1;
}
//Fn to push from rear
void enqueue(int val){
    if((rear+1)%size == front) {
        cout << "Queue is full" << endl; // Queue is full
        return;
    }
    if(front == -1) front = 0; //for first element
    rear = (rear+1)%size; // Circular increment
    arr[rear] = val; // Insert the value at the rear
  }
 //Fn to pop from front
 void dequeue(){
    if(front == -1) {
        cout << "Queue is empty" << endl; // Queue is empty
        return;
    }
    if(front == rear){ //if queue has only 1 element
    front = -1;
    rear = -1;
    } else{
    front = (front+1) % size; // Circular decrement
    }
 }
 //Fn to display
 void print(){
    if(front == -1) {
    cout<<"Queue is Empty.";
    return;
    }
    cout<<"Queue Elements : ";
   int i = front;
   while(true){
    cout<<arr[i]<<" ";
    if(i==rear) break;
    i = (i+1)%size;
   }
   cout<<endl;
 } 
};
int main(){
CircularQueue cq;
cq.enqueue(1);
cq.enqueue(2);
cq.enqueue(3);
cq.enqueue(4);
cq.enqueue(5); //should say queue is full here.
cq.print(); // 1 2 3 4
//poping 2 elements.. 
cq.dequeue();
cq.dequeue();
//space created for two more elements..  rear can traverse again
cq.enqueue(6);
cq.enqueue(7);
cq.print(); // 3 4 6 7
    return 0;
}
// Output:-
// Queue Elements : 1 2 3 4
// Queue Elements : 3 4 6 7
// What's happening Internaly :-

// +--------------------------------------+--------+------+---------------------+------------------------------------------+
// | Step                                 | Front  | Rear | Array Contents      | Notes                                    |
// +--------------------------------------+--------+------+---------------------+------------------------------------------+
// | Initially                            |  -1    | -1   | [ _ , _ , _ , _ ]   | Queue is empty                           |
// | enqueue(1)                           |   0    |  0   | [ 1 , _ , _ , _ ]   | First element inserted                   |
// | enqueue(2)                           |   0    |  1   | [ 1 , 2 , _ , _ ]   |                                          |
// | enqueue(3)                           |   0    |  2   | [ 1 , 2 , 3 , _ ]   |                                          |
// | enqueue(4)                           |   0    |  3   | [ 1 , 2 , 3 , 4 ]   | Queue becomes full                       |
// | enqueue(5)                           |   0    |  3   | [ 1 , 2 , 3 , 4 ]   | ❌ Queue is full — cannot insert         |
// | dequeue() → removes 1                |   1    |  3   | [ _ , 2 , 3 , 4 ]   | Front moves forward to 2                 |
// | dequeue() → removes 2                |   2    |  3   | [ _ , _ , 3 , 4 ]   | Front moves to 3                         |
// | enqueue(6) → wraps to index 0        |   2    |  0   | [ 6 , _ , 3 , 4 ]   | Rear wraps around to beginning           |
// | enqueue(7) → wraps to index 1        |   2    |  1   | [ 6 , 7 , 3 , 4 ]   | Queue becomes full again                 |
// +--------------------------------------+--------+------+---------------------+------------------------------------------+