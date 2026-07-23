#include <iostream>
#include <vector>
using namespace std;

// ======================= MAX HEAPIFY =======================
// Is function ka kaam hai ki maan lo idx par heap property toot gayi hai,
// to us node ko niche bhejte hue Max Heap property wapas maintain karna.

void maxHeapify(vector<int>& nums, int idx, int n){

    // Jab tak swapping ki zarurat pade
    while(true){

        // Current node ke left aur right child ke indices
        int leftChild = 2*idx + 1;
        int rightChild = 2*idx + 2;

        // Assume karo current node hi sabse bada hai
        int largest = idx;

        // Agar left child exist karta hai aur bada hai
        if(leftChild < n && nums[leftChild] > nums[largest])
            largest = leftChild;

        // Agar right child aur bhi bada hai
        if(rightChild < n && nums[rightChild] > nums[largest])
            largest = rightChild;

        // Agar current node hi largest hai,
        // matlab heap property satisfy ho gayi
        if(idx == largest)
            break;

        // Warna current node ko largest child ke saath swap karo
        swap(nums[largest], nums[idx]);

        // Ab jis position par current element gaya hai,
        // wahi se fir check karna hoga
        idx = largest;
    }
}


// ======================= MIN HEAPIFY =======================
// Max Heapify ka ulta.
// Current node ko niche bhejte hue Min Heap property maintain karta hai.

void minHeapify(vector<int>& nums, int idx, int n){

    while(true){

        // Left aur Right child
        int leftChild = 2*idx + 1;
        int rightChild = 2*idx + 2;

        // Assume current node hi smallest hai
        int smallest = idx;

        // Left child chhota hai?
        if(leftChild < n && nums[leftChild] < nums[smallest])
            smallest = leftChild;

        // Right child aur bhi chhota hai?
        if(rightChild < n && nums[rightChild] < nums[smallest])
            smallest = rightChild;

        // Agar current node already smallest hai
        if(idx == smallest)
            break;

        // Chhote child ke saath swap karo
        swap(nums[smallest], nums[idx]);

        // Neeche wali position se fir check karo
        idx = smallest;
    }
}


// ======================= BUILD MAX HEAP =======================
// Kisi bhi random array ko Max Heap mein convert karta hai.

void buildMaxHeap(vector<int> &nums, int n){

    // Last non-leaf node se start karte hain
    // Aur har node par Heapify Down chalate hain
    for(int i = n/2 - 1; i >= 0; i--){

        maxHeapify(nums, i, n);
    }
}


// ======================= BUILD MIN HEAP =======================
// Random array ko Min Heap mein convert karta hai.

void buildMinHeap(vector<int> &nums, int n){

    // Last non-leaf node se start
    for(int i = n/2 - 1; i >= 0; i--){

        minHeapify(nums, i, n);
    }
}


// ======================= PRINT =======================

void print(vector<int> nums){

    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << endl;
}


int main(){

    // Random Array
    vector<int> nums = {23, 5, 18, 76, 24, 6, 45, 123, 9, 56};

    // Max Heap bana do
    buildMaxHeap(nums, nums.size());

    cout << "Max Heap : ";
    print(nums);

    // Isi array ko Min Heap mein convert karo
    buildMinHeap(nums, nums.size());

    cout << "Min Heap : ";
    print(nums);

    return 0;
}
// | Operation      | Time Complexity |
// | -------------- | --------------- |
// | Heapify        | **O(log n)**    |
// | Build Max Heap | **O(n)**        |
// | Insert         | **O(log n)**    |
// | Delete Root    | **O(log n)**    |
// | Heap Sort      | **O(n log n)**  |
