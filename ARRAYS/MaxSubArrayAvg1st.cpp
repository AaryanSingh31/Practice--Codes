#include <iostream>
#include <vector>
using namespace std;
double maxSubArray(vector<int> &nums, int k){
    int n = nums.size();
    double CurSum = 0;
    for(int i = 0; i < k; i++){
        CurSum += nums[i];
    }
    double Avg = CurSum/k;
    //Slide the window
    for(int i = k; i < n; i++){
        CurSum += nums[i] - nums[i - k];
        Avg = max(Avg, CurSum/k);
    }
    return Avg;
}
int main(){
 vector<int> nums = {1,12,-5,-6,50,3};
 int k = 4;
    cout<<maxSubArray(nums, k); //Ans : 12.75
}
//LeetCode Link: https://leetcode.com/problems/maximum-average-subarray-i/
//Time Complexity: O(n)
//Space Complexity: O(1)
