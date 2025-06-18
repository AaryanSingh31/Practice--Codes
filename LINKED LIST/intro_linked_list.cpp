#include <iostream>
using namespace std;
class Node{ 
    public:
    int data;      //for data storage
    Node* next;    //next pointer for storing agli node's address into current node
    Node(int value){//constructor to initialising the value and 
        data = value;
        next = NULL;//next is null because it's not pointing to any node yet  
    }
};
class LinkedList{
    public : 
    Node* head;    //head pointer for starting of list
    LinkedList(){
     head = NULL;  //initialsie head to NULL.
    }
   //Fn to push back any value
   void pushBack(int value){
    Node * newNode = new Node(value); //newNode pointer for nayi node (creation of new node using Pointer's new keyword)
    if(head == NULL){   // If initially list has no elements then,
        head = newNode; //assign newNode pointer to head i.e,(head is now pointing to new Node formed.)
         return;        
    }    //Temp->next ka mtlb hai ki... woh address jo temp ke next pointer ke pass stored hai
   Node* temp = head; //temp pointer banaya usko head pointer pe point kara diya.
   while(temp->next!=NULL){ //jab tk temp NULL na ho jaye tb tak,
    //temp pointer ko update kr rhe hain.. 
    //mtlb ab temp agli node ko point karega kyuki temp->next hai agle node ka address and 
    //usey temp ke equal kardiya mtlb ab temp ke andar agle node ka address hai i.e, 
    //ab temp agle node ko point kar rha hai. i.e, temp update hoke aage bdh gya h.
      temp = temp->next;//(address of next node)      
   }
   //Jab loop end ho jaye mtlb jab temp NULL pe pahuch jaye traverse krte krte tab,
   // temp wali node ke andar newNode ka address daal do. (i.e, connect current node(if any) to newNode).
    temp->next = newNode;
   } 
   //Fn to add a node in front
   void pushFront(int value){
    Node* newNode = new Node(value);
    newNode->next = head; // New node ka next pointer ko current head wali node ka address store kara do i.e,(i.e, to connect both the list).
    head = newNode ; //head ko update karke newNode pe le aao kyuki naya node aage bana hai and head hmesa sabse aage rehta hai ..
   }
   //Fn to print the list
   void print(){
    Node * temp = head; // ek temporary pointer bnaya jisko head se initialise kiya.
    while(temp != NULL){//temp jb tk chlte chlte end pe na pahuch jaye tb tk,
        cout<<temp->data<<"->"; //temp pointer(jiske pass current node ka address h) ke address ki help se us node ke andar ke data ko cout kardo
        temp = temp->next; //temp ko update krke agle node pe le jao..
    }
    cout<<"NULL"<<endl;
   }
};
int main(){
LinkedList list; // Obj creation
list.pushBack(12);
list.pushBack(15);
list.pushBack(16);
list.pushFront(10);
list.pushFront(9);
list.pushFront(7);
list.pushFront(5);
list.print();


    return 0;
}
// Output :-
// 5->7->9->10->12->15->16