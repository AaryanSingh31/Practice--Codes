#include <iostream>
#include <vector>
using namespace std;
       //FN FOR BINARY SEARCH WITHIN THE TARGET ROW
bool searchRow(vector<int> &midRow, int tar){
    int st = 0, end = midRow.size() - 1;
    while (st <= end){
        int mid = st + (end - st) / 2;
        if (tar == midRow[mid]){
            return true;      // found
        }
        else if (tar < midRow[mid]){  // search in left half
            end = mid - 1;
        }
        else {                // search in right half
            st = mid + 1;
        }
    }
    return false;
}
      //FN FOR FINDING THE TARGET IN THE MATRIX
bool searchMatrix(vector<vector<int>> &mat, int tar){
    int m = mat.size(), n = mat[0].size();
    int stRow = 0, endRow = m - 1;                               // Initialisation of row for BS across the rows.
    while (stRow <= endRow){
        int midRow = stRow + (endRow - stRow) / 2;
        if (tar >= mat[midRow][0] && tar <= mat[midRow][n - 1]){ //IF the target within the row
           return searchRow(mat[midRow], tar);                         //Call the fn
        }
        else if (tar < mat[midRow][0]){ // Search in upper row.
            endRow = midRow - 1;
        }
        else{                           // Search in lower row.
            stRow = midRow + 1;
        }
    }
    return false;
}
int main(){
    int tar = 30;
    vector<vector<int>> mat = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
        {60, 61, 62, 63}};
    if (searchMatrix(mat, tar)){
        cout << "Target found." << endl;
    }
    else{
        cout << "Target Not found." << endl;
    }
    return 0;
}
// Output:-
// Target found.