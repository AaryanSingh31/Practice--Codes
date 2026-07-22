#include <iostream>
#include <vector>

using namespace std;

//============================================= MAX HEAPIFY =============================================//
// Heapify Down
// Purpose:
// Agar idx par Max Heap property toot gayi ho,
// to us element ko niche bhejte hue Max Heap property wapas maintain karo.
//
// Parameters:
// nums      -> Heap
// idx       -> Jis node se Heapify start karni hai
// n         -> Current Heap Size

//this function is to heapify a single node
void heapify(vector<int> &nums, int idx, int n){

    while(true){

        // Left aur Right child ke indices
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;

        // Assume current node hi largest hai
        int largest = idx;

        // Agar left child bada hai
        if(leftChild < n && nums[leftChild] > nums[largest])
            largest = leftChild;

        // Agar right child aur bhi bada hai
        if(rightChild < n && nums[rightChild] > nums[largest])
            largest = rightChild;

        // Agar current node already largest hai
        // to Heap property satisfy ho gayi
        if(largest == idx)
            break;

        // Bade child ke saath swap karo
        swap(nums[largest], nums[idx]);

        // Jahan current element gaya hai,
        // wahi se fir Heapify continue hogi
        idx = largest;
    }
}


//============================================= BUILD MAX HEAP =============================================//
// Random Array ko Max Heap mein convert karta hai.
//
// Logic:
// Last Non-Leaf Node se start karke
// har node par Heapify Down chalao.
//This fn is to heapify the whole array or all the nodes one by one
void buildMaxHeap(vector<int> &nums){
    int n = nums.size();
    // Last Non-Leaf Node = n/2 - 1
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(nums, i, n);
    }
}


//============================================= HEAP SORT =============================================//
// Heap Sort Steps:
//
// 1. Build Max Heap
// 2. Root (Maximum Element) ko Last Unsorted Element se Swap karo
// 3. Heap Size 1 kam maan lo
// 4. Remaining Heap par Heapify Down chalao
// 5. Repeat until Heap Size = 1

void heapSort(vector<int> &nums){
    int n = nums.size();
    // Step 1 : Convert Array into Max Heap
    buildMaxHeap(nums);
    // Step 2 : Move Maximum Element to its Correct Position
    for(int i = n - 1; i > 0; i--){
        // Root (Maximum Element) ko last unsorted position par bhej do
        swap(nums[0], nums[i]);
        // Remaining Heap ko dobara Max Heap banao = > bas new root element ko uski sahi pos pe pahuchana h baki maxHeap already hai.
        // Heap Size = i //jo largest node swap hoke last mein pahuchi h usey heapify nhi krna h isliye heapify ka size uske index se chhota rakhte hain
        heapify(nums, 0, i); //index idx = 0 isliye put kiya h kyuki hme bas first wali new node jo swap ho gyi h usey sahi position pe lana h baki poora array already heapified hai isliye heapify ko call kiya us ek node ko sahi pos pe pahuchane k lie aur na hi buildMaxHeap
    }
}


//============================================= PRINT =============================================//

void print(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int main(){

    // Random Unsorted Array
    vector<int> nums = {12, 4, 2, 21, 32, 8, 10, 5, 1, 14};
    cout<<"Array Before Heap Sort\n";
    print(nums);
    // Heap Sort
    heapSort(nums);
    cout<<"\nArray After Heap Sort\n";
    print(nums);
    return 0;
}

//TC of heap sort 

// | Operation         | Complexity     |
// | ----------------- | -------------- |
// | Build Max Heap    | **O(n)**       |
// | Heapify n−1 times | **O(n log n)** |
// | Total             | **O(n log n)** |
// | Extra Space       | **O(1)**       |
