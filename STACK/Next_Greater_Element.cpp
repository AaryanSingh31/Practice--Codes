#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
vector<int> nums = {4, 5, 2, 10, 8};
int n = nums.size();
vector<int> ans(n, -1); // to store the next greater element for each element.
stack<int> s; // To store the greater element.
for(int i = n-1; i>=0; i--){ //reverse loop is Useful
    while(s.size()>0 && s.top()<=nums[i]){ // pop the top element if it is less than or equal to current element.
        s.pop();
    }
    if(s.size()==0) ans[i] = -1; //No greater element found for current element, so assign -1.
    else{
        ans[i] = s.top(); // if stack is not empty then the top element is the next greater element for current element.
    }
    s.push(nums[i]); // push the current element in stack for the next iteration.
}
//print the ans array
for(int val : ans){
    cout<<val<<" ";
}
cout<<endl;
    return 0;
}
// Output:-
// 5 10 10 -1 -1 