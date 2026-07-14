#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
public:
    vector<int> heap;

    void insert(int val) {
        heap.push_back(val); //push the current val in heap

        int idx = heap.size() - 1; //current index 

        //loop runs again for every new element
        //inside the loop the logic is to heapify the current element.
        while (idx > 0) {
            int parent = (idx - 1) / 2; //find the parent index for the current index

            if (heap[parent] < heap[idx]) { //if current index element is greater than its parent's element then swapping is needed.
                swap(heap[parent], heap[idx]);
                idx = parent; //new current index would be the parent index so that if further upper swapping is needed, we can compare index with its parent(the upper one)
            } else {
                break; //if the current element is smaller than the parent's element then no need to run the loop for current inserted element.
            }
        }
    }

    void print() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;

    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(54);
    h.insert(201);
    h.insert(1);

    h.print();   // 20 15 10 5
}