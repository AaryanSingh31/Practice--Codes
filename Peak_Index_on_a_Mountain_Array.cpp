#include <iostream>
#include <vector>
using namespace std;

int mountPeak(vector<int> &A){
      //we Take start from 1 and End -2 To Avoid Corner Problems i.e, Peak can't be 1st and last element.
    int start = 1, end = A.size() - 2;       
    while (start <= end){
        int mid = start + (end - start) / 2; //optimal way of Finding mid.
       //Condition if the Mid itself the answer. 
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]){
            return mid;
        }
      // Search for Peak in right side of mid. 
        if (A[mid - 1] < A[mid]){ 
            start = mid + 1;
        }
      // Search for Peak in left side of mid. i.e, (A[mid-1]>A[mid])  
        else{ 
            end = mid - 1;
        }
    }
    return -1; // if not found.
}
int main(){
    vector<int> A = {0, 3, 5, 7, 9, 2, 8, 1}; // Example Array.
    int res = mountPeak(A);
    cout << "Index of the peak Element : " << res << endl;
    cout << "Peak Element is : " << A[res] << endl;
    return 0;
}
       //output :-
       //Index of the peak Element : 4
       //Peak Element is : 9