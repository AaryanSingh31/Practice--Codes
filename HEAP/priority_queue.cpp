#include <bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> p; //maxheap .. This prioritises the max element of heap first.
    priority_queue<int, vector<int>, greater<int>> p1; //minHeap .. this prioritises the min element of heap first.
    p.push(20);
    p.push(10);
    p.push(30);
    p.push(12);
    p.push(15);
    p.push(8);
    p1.push(20);
    p1.push(10);
    p1.push(30);
    p1.push(12);
    p1.push(15);
    p1.push(8);


    cout<<p.top()<<endl; //returns the max el of heap
    cout<<p1.top()<<endl; //returns the min el of heap
    cout<<"Max Heap priority queue : ";
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<endl;
    cout<<"Min heap priority queue : ";
    while(!p1.empty()){
        cout<<p1.top()<<" ";
        p1.pop();
    }
    return 0;
}