#include <iostream>
using namespace std;

int main()
{
    int n = 6;                          // size of array
    int pos = 3;                        // Index of element to be deleted.
    int arr[n] = {2, 4, 1, 7, 9, 1};
    for (int i = pos; i < n - 1; i++){
        arr[i] = arr[i + 1];            // 7 becomes 9, 9 becomes 1. i.e, new array = {2,4,1,9,1,1}
    }
    n--; //size of array is reduced     // last 1 is removed. array after deletion = {2,4,1,9,1} , we can see 7 is removed.
    cout << "Array after deletion: { ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";          // Output : 2 4 1 9 1 (7 is removed).
        
    } cout<<"}"<<endl;
    return 0;
}