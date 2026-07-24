#include <bits/stdc++.h>
using namespace std;

long long minCost(vector<long long> nums, long long n){
    //min heap priority queue
    priority_queue<long long, vector<long long>, greater<long long>> p;
    for(int i = 0; i < n; i++){
        p.push(nums[i]); //tc-O(logn) for each push in queue. For n elements TC- O(n*logn)
    }
    long long cost = 0;
    while(p.size() > 1){ //TC for while loop O(n-1)
        long long first = p.top(); //first rope to take out
        p.pop(); //O(logn)
        long long second = p.top();//sec rope to take out
        p.pop();//O(logn)
        long long merged = first + second; //merge the ropes
        cost += merged; //add the cost of merge
        p.push(merged); //O(logn) //Push the new length of the merged rope.

        //total tc - O(n-1 * 3logn) => O(nlogn)
    }
    return cost;
}
int main(){
    vector<long long> nums = {2, 5, 1, 3}; //ans = 20
    cout<<minCost(nums, nums.size());
    return 0;
}

//ovrall tc - O(nlogn) + O(nlogn) = O(nlogn).