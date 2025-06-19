                     //HOW DOES A CYCLE IN LL LOOKS LIKE
        // EG-  1->2->3->4->5   //here cycle/loop starts from 3.
     //               |     |           
//                    |_____|
//

//LOGIC TO DETECT A CYCLE - NORMALLY SLOW POINTER DOESN'T CATCHUP WITH FAST POINTER BUT,
//IF SLOW AND FAST POINTER MEETS SOMEWHERE I.E, THERE EXISTS A LOOP AND THE FAST POINTER RUNS THROUGH THE LOOPS AND MEETS THE SLOW POINTER.

#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = NULL;
    }
};
class LinkedList{
public:
    Node *head;
    LinkedList(){
        head = NULL;
    }
    // Fn to push back
    void pushBack(int value){
        Node *NewNode = new Node(value);
        if (head == NULL){
            head = NewNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = NewNode;
    }
    // Fn to push front
    void pushFront(int value){
        Node *NewNode = new Node(value);
        Node *temp = head;
        NewNode->next = head;
        head = NewNode;
    }
      void print(){
        Node *temp = head; 
        while (temp != NULL){           
            cout << temp->data << "->";
            temp = temp->next;       
        }
        cout << "NULL" << endl;
    }
  //FN TO DETECT THE CYCLE
  bool hasCycle(Node*head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    if(slow == fast){ //Cycle Exists
        return true;
     }
   }
    return false;     //Cycle Doesn't Exists.
 }  
};
int main(){
    LinkedList list;
    list.pushFront(3);
    list.pushFront(2);
    list.pushBack(4);
    list.pushFront(1);
    list.pushBack(5);
    list.pushBack(6);
    list.print();
    if(list.hasCycle(list.head)){
        cout<<"Cycle Exists."<<endl;
    } else{
        cout<<"No Cycle Exists."<<endl;
    }
    return 0;
}
// Output :-
// 1->2->3->4->5->6->NULL
// No Cycle Exists