
// ****************** THIS ALGO IS TO FIND THE MAX SUBARRAY SUM WITH IN O(N) TIME COMPLEXITY.*************************************************
/*APPROACH-> If the Sum of the elements goes less than 0 .. INitialise the current sum to Zero because.. Those numbers from which the current sum
was getting less than Zero can never be the part of the SubArray with maxSum.
*/

#include <iostream>
using namespace std;

int main(){
    int n = 7;
    int arr[]= {3,-4,1,7,5,-2,8};
   int maxSum = INT_MIN;
   int currSum = 0;
  for(int i =0; i<n; i++){
      currSum += arr[i];
      maxSum=max(currSum, maxSum);
      if(currSum<0){ //Resets to the new possible Subarray from the next Index.
        currSum = 0;
      }
  } 
    cout<<"Max SubArray Sum: "<<maxSum<<endl; //19
    return 0;
}
//TC -> O(n)


// Dry Run for: int arr[] = {3, -4, 1, 7, 5, -2, 8};
// n = 7
// Initial values:
// maxSum = INT_MIN
// currSum = 0

// Step-by-step dry run:
/*
i=0: arr[0]=3
    currSum = 0 + 3 = 3
    maxSum  = max(-∞, 3) = 3

i=1: arr[1]=-4
    currSum = 3 + (-4) = -1
    maxSum  = max(3, -1) = 3
    currSum < 0 → reset to 0

i=2: arr[2]=1
    currSum = 0 + 1 = 1
    maxSum  = max(3, 1) = 3

i=3: arr[3]=7
    currSum = 1 + 7 = 8
    maxSum  = max(3, 8) = 8

i=4: arr[4]=5
    currSum = 8 + 5 = 13
    maxSum  = max(8, 13) = 13

i=5: arr[5]=-2
    currSum = 13 + (-2) = 11
    maxSum  = max(13, 11) = 13

i=6: arr[6]=8
    currSum = 11 + 8 = 19
    maxSum  = max(13, 19) = 19
*/

// ✅ Final Output: Max SubArray Sum = 19
