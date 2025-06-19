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
Node* head;
LinkedList(){
    head = NULL;   
}
//FN TO CHK THE CYCLE AND FIND THE START OF THE CYCLE IF EXISTS.
Node* isCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false; //initialise the cycle as false.
    while(fast!=NULL && fast->next!=NULL){ //to find the if the cycle exists.
        slow = slow->next;
        fast = fast->next->next;
      if(slow == fast) //if exists
        isCycle = true;//reset the isCycle to true and,
        break;         //break from the loop so that our value of pointers get preversed.
    }
    if(!isCycle){      //If cycle doesn't exists 
    return NULL;       //return nullptr.
    }
    //IF NULL IS NOT RETURNED THAT MEANS THE CYCLE EXISTS. SO WE INITIALISE THE SLOW AGAIN TO HEAD 
    slow= head;
    //when the loop will stop, both slow and end will be at the same node and that node will be the start of the cycle. 
    while(slow!=fast){   
        slow = slow->next; //slow starts to move 1 node from the start of the ll
        fast = fast->next; //fast starts to move 1 node (not 2) from where we take the break from the loop earlier.
    }
   return slow; //return the start of the cycle. 
}
};
int main(){
    //IDK HOW TO CREATE A CYCLE IN THE LL SO I'M LEAVING IT UPTO YOU.
    return 0;
}