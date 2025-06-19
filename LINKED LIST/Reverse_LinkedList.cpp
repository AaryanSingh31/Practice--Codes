                 //Reverse the LL and return the index of its new HEAD.
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};
class LinkedList{
    public:
    Node * head; //this is list.head.
    LinkedList(){
        head = NULL;
    }
    void pushBack(int value){
        Node * newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            return;
        }
         Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
     void pushFront(int value){
        Node* newNode = new Node(value);
        if(head==NULL){
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
     }
     void print(){
         Node* temp = head;
         while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
         }
         cout<<"NULL"<<endl;
     }
     Node* reverse_LL(){ // Fn type is pointer so it returns the pointer.
        Node* prev = NULL; 
        Node* curr = head;
        Node* upcoming = NULL;
      //Performing the reverse.
      while(curr!=NULL){
        upcoming = curr->next; //preserved the address of whole linked list before reversing the relation so that we don't lose the LL.
        curr->next = prev; //Reverse the relation 
        prev = curr; //Move the prev to next node
        curr = upcoming; //Move the curr to next node
        //upcoming will get automatically moved to next node because of the preservation step.
     } return prev; //prev becomes the new head.this is list.reverse_LL();
    } 
};
int main(){
    LinkedList list;
    list.pushFront(3);
    list.pushFront(2);
    list.pushBack(4);

    cout << "Original List: ";
    list.print();

   list.head = list.reverse_LL(); //assigning the return value(i.e,list.reverse_LL) of reverse() fn to head which is inside the linked list class.

    cout << "Reversed List: ";
    list.print(); 

    return 0;
}
// Note :-
// the order of the reverse perform should be this only else we'll lose the address of any of the Nodes.