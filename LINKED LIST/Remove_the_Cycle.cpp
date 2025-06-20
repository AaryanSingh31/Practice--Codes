#include <iostream>
using namespace std;
class Node {
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
Node* head;
 LinkedList(){
    head = NULL;
}
    void push_back(int value){
 Node* newNode = new Node(value);
     if(head==NULL){
       head = newNode;
       return;
     }
     Node* temp = head;
     while(temp->next!=NULL){
        temp = temp->next;
     }
     temp->next = newNode;
  } 
     //FN TO MAKE A CYCLE.

  void makeCycle(int pos){ //pos = jis bhi node se cycle st karna ho uska position. pos = 0 means index = 0 i.e, head se hi cycle ko st krna hai.
    Node* temp = head;
    Node* stNode = NULL; //To store the start of the cycle
    int count = 0; //local variable for counting ki hum ab kis position pe hain.
    //Traverse till the last node
    while(temp->next!=NULL){

        if(count==pos){ //jaise hi hum apni cycle st wali position pe pahuch jayen toh,
          stNode = temp;//Us position ko(jo ki temp pointer hoga) stNode pointer mein store kara lenge.
        }
        temp = temp->next; //temp ko update krte rahenge till it reaches NULL.
        count++; // Position(Local Index) ko update krte rahege to get the position of the current node.
    }//CYCLE CREATION.
    if(stNode !=NULL){    //If hmari stNode NULL nhi hai toh,
      temp->next = stNode;//Temp->next is the last node and uske next ke andar stNode pointer ko store kara diya.. i.e, last Node is now connected to stNode(jaha se cycle shuru hai)
    }
  }
  void  detectAndRemoveCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            isCycle = true;
            break;
        }
    }
    if(!isCycle){
         return;  
        }
   //The Cycle Exists.
        slow = head;
        Node* prev = NULL; // we need to store the last Node
        while(slow!=fast){
            slow = slow->next;
            prev = fast; //to store the previous value of fast.. i.e, when slow becomes equal to fast(start of the cycle) prev will the at the last Node.
            fast = fast->next;
        }
        prev->next = NULL; // we point the last Node's Node to NULL(which was initially pointing to a Node i.e, a Cycle) .. i.e, we removed the cycle.
    }
     void print(){
        Node *temp = head; // ek temporary pointer bnaya jisko head se initialise kiya.
        while (temp != NULL){                               // temp jb tk chlte chlte end pe na pahuch jaye tb tk,
            cout << temp->data << "->"; // temp pointer(jiske pass current node ka address h) ke address ki help se us node ke andar ke data ko cout kardo
            temp = temp->next;          // temp ko update krke agle node pe le jao..
        }
        cout << "NULL" << endl;
    }
};
int main(){
LinkedList list;
list.push_back(10);
list.push_back(20);
list.push_back(30);
list.push_back(40);
list.makeCycle(1);
list.detectAndRemoveCycle(list.head);
list.print();
    return 0;
}
//Bhai, chal ek solid dry run karte hain

/*Phase 1: Creating the Linked List
list.push_back(10); // head -> 10
list.push_back(20); // head -> 10 -> 20
list.push_back(30); // head -> 10 -> 20 -> 30
list.push_back(40); // head -> 10 -> 20 -> 30 -> 40


Linked list ab kuch aisa hai:
10 -> 20 -> 30 -> 40 -> NULL

Phase 2: Creating the Cycle
list.makeCycle(1);

Yeh kya karega:
- Traverse karega list mein aur position 1 wali node dhundega (that’s node with data = 20)
- Last node (40) ka next us 20 node pe point kar dega
So now, last node points to 20:
10 -> 20 -> 30 -> 40
       ↑           ↓
       ←  ← ← ← ← ← 


So now it’s a cycle starting from node 20.

Phase 3: Detect & Remove Cycle
list.detectAndRemoveCycle(list.head);


Let’s dry run this inside the function:
- Cycle Detection (Floyd’s Algorithm):
- slow = head, fast = head
- Iteration 1: slow = 20, fast = 30
- Iteration 2: slow = 30, fast = 20
- Iteration 3: slow = 40, fast = 40 → They meet! Cycle exists!
- Cycle Removal:
- Now reset slow = head (10)
- fast is already at the meeting point, which is 40
- Keep advancing:
- slow = 10, fast = 40, prev = NULL
- slow = 20, fast = 20, prev = 40
- They now meet at start of cycle 20, so prev is at 40
- Do prev->next = NULL
Boom! Cycle removed ✅
Now linked list is back to:
10 -> 20 -> 30 -> 40 -> NULL



Phase 4: Printing the List
list.print();


- temp = 10, prints 10->
- temp = 20, prints 20->
- temp = 30, prints 30->
- temp = 40, prints 40->
- temp = NULL, prints NULL
So final output:
10->20->30->40->NULL
*/