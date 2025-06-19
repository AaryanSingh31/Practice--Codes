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
     //FN TO FIND THE MIDDLE NODE OF THE LINKED LIST.
    Node * mid(Node* head){ //RETURN TYPE OF FN IS POINTER.
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* slow = head; //slow pointer moves by 1 node.
        Node* fast = head; //fast pointer moves by 2 nodes.

     //loops runs until the fast pointer reaches the end and the next pointer of the fast points to null of the linkedlist.
        while(fast!= NULL && fast->next != NULL){ 
            slow = slow->next;      //1 node
            fast = fast->next->next;//2 nodes
        }
        // At the end of the while loop, slow pointer will be at the middle of the LL
        return slow;
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

    Node* middleNode = list.mid(list.head); //pointer middleNode is the return value of mid fn.
if (middleNode != NULL)
    cout << " Value at Middle node: " << middleNode->data << endl;
    return 0;
}
// Output:-
// 1->2->3->4->5->NULL
// Value at Middle Node: 3
// if list has even no of nodes then,
// 1->2->3->4->5->6->NULL
// Value at the middle node: 4 .. which is the second middle term
