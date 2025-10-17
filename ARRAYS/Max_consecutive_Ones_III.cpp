// **************************************** SLIDING WINDOW APPROACH*************************************
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int MaxOnes(vector<int> & nums, int k){
    int n = nums.size();
    int l = 0, maxLength = 0;
    unordered_map<int, int> m;
   
   for(int r = 0; r < n; r++){
        m[nums[r]]++;

        if(m[0] > k){
            while(m[0] >k){
            m[nums[l]]--;
            l++;
        }
     }
     maxLength = max(maxLength, r-l+1);
   }
   return maxLength; 
}
int main(){
    vector<int> nums = {1,1,0,0,0,1,1,0,1};
    int k = 2;
    cout << MaxOnes(nums, k);
    return 0;
}