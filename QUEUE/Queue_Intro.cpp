#include <iostream>
#include <vector>
using namespace std;
class Queue{
    public:
static const int size = 100; //fixed size array.
  int arr[size];
  int front, rear; //Front and rear of the queue.
  Queue(){ //constructor
front = 0;
rear = 0;
  }
  //Fn to push from rear
  void enqueue(int val){
    if(rear==size) return; //if the queue has reached its max size, return.
     arr[rear++] = val; //push the value from rear.. then update the rear to the new value.
  }
  //Fn to pop from front
  void dequeue(){
    if(front == rear) return; //q is empty
    front++; //update the front to next element .. since the front is the start of the queue.. the queue is now starting from next element after updating. i.e, prev 1st element is removed.
  }
  //Fn to peek/see the front element
  int peek(){
    if(front == rear) { //Q is empty
        return -1;
    }
    
    return arr[front]; //Return the front element.
  }
  bool isEmpty(){
    if(front==rear) return true;
     else {
         return false;
     }
}
//Fn to print the queue
  void print(){
    for(int i = front; i < rear; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  }
};
int main(){
Queue q;
q.enqueue(1); //1
q.enqueue(2); //1 2
q.enqueue(3); //1 2 3
q.enqueue(4); //1 2 3 4 
q.enqueue(6); //1 2 3 4 6
cout<<"Front of the queue : "<<q.peek()<<endl; //1
cout<<"Original Queue : "; //1 2 3 4 6
q.print(); 
q.dequeue(); //Removes the Front : 1
q.dequeue(); //Removes the new front : 2
cout<<"New Front of the queue : "<<q.peek()<<endl; // 3
cout<<"Queue after poping : "; //3 4 6
q.print();

    return 0;
}