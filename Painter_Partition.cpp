#include <iostream>
#include <vector>
using namespace std;
 //Fn to check whether the mid value(maxAllowedTime) is a valid ans or not.
bool isPossible(vector<int> &A, int k, int n, int maxAllowedTime){
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++){ //No extra painter needed.
        if (time + A[i] <= maxAllowedTime){
            time += A[i]; 
        }
        else{ //Extra painter needed
            painters++;
            time = A[i]; //Assign the new time to new painter.
        }
    }
    return painters <= k; //return true if painter used < No. of painters we have.
}
    //Fn to cal the min time
int minTime(vector<int> &A, int k, int n){
    int sum = 0; 
    int maxVal = INT_MIN;
    for (int i = 0; i < n; i++){
        sum += A[i];                // Max time taken to paint the board.
        maxVal = max(maxVal, A[i]); // Min time taken to paint the board.

    // Range to apply Binary Search :-
    //  [maxVal,......mid........,sum]   
    }
    int start = maxVal, end = sum, ans = -1;
    while (start <= end){
        int mid = start + (end - start) / 2;
        if (isPossible(A, k, n, mid)){ //if isPossible fn return true then this condition will run.
            ans = mid;
            end = mid - 1; // Search in left to get to more minimum answer.
        }
        else{ // if mid is a notpossible answer then,
            start = mid + 1; //search in right.
        }
    }
    return ans;
}

int main(){
int k=3; //no of painters we have.
vector<int> A = {5, 10, 30, 20, 15}; //Boards to paint {their 1 unit area takes 1 unit of time to get painted.}
int n = A.size();        // total no of boards.
int res = minTime(A,k,n); //fn call
cout<<"Min time taken by "<<k<<" painters to paint all the boards is : "<<res<<" Units. "<<endl; //print the output.

    return 0;
}