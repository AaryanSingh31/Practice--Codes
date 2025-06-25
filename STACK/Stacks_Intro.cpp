
//*******************STACKS USING STL stack LIBRARY**********************

/*
#include <iostream>
#include <stack>
using namespace std;

int main(){
stack <int> s; //this is the way of creating a stack.
s.push(10); //to Insert the value stack 10
s.push(20); //to Insert the value stack 20 10
s.push(30); //to Insert the value stack 30 20 10
cout<<s.top()<<endl;; //30
s.pop(); //removes the 30(the top element)
cout<<s.top()<<endl;; //20 is the new top after removing 30.
cout<<s.size()<<endl;;//2 after pop
    //PRINTING THE STACK.
while(s.size()!=0){
cout<<s.top()<<" ";
s.pop();
} cout<<endl;
 //output - 20 10
    return 0;
}
 */

 // ***************STACKS USING ARRAY/VECTORS********************
/*
 #include <iostream>
 #include <vector>
 using namespace std;
 class Stack{
vector<int> v;
public :
//fn to push the val to stack
void push(int val){
    v.push_back(val); 
}
//fn to get the top of the stack
int top(){
   return v[v.size()-1]; //element of last index of array/vector.
}
//fn to remove the top element.
void pop(){
    v.pop_back();
   }
//fn to check if the stack is empty.   
 bool isEmpty(){
    return v.size()==0;
   }
  };
int main(){
Stack s;
s.push(100); //100
s.push(200); //200 100
s.push(300); //300 200 100
cout<<"Top Before Pop : ";
cout<<s.top()<<endl;//300
s.pop();// removes the last/top = 300
cout<<"Top after Pop : ";
cout<<s.top()<<endl; //200
//printing the stack till it becomes empty.
cout<<"Stack : ";
while(!s.isEmpty()){
    cout<<s.top()<<" ";
    s.pop();
}
return 0;
Output - 200 100
}
*/
 
//*******************STACKS USING LINKED LISTS.**************************

#include <iostream>
 #include <list>
 using namespace std;
 class Stack{
list<int> ll;
public :
//fn to push the val to stack
void push(int val){
    ll.push_front(val); 
}
//fn to get the top of the stack
int top(){
   return ll.front(); //element of last index of array/vector.
}
//fn to remove the top element.
void pop(){
    ll.pop_front();
   }
//fn to check if the stack is empty.   
 bool isEmpty(){
    return ll.size()==0;
   }
  };
int main(){
Stack s;
s.push(10); //10
s.push(20); //20 10
s.push(30); //30 20 10
cout<<"Top Before Pop : ";
cout<<s.top()<<endl;//30
s.pop();// removes the last/top = 30
cout<<"Top after Pop : ";
cout<<s.top()<<endl; //20
//printing the stack till it becomes empty.
cout<<"Stack : ";
while(!s.isEmpty()){
    cout<<s.top()<<" ";
    s.pop();
}
return 0;
//output - 20 10
}