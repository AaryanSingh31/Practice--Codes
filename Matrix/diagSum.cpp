#include <iostream>
#include <vector>
using namespace std;

int diagSum(int n, vector<vector<int>> & matrix){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += matrix[i][i];
        if(i != n-i-1){ //To avoid central element duplication i.e, i, j == n/2
            sum += matrix[i][n-i-1];
        }
    }
    return sum;
}

int main(){
    int n;
    cout<<" Size of Matrix : ";
    cin>>n;
    cout<<"Enter "<<n*n<<" elements : ";
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < matrix.size(); i++){ //Matrix.size() => Total no. of Rows
        for(int j = 0; j < matrix[i].size(); j++){ //matrix[i].size() => Total no of cols in ith row.
            cin>>matrix[i][j];
        }
    }
    cout<<diagSum(n, matrix)<<endl;
    return 0;
}
// MOST IMPORTANT SUMMARY (Interview Gold)
// Concept	Condition
// Primary diagonal	i == j
// Secondary diagonal	i + j == n-1 or j = n-i-1
// Same diagonal	i + j = constant
// Upper triangle	i < j
// Lower triangle	i > j