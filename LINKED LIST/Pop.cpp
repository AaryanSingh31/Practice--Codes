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
    // Fn to remove the Node from the end
    void popBack(){
        Node *temp = head;
        if (head == NULL){ // If the list is empty
            return;
        }
        if (head->next == NULL){ // If the list contains only 1 node
            delete head;
            head = NULL;
            return;
        } // For more than 1 Nodes
        while (temp->next->next != NULL){   // temp->next->next is the second last node.
            temp = temp->next; // loop stops where temp points to second last node which later will become our last node.
        }
        delete temp->next; // i.e, deleting the address of last Node from the second last node's next pointer.
        temp->next = NULL; // Now after deleting .. temp next(Nayi last node) should have something valid in its next pointer Inshort we point it to NULL cuz the next pointer of last node should point to null.
                           // Also Delete keyword only deletes the memory and not the variables or pointers.
    }
    // Fn to remove the node from the start of the list.
    void popFront(){
        if (head == NULL){ // If the list is empty
            return;
        }
        if (head->next == NULL){ // If the list contains only 1 node
            delete head;
            head = NULL;
            return;
        }
        // If the list has more than two nodes.
        Node *temp = head; // pointer to store the address of 1st node so that our whole list doesn't lost from us.
        head = head->next; // move the head to Second Node.
        delete temp; // Delete the first node
         
    }
    // Fn to print the list
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
    LinkedList list; //Obj creation.
    list.pushBack(5);
    list.pushFront(3);
    list.pushFront(2);
    list.pushBack(6);
    list.print();   //Output=>>  2->3->5->6->NULL
    list.popBack();
    list.print();   //Output=>>  2->3->5->NULL
    list.popFront();
    list.print();   //Output=>>  3->5->NULL

    return 0;
}