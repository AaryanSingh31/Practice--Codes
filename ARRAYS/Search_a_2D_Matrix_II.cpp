#include <iostream>
#include <vector>
using namespace std;
bool searchMat(vector<vector<int>> &mat, int tar){
    int row = 0, col = mat[0].size() - 1; //Start from top right corner
    while (row <= mat.size() && col > 0){ // Loop conditions is because col moves left, and row moves downwards as the iteration goes on.  
        if (mat[row][col] == tar){        //If target at our assumed corner.
            return true;
        }
        else if (tar < mat[row][col]){    //If target is less than our assumed spot then,
            col--;                        //Move to left col as it contains smaller values than our assumed corner's col.
        }  else{                          //If target is greater than our assumed spot then,                             
           row++;                         //Move to next(down) row as it contains larger values than our assumed corner's row.
        }
    }
    return false;                         //If not found.
}
int main(){
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int tar = 13;
    if (searchMat(mat, tar)){
        cout << "Target Found." << endl;    //Eg tar = 14
    }
    else{
        cout << "Target Not found." << endl; //Eg tar = 31
    }
    return 0;
}
// Output:-
// Target Found.