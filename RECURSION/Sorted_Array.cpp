#include <iostream>
#include <vector>
using namespace std;
bool isSorted(vector<int> &A, int n){
    if (n == 1 || n == 1){ //Base case.
        return true;
    }
return A[n - 1] >= A[n - 2] && isSorted(A, n - 1); //Condition for sorted and recursion call
}
int main(){
    vector<int> A = {1, 3, 5, 8, 9};
    int n = A.size();
    if (isSorted(A, n)){
        cout << "Sorted." << endl;
    }
    else {
        cout << "Not Sorted." << endl;
    }
    return 0;
}