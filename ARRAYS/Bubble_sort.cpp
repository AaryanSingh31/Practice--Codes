#include <iostream>
#include <vector>
using namespace std;

    //Fn to sort the array.
void bubbleSort(vector<int> &arr, int n){
    for (int i = 0; i < n - 1; i++){
        bool isSwap = false;                 //Fn to avoid loops if the elements are already sorted.
        for (int j = 0; j < n - i - 1; j++){ //Fn to swap adjacent elements.
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);    //Built in Swap fn.
                isSwap = true;               //if swap is done, store true.
            }
        }
        if (!isSwap){                        //if isSwap is false then exit the loop.
            return;
        }
    }
}
void printArr(vector<int> arr, int n){      //Fn to print array.
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main(){
    vector<int> arr = {4, 5, 2, 3, 1, 0};    //Example array.
    int n = 6;                               //sizeof array.
    bubbleSort(arr, n);                      //Fn call.
    cout << "The Sorted array is :-" << endl;
    cout << "[ ";
    printArr(arr, n);                        //print fn
    cout << "]";
    return 0;
}
