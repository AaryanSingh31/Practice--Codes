#include <iostream>
#include <vector>
using namespace std;

int maxColSum(int rows, int cols, vector<vector<int>> &matrix){
    int maxSum = INT_MIN;
    for(int i = 0; i < cols; i++){
        int sum = 0;
        for(int j = 0; j < rows; j++){
            sum += matrix[j][i];
        }
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}

int main(){
    int rows, cols;
    cin>>rows>>cols;
    vector<vector<int>> matrix(rows, vector<int>(cols)); //Initialisation of the 2D vectors.
    for(int i=0; i<rows;i++){
        for(int j=0; j<cols; j++){
            cin>>matrix[i][j];
        }
    }
    cout << maxColSum(rows, cols, matrix)<<endl;
    return 0;
}