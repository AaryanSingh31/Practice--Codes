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
  Node * head;
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
    void print(){
        Node *temp = head; 
        while (temp != NULL){           
            cout << temp->data << "->";
            temp = temp->next;       
        }
        cout << "NULL" << endl;
    }
    Node* mergeList(Node* &head1, Node* &head2){
       if(head1==NULL){
             return head2;
       }
       if(head2==NULL){
             return head1;
       }
        if(head1->data <= head2->data){
           head1->next  = mergeList(head1->next, head2);
           return head1;
        } if(head1->data > head2->data){
           head2->next  =  mergeList(head1, head2->next);
           return head2;
        }
     return NULL;
    } 
};
int main(){
LinkedList list1, list2;
list1.pushBack(1);
list1.pushBack(3);
list1.pushBack(5);
list1.pushBack(7);
cout<<"Sorted List1 : ";
list1.print();
list2.pushBack(2);
list2.pushBack(4);
list2.pushBack(6);
cout<<"Sorted List2 : ";
list2.print();
Node* merge = list1.mergeList(list1.head, list2.head);
   Node* temp = merge;
   cout<<"Merged Sorted List : ";
   while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
   }
   cout<<"NULL";
   return 0;
}
