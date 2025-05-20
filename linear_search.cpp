<<<<<<< HEAD
#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int target){  

    for (int i = 0; i < size; i++){
        if (arr[i] == target){
            return i;                        // If found. 
        }
    }
    return -1;                               // If not found.
}
int main(){
    int arr[] = {2, 45, 10, 22, 8, 90};
    int size = 6;
    int target = 8;

    cout << linearSearch(arr, size, target);  //calling the fn.

    return 0;
}

// output :-
=======
#include <iostream>
using namespace std;
int linearSearch(int arr[], int size, int target){  

    for (int i = 0; i < size; i++){
        if (arr[i] == target){
            return i;                        // If found. 
        }
    }
    return -1;                               // If not found.
}
int main(){
    int arr[] = {2, 45, 10, 22, 8, 90};
    int size = 6;
    int target = 8;

    cout << linearSearch(arr, size, target);  //calling the fn.

    return 0;
}

// output :-
>>>>>>> bde8109 (Add linear search)
//  index => 4