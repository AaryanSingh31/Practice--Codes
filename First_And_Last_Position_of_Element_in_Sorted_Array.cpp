#include <iostream>
#include <vector>
using namespace std;
vector<int> count(vector<int> &A, int target){
    int n = A.size();
    int first = -1, last = -1; //Initialising with -1 to indicate not found.
    int start = 0, end = n - 1;
    // Finding the first occurrence of target
    while (start <= end){
        int mid = start + (end - start) / 2;
        if (A[mid] == target){
            first = mid;
            end = mid - 1; // continue searching in the left half
        }
        else if (A[mid] < target){
            start = mid + 1; // target is in the right half
        }
        else{
            end = mid - 1; // target is in the left half
        }
    }
   start = 0, end = n - 1; // Reset start and end for the second search
    // Finding the last occurrence of target
    while (start <= end){
        
        int mid = start + (end - start) / 2;
        if (A[mid] == target){
            last = mid;
            start = mid + 1; // continue searching in the right half
        }
        else if (A[mid] < target){
            start = mid + 1; // target is in the right half
        }
        else{
            end = mid - 1; // target is in the left half
        }
    }
    return {first, last}; //this will return -1,-1 if the target is not found.
}

int main(){
    cout<<"The Array A = [2, 5, 7, 7, 8, 8, 8, 10]"<<endl;
      vector<int> A = {2, 5, 7, 7, 8, 8, 8, 10};
      int target1 = 8;
    cout<<"The Array B = [1, 2, 2, 4, 6, 6, 6]"<<endl;
      vector<int> B = {1, 2, 2, 4, 6, 6, 6};
      int target2 = 5;

    vector<int> result1 = count(A, target1);
    vector<int> result2 = count(B, target2);

    cout << "Array A: Index of target = " << target1<<" is "<<result1[0] << " to " << result1[1] << endl;
    cout << "Array B: Index of target = " << target2<<" is "<<result2[0] << " to " << result2[1] << endl;
   

    return 0;
}
// output:-
//  Array A : Index of 8 is 4 to 6.
//  Array B : Index of 5 is -1 to -1. (because 5 is not present in the array B).
