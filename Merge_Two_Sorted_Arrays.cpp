#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &A, vector<int> &B, int m, int n){
    int idx = m + n - 1; // Index for the last position in A
    int i = m - 1, j = n - 1; // i for the last element in A, j for the last element in B
    while (i >= 0 && j >= 0){ //backwards loop travel
        if (A[i] >= B[j]){    //
            A[idx--] = A[i--];//Assign the larger value to the end of A
                              // and move the i of A and idx backwards.
        }
        else {                // If B[j] is larger than A[i]
            A[idx--] = B[j--];// Assign the larger value to the end of A
                              // and move the j of B and idx backwards.
        }
    }
    while (j >= 0){           // If there are remaining elements in B
        A[idx--] = B[j--];    // Assign the remaining elements of B to A
    }
}
int main(){
    vector<int> A = {4, 5, 6, 0, 0, 0, 0}; // A has enough space for B
    vector<int> B = {1, 3, 7, 9};          // B is the array to be merged into A
    merge(A, B, 3, 4);                      //Fn call
           cout<<"Merge Sorted Array is - [ ";        
    for (int i = 0; i < A.size(); i++){    //Print the merged array.
        cout << A[i] << " ";
    }
           cout<<"]";
    return 0;
}

// OUTPUT:-
//Merge Sorted Array is - [1 3 4 5 6 7 9]
// Time Complexity: O(m + n) & Space Complexity: O(1)
// NOTE:-
// Eg-> A[idx--]=B[j--] means -> A[idx]=B[j] 
//                               idx--, j--; 