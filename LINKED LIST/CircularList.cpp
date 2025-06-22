   // CIRCULAR LIST => THE TAIL POINTS TO HEAD INSHORT .. TAIL->NEXT = HEAD ..
   //NOTE - IF HEAD IS NOT GIVEN WE CAN USE TAIL->NEXT CUZ IT IS HEAD.
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
class CircularList{
public:
Node* head;
Node* tail;
CircularList(){
    head = tail = NULL;
  }
  //FN TO INSERT AT FRONT.
void insertAtFront(int value){
    Node* NewNode = new Node(value); //NODE CREATION.
    if(head==NULL){         //IF LIST IS EMPTY.
     head = tail = NewNode;
     tail->next = head; //LINK TO CIRCLE
    } else{
        NewNode->next = head;// LINK NEW NODE TO HEAD
        head = NewNode;     // UPDATE HEAD TO NEW NODE
        tail->next = head; // OR tail->next = head,  both are same thing. CIRCULAR LINK.
    }
}
//FN TO INSERT AT BACK.
void insertAtBack(int value){
    Node* NewNode = new Node(value);
    if(head==NULL){
        head = tail = NewNode;
        tail->next = head;
    } else {
         NewNode->next = head; // LINK NEW NODE TO HEAD FOR CIRCULARITY
         tail->next = NewNode; // LINK TAIL TO NEW NODE
         tail = NewNode;      //UPDATE TAIL TO NEW NODE.
    }
}
//FN TO DELETE AT FRONT/HEAD.
void deleteAtFront(){
    if(head==NULL){
        return;
    } else if(head==tail){
        delete head; //DELETE THE ONLY NODE
        head = tail = NULL; //SET HEAD AND TAIL TO NULL
    } else{
        Node* temp = head;
        head = head->next; //MOVE HEAD TO NEXT NODE
        tail->next = head; //TAIL POINTS TO NEW HEAD (CIRCULARITY)
        temp->next = NULL; //REMOVE FORWARD LINK FROM OLD HEAD
        delete temp; //DELETE OLD HEAD
    }
}
//FN TO DELETE AT BACK/TAIL.
void deleteAtBack(){
    if(head==NULL){
        return;
    } else if(head==tail){
        delete head; //DELETE THE ONLY NODE
        head = tail = NULL; //SET HEAD AND TAIL TO NULL
    } else{
        Node* temp = head;
       while(temp->next != tail){
            temp = temp->next;
       }
         //NOW TEMP POINTS TO THE NODE BEFORE TAIL.
         
         tail->next = NULL; //REMOVE FORWARD LINK FROM TAIL
         delete tail; //DELETE TAIL deletes only memory and the not the tail variable
         tail = temp; //UPDATE TAIL TO THE NODE BEFORE TAIL i.e, NEW TAIL.
         tail->next = head; //UPDATE TAIL TO POINT TO HEAD (CIRCULARITY)
    }
}
            
// FN TO PRINT THE LIST.
void print(){
    if(head == NULL) return;
    Node* temp = head;
    do { //DO ONCE UNTIL THE LOOP START AGAIN.
        cout << temp->data << "->";
        temp = temp->next;
    } while(temp != head); //LOOP MOVES TO HEAD AFTER DO AND STOPS IN WHILE.
    cout <<head->data<<" and the circle continues "<<endl; // to visually show circularity
  }
};
   int main(){
CircularList list;

list.insertAtFront(2);
list.insertAtFront(1);
list.insertAtFront(0);
list.insertAtBack(3);
list.insertAtBack(4);
list.print();
list.deleteAtFront();
list.deleteAtBack();
list.print();
    return 0;
   }
//  Output:-
//  0->1->2->3->4->0 and the circle continues 
//  1->2->3->1 and the circle continues