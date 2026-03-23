#include <iostream>
#include <vector>
using namespace std;

int diagSum(int n, vector<vector<int>> & matrix){
    int prinDiagSum = 0, nonpD = 0, totalSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                prinDiagSum += matrix[i][j];
            }
            if(i + j == n - 1){
                nonpD += matrix[i][j];
            }
        }
    }
    return (prinDiagSum + nonpD);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];
        }
    }
    cout<<diagSum(n, matrix)<<endl;
    return 0;
}