#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
void nextPermutation(vector<int> &nums){
    int n = nums.size();
    int i = n-2;                                //Start from the second last element
    while(i >= 0 && nums[i] >= nums[i+1]){      //Find the first decreasing element i.e, Pivot Element.
        i--;
    }
    if(i>=0){                                   //If the entire array is not in descending order
        int j = n-1;                            //Start from the last element
        while(j >= 0 && nums[j] <= nums[i]){    //Find the first element greater than the pivot element
            j--;
        }
        swap(nums[i], nums[j]);                 //Swap the pivot element with this element
    }
    reverse(nums.begin()+i+1, nums.end());      //Reverse the elements after the pivot element.
}
int main(){
    vector<int> nums = {1, 2, 5, 4, 3};
    nextPermutation(nums);
    for(int i : nums) cout << i << " ";
    return 0;
}