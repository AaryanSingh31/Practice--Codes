#include <iostream>
using namespace std;
class Node{
public:
int data;
Node* next;
Node* prev;
Node(int value){
    data = value;
    prev = next = NULL;
 }
};
class DoublyList{
public:
Node* head;
Node* tail;
DoublyList(){
    head = tail = NULL;
}
// FN TO PUSH FRONT
void pushFront(int value){
    Node* NewNode = new Node(value);

    if(head==NULL){
      head = tail = NewNode;
    } else{
    NewNode->next = head; //forward link
    head->prev = NewNode; //backward link
    //NewNode->prev = NULL; //new node will be the first node
    head = NewNode;       //head will point to the new node
    }
}
// FN TO PUSH BACK
    void pushBack(int value){
    Node* NewNode = new Node(value);
    if(head==NULL){
        head = tail = NewNode;
    } else{
        tail->next = NewNode; //forward link    
        NewNode->prev = tail; //backward link
        //NewNode->next = NULL; //new node will be the last node
        tail = NewNode; //tail will point to the new node
    }
}
//FN TO POP FRONT
void popFront(){
    if(head == NULL){
        return;
    } else if(head == tail){
        delete head;
        head = tail = NULL;
    } else{
        Node* temp = head; //store the current head
        head = head->next; //move head to the next node 
        head->prev = NULL; //set the previous of new head to NULL (backward link removed.)
        delete temp;       //delete the old head (Automatically removes the forward link)
    }
}
//FN TO POP BACK
void popBack(){
    if(head == NULL){
        return;
    } else if(head == tail){
        delete head;
        head = tail = NULL;
    } else{
        Node* temp = tail; //store the current tail
        tail = tail->prev; //move tail to the previous node
        tail->next = NULL; //set the next of new tail to NULL (forward link removed.)
        delete temp;       //delete the old tail (Automatically removes the backward link)
    }
}

void print(){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"<=>";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
   }
  
};
int main(){
DoublyList list;
list.pushFront(3);
list.pushFront(2);
list.pushFront(1);
list.pushBack(4);
list.pushBack(5);
list.popFront();
list.popBack();
list.print();

    return 0;
}
// Output:-
// 2<=>3<=>4<=>NULL