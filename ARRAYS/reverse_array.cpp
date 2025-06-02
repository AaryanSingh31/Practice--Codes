#include <iostream>
using namespace std;
void RevArr(int arr[], int size){     //fn to reverse the array.
    int start = 0;                    //index.
    int end = (size - 1);             //index.
    while (start < end){              
        swap(arr[start], arr[end]);   //built in c++ fn (swap) to swap the values.
        start++;                      //to increase the start to next index.
        end--;                        //to decrease the end to previous index.
    }
}

int main() {
    int arr[] = {3, 1, 4, 7, 11};     //array creation.
    int size = 5;                      
    RevArr(arr, size);                //calling the fn.
    for (int i = 0; i < size; i++) {  // for printing the rev array. 
        cout << arr[i] << " ";
    }

    return 0;
}
 //Output : 11 7 4 1 3
 // Time Complexity: O(n).