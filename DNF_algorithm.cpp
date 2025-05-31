#include <iostream>
#include <vector>
using namespace std;
void colorSort(vector<int> &A){
    int n = A.size();
    int mid = 0, low = 0, high = n - 1; //three pointers.
    while (mid <= high){
        if (A[mid] == 0){ 
            swap(A[mid], A[low]); //swap the values
            mid++, low++; //move the low and mid to right.
        }
        else if (A[mid] == 1){ 
            mid++;   //move the mid to right so that the partition of 1 gets big by one on right side.
        }
        else{
            swap(A[mid], A[high]); //swap the values.
            high--;  //move the high to left so that the partition of 2 gets big by one on left side.
        }
    }
}

int main(){
    vector<int> A = {1, 0, 2, 0, 1, 1, 2, 2, 0, 1}; // Eg Array.
    int n = A.size();
    colorSort(A); // FN call
     cout<<"[ ";
    for (int i = 0; i < n; i++){ //Print Sorted Array.    
        cout << A[i] << " ";
    }
  cout<<"]";
    return 0;
}

// output :-
// [ 0 0 0 1 1 1 1 2 2 2]
// TC - O(n), SC - o(1).
