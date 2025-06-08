#include <iostream>
#include <vector>
using namespace std;
int diagSum(vector<vector<int>> &mat, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += mat[i][i];
        if(i != n-1-i){
            sum += mat[i][n-1-i];
        }
    }
    return sum;
}
int main(){
    int n = 3;
    vector<vector<int>> mat = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout << diagSum(mat, n); //25
    return 0;
}