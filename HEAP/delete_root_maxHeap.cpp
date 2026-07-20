#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    public:
    //fn to delete element and then again heapify the remaining heap
    void deleteRoot(vector<int> &heap){
        //replace the root element to the last element.
        heap[0] = heap.back();

        //delete the new last element (root element)
        heap.pop_back();
        //Now logic to take that new first element to its right position
        int n = heap.size();
        int idx = 0; //heapify down starts with the root //idx is the index for the parent node.

        //heapify down the new first(root) element to its right position.
        while(true){
            int leftChild = 2*idx+1; //current node ka left child ka index
            int rightChild = 2*idx+2;//current node ka rfght child ka index
            int largest = idx; // set the current parent node as the largest

            //If left child exists && leftChild is larger than largest val then leftchild is marked as largest.
            if(leftChild < n && heap[leftChild] > heap[largest]) largest = leftChild; 
            //If right child exists && rightChild is larger than largest val then  rightChild is marked as largest.
            if(rightChild < n && heap[rightChild] > heap[largest]) largest = rightChild;
            //If the largest is already is the parent node .. ie, we've successfully heapify, break from the loop
            if(largest == idx) break;
            //else
            swap(heap[idx], heap[largest]); //swap the parent node with the largest child.

            idx = largest; //ab  jaha swap hua h wahi pe poora heapify karo firse.. uske liye us largest jo swap hua h usy parent node banana padgea aur parent node ka index hmne idx rkha tha toh idx ki val ko largest(largest element ki index) banana padega
        }
    }
    void print(vector<int> & heap){
        for(int i = 0 ; i < heap.size(); i++){
            cout<<heap[i] <<" ";
        }
        cout<<endl;
    }

};
int main(){
    MaxHeap h;
    vector<int> heap = {201, 30, 54, 10 , 15, 20, 5, 1}; //Maxheap is given .. We need to delete its root element.
    cout<<"Before deletion"<<endl;
    h.print(heap);
    h.deleteRoot(heap);
    cout<<"After Deletion"<<endl;
    h.print(heap);
    return 0;
}