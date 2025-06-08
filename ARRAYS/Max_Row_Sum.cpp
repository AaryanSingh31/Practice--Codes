#include <iostream>
#include <vector>
using namespace std;
int getMaxSum(vector<vector<int>> &mat){
    int maxRowSum = INT_MIN; //Initialise max sum.
    int m = mat.size(), n = mat[0].size(); // size of row and col.
    for (int i = 0; i < m; i++){           //for loop for rows
        int currowSum = 0;                 //Initialise curr sum with 0 after each iteation to store sum of next row elements ##IMP STEP.
        for (int j = 0; j < n; j++){       //for loop for each row.
            currowSum += mat[i][j];        // Add current cell element to curr sum.
     maxRowSum = max(maxRowSum, currowSum);//Store the max value of row sum.
        }
    }
    return maxRowSum;
}
int main(){
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10}}; // Vector 2D array ## dynamic in nature i.e, it can have diff no of col/row at evry or any place.
    cout << "Max Row Sum is : " << getMaxSum(mat) << endl; //Fn call.
    return 0;
}
// Output :-
// Max Row Sum is : 27 (which is r2)
// TC -> O(log(m*n)).