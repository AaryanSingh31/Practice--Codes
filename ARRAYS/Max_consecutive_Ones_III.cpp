// **************************************** SLIDING WINDOW APPROACH*************************************
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int MaxOnes(vector<int> & nums, int k){
    int n = nums.size();
    int l = 0, maxLength = 0;
    unordered_map<int, int> m;              // To store the count of 0's and 1's in the current window
   
   for(int r = 0; r < n; r++){              // r is the right pointer
        m[nums[r]]++;                       // Increment the count of the current element

        if(m[0] > k){                       // If count of 0's exceeds k, shrink the window from the left
            while(m[0] > k){                // While count of 0's is more than k
            m[nums[l]]--;                   // Decrement the count of the leftmost element until count of 0's is less than or equal to k
            l++;                            // Move the left pointer to the right after every decrement
        }
     }
     maxLength = max(maxLength, r-l+1);      // Update the maximum length of the window
   }
   return maxLength;                         // Return the maximum length found
}
int main(){
    vector<int> nums = {1,1,0,0,0,1,1,0,1};
    int k = 2;
    cout << MaxOnes(nums, k); //Ans : 5
    return 0;
}

//LeetCode Link: https://leetcode.com/problems/max-consecutive-ones-iii/
//Time Complexity: O(n)
//Space Complexity: O(1)
