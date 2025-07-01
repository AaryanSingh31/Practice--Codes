                                    //****************MAKE A STACK USING FNS OF QUEUE.************************
                                                       //****** LIFO from FIFO******
                                               //TOP OF STACK == THE FRONT OF Q1
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
// stack<int> s; // Remove this line, as we are implementing stack using queues
queue<int> q1, q2; //q1 will store the elements of stack in the lifo order and q2 ia helper queue.
//FN TO PUSH INTO STACK
void push(int x){ //O(n)
    //step(i) copy the elements of q1 to q2
    while(!q1.empty()){
        q2.push(q1.front()); //copy the elements from q1 to q2
        q1.pop(); //empty the q1
    }
    q1.push(x); //step(ii) push the new element to q1
//step(iii) copy back the elements from q2 to q1.
    while(!q2.empty()){
        q1.push(q2.front()); //copy the elements from q2 to q1
        q2.pop(); //empty the q2
  }
}
//FN TO POP TOP FROM STACK
void pop(){ //O(1)
    if(q1.empty()){
        cout << "Stack is empty" << endl;
        return;
    }
    q1.pop(); //pop the top element from q1 which will remove the top of the stack
}
//FN TO RETURN THE TOP OF THE STACK
int top(){ //O(1)
    return q1.front();
}
//CHK IF THE STACK IS EMPTY
bool isEmpty(){ //O(1)
    return q1.size()==0;
}
void print(){
    while(!q1.empty()){
cout<<q1.front()<<" ";
q1.pop();
    }
}
int main(){
    push(1); //1
    push(2); //2 1
    push(3); //3 2 1
    push(4); //4 3 2 1
    push(5); //5 4 3 2 1
    print(); //5 4 3 2 1
    cout<<top(); //5
    pop(); //removes 5
    pop(); //removes 4
    print();// 3 2 1
    cout<<top(); //3
    return 0;
}
// Note:-
// We can see.. We have created a stack implementation using queue.