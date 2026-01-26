#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target){
    int left = 0, right = nums.size() - 1;
    while(left < right){
        if(nums[left] + nums[right] == target){
            return {left + 1, right + 1};
        }  else if(nums[left] + nums[right] < target){
            left++;
        } else {
            right--;
        }
    }
    return {};
}

//Fn to print the vector
void print(vector<int> &ans){
    for(int val : ans){
        cout<<val<<" ";
    }
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;
    vector<int> ans = twoSum(nums, target);
    print(ans);
    return 0;
}