#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &arr, int target){
    int start = 0, end = arr.size() - 1;
    while (start <= end){
        int mid = start + (end - start) / 2; //Calculate mid index.
        // Check if the middle element is the target.
        if (arr[mid] == target){
            return mid;
        }
        if (arr[start] <= arr[mid]){ // left sorted
            if (arr[start] < target && target <= arr[mid]){ // search in left half
                end = mid - 1;
            }
            else{ // search in right half
                start = mid + 1;
            }
        }
        else{     // right sorted
            if (arr[mid] < target && target <= arr[end]){ // search in right half.
                start = mid + 1;
            }
            else{ // searh in left half.
                end = mid - 1;
            }
        }
    }
    return -1;    // Target not found.
}
int main(){

vector<int> arr = {4, 5, 6, 7, 0, 1, 2};     // Example input.
    int target = 1;                          // Target to search.
    int index = search(arr, target);         // fn call.
    if (index != -1){
        cout << "Element found at index: " << index << endl;
    }
    else{
        cout << "Element not found." << endl;
    }
    return 0;
}