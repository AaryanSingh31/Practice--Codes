#include <iostream>
#include <vector>
using namespace std;
void dupZero(vector<int> &arr)
{
    int n = arr.size();
    int zeroes = 0;
        // Count the number of zeroes in the array.
    for (int i = 0; i < n; i++){
        if (arr[i] == 0){
            zeroes++;
         //total zeroes = 2.   
        }
    }
        //backward for loop.
    for (int i = n - 1; i >= 0; i--){   
        // Shift the elements to the right.
        // If the current element is not zero, shift it to the right by the number of zeroes.
        if (i + zeroes < n){
            arr[i + zeroes] = arr[i];
        }
        // If the current element is zero, we need to duplicate it.
       
        if (arr[i] == 0){
            zeroes--;  // Decrease the number of zeroes to be duplicated.
        // If the current index + number of zeroes is within bounds, duplicate the zero.
            if (i + zeroes < n){
                arr[i + zeroes] = 0; 
            }
        }
    }
}

int main(){
    vector<int> arr = {1, 0, 2, 0, 5, 3, 6}; // Example input.
    dupZero(arr); //fn call.
    // Print the modified array.
    cout << "Array after duplicating zeroes: { ";
    for (int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "}";
    return 0;
}
// Time complexity: O(n), where n is the size of the array.

// Output :-
// for i=6, arr[6]=6 -> Out of bounds.
// for i=5, arr[5]=3 -> Out of bounds.
// for i=4, arr[4]=5 -> i(4)+zeroes(2)= 6 < 7, So arr[4+2]=arr[6]=6->5. New array is {1,0,2,0,5,3,5}.
// for i=3, arr[3]=0 -> i(3)+zeroes(2)= 5 < 7, So arr[3+2]=arr[5]=3->0. New array is {1,0,2,0,5,0,5}, and also arr[3]=0 So zeroes-- and new zeroes=1.
// for i=3 again Second loop will run i.e, arr[3+1]= arr[4]=5->0. New array is {1,0,2,0,0,0,5}.
// for i=2, arr[2]=2 -> i(2)+zeroes(1)= 3 < 7, So arr[2+1]=arr[3]=2->2. New array is {1,0,2,2,0,0,5}.
// for i=1, arr[1]=0 -> i(1)+zeroes(1)= 2 < 7, So arr[1+1]=arr[3]=2->0. New array is {1,0,0,2,0,0,5}, and also arr[1]=0 So zeroes-- and new zeroes=0.
// for i=1 again Second loop will run i.e, arr[1+0]= arr[1]=0->0. New array is {1,0,0,2,0,0,5}.
// for i=0, arr[0]=1 -> i(0)+zeroes(0)= 0 < 7, So arr[0+0]=arr[0]=1->1. New array is {1,0,0,2,0,0,5}.

// Final output is {1,0,0,2,0,0,5}.

