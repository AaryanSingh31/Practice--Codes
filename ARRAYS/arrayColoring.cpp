#include <bits/stdc++.h>
using namespace std;

bool arrayColoring(vector<int> &nums){
    int n = nums.size();
    vector<pair<int, int>> v;
    v.reserve(n);
    for(int i = 0; i < n; i++){
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n - 1; i++){
        int idx1 = v[i].second;
        int idx2 = v[i+1].second;
        
        if((idx1 % 2) == (idx2 % 2)){ 
            return false;
            
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
            cout<<"yes"<<endl;
        }else {
            cout<<"no"<<endl;
        }
    }

}
