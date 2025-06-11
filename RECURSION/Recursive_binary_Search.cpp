#include <iostream>
#include <vector>
using namespace std;
int getIdx(vector<int> &arr, int tar, int st, int end){
    int mid = st + (end - st) / 2;
    if (st > end){           //BASE CASE.
        return -1;
    }
    if (arr[mid] == tar){
        return mid;
    }
    else if (arr[mid] < tar){ //Search in right half
        return getIdx(arr, tar, mid + 1, end);
    }
    else{               //Search in left half.
        return getIdx(arr, tar, st, mid - 1);
    }
}
int main(){
    vector<int> arr = {2, 5, 7, 10, 12, 16};
    int tar = 12;
    int st = 0, end = arr.size() - 1;
    cout << getIdx(arr, tar, st, end);
    return 0;
}
// Output :-
// 4
// TC -> O(logn)
// SC -> O(logn)