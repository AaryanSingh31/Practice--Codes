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
    return (n % 2 == 0) ? (prinDiagSum + nonpD) : (prinDiagSum + nonpD - matrix[n/2][n/2]); //Central element in case of odd matrix of size n is n/2
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
// MOST IMPORTANT SUMMARY (Interview Gold)
// Concept	Condition
// Primary diagonal	i == j
// Secondary diagonal	i + j == n-1
// Same diagonal	i + j = constant
// Upper triangle	i < j
// Lower triangle	i > j