#include <iostream>
#include <string>
using namespace std;
void RevChArr(char A[], int n){  // Function to reverse a character array
    int st = 0, end = n - 1;     // Start and end indices
    while (st <= end){          
        swap(A[st++], A[end--]); //Swap st and end, then move pointers accordingly.
    }
}

int main(){
    char A[] = {'H', 'E', 'L', 'L', 'O', '\0'}; // Eg char array.
    int n = 6;
    RevChArr(A, n);
    cout << "Reversed character array : ";   
    for (int i = 0; i < n; i++){               //print the array.
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
// OUTOUT :-
// Reversed character array : O L L E H 
//TC - O(n).