                                  //******************Make A queue using fn of  stacks*********************/
#include <iostream>
#include <stack>

using namespace std;
stack<int> s1, s2;

//FN TO PUSH
void push(int val){ //O(n)
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(val);
    while(!s2.empty()){
     s1.push(s2.top());
     s2.pop();   
    }
}
//FN TO POP
void pop(){ //O(1)
    if(s1.empty()){
        return;
    } else {
    s1.pop();
    }
}
//FN TO return front of the queue
int front(){ //O(1)
     if(s1.empty()){
         return -1;
    }
    return s1.top();
}
//CHK IF THE STACK S1/Q IS EMPTY.
bool isEmpty(){
    return s1.empty();
}
//Fn to display
void displayQueue(){
    if(s1.empty()){
        cout << "Queue is empty" << endl;
        return;
    }
    stack<int> temp = s1; // Create a temporary stack to hold the elements
    while(!temp.empty()){
        cout << temp.top() << " "; // Print the top element
        temp.pop(); // Remove the top element
    }
    cout << endl; // New line after displaying all elements
}

int main(){
push(1); //1
push(2); //1 2
push(3); //1 2 3
push(4); //1 2 3 4
displayQueue();// 1 2 3 4
 cout<<front()<<endl; //returns the front of the queue = 1
 pop(); //Removs the top of the stack which is equal to the front of the queue. = 1.
 pop(); //Removes 2
 displayQueue(); //3 4
 cout<<front()<<endl; // 3
    return 0;
}
// Note:-
// We can see.. We have created a queue implementation using stack.
// From LIFO to FIFO.