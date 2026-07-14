class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums){
        //sorting on first number must be smallest and second number of the interval must be biggest.
       sort(nums.begin(), nums.end(), [](auto &a, auto&b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });    
        int cnt = 0;
        int endMax = 0; 
        for(auto & interval : nums){
            if(interval[1] <= endMax){ //if the current end num is smaller than or equal to maximum end val of interval ie. this interval can be merged.. starting interval is already sorted in ascending order so it will not create any problem
                cnt++; //increase the cnt of merge interval    
            }else {
                endMax = interval[1]; //if current interval endval is greater .. update the max end interval val
            }
        }
        return nums.size()-cnt; //answer will the remaining intervals.
    }
};