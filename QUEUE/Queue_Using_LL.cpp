#include <iostream>
using namespace std;
class Node {
 public:
 int data;
 Node* next;
 Node(int val){
    data = val;
    next = NULL;
 }
};
class Queue {
 public:
 Node* front;
 Node* rear;
 Queue(){
    front = NULL;
    rear = NULL;
 }
    // Function to push from rear
    void enqueue(int val){
        Node* newNode = new Node(val);
        if(rear == NULL) { // If queue is empty
            front = rear = newNode; // Both front and rear point to the new node
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
   //Fn to pop from front
   void dequeue(){
    if(front==NULL) return;
    Node* temp = front; // Store the current front node 
    front = front->next;
    if(front == NULL) { // If the queue becomes empty after pop
        rear = NULL; // Update rear to NULL as well
    }
    delete temp; // Free the memory of the popped node
   }
   //Fn to Peek/see the front element.
   int peek(){
    if(front == NULL) {
        return -1;
      } else{
          return front->data;
      } 
    }
    //chk if the queue is empty
    bool isEmpty(){
 return front == NULL;
    } 
    //Fn to print the queue.
   void print(){
    Node* temp = front;
    while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
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
q.print();    //1 2 3 4
cout<<q.peek()<<endl; //Front = 1
q.dequeue();// Removesfront = 1
q.dequeue();//Removes Newfront = 2
q.print(); //3 4
cout<<q.peek()<<endl; //New Front = 3
    return 0;
}