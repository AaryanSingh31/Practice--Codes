#include <bits/stdc++.h>
using namespace std;

bool arrayColoring(vector<int> &nums){
    int k = 0, n = nums.size();
    map<int, char> mp;
    while(k < n){
        mp[nums[k]] = 'b';
        k++;
        if(k < n){
            mp[nums[k]] = 'r';
            k++;
        }
    }
    vector<char> ans; 
    for(auto &it : mp){
        ans.push_back(it.second);        
   }
   for(int i = 0; i < n; i++){
       if(i < n-1){
           if(ans[i] == ans[i+1])return false;
       }
   }
   return true;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin>>nums[i];
        }
        if(arrayColoring(nums)){
            cout<<"Yes"<<endl;
        }else {
            cout<<"No"<<endl;
        }
    }

}
