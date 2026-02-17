#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> addVect(vector<int>& a, vector<int>& b){
    int i = a.size()-1, j = b.size() -1; //For traversing the vectors from the end
    int carry = 0; //To store the carry value when the sum of two digits exceeds 9
    vector<int> res;
    while(i >= 0 || j >= 0){ //Loop until we have traversed both vectors
        int sum = carry;     //Initialize sum with the carry value from the previous iteration
        if(i >= 0){
            sum += a[i];     //Add the current digit of vector a to the sum
            i--;
        }
        if(j >= 0){
            sum += b[j];     //Add the current digit of vector b to the sum
            j--;
        }
        res.push_back(sum % 10); //Add the last digit of the sum to the result vector
        carry = sum/10;  // Update the carry value for the next iteration (1 if sum is 10 or more, otherwise 0)
    }
    reverse(res.begin(), res.end()); //Reverse the result vector to get the correct order of digits
    return res;
}

int main(){
    vector<int> v1 = {1, 3, 4, 9};
    vector<int> v2 = {1};
    vector<int> ans = addVect(v1,v2);
    for(int i = 0; i < ans.size(); i++){ //Output - [1, 3, 5, 0]
        cout<<ans[i]<<" ";
    }
    return 0;
}