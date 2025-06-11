#include <iostream>  
#include <vector>  
using namespace std;  
  
void getPer(vector<int> &arr, int idx, vector<vector<int>> &ans) {  
    int n = arr.size();  
      
    // Base case: If index reaches the end, store the current permutation  
    if (idx == n) {  
        ans.push_back(arr);         // Push the current permutation into the answer vector  
        return;  
    }  

    // Loop through all elements from idx to end  
    for (int i = idx; i < arr.size(); i++) {  
        swap(arr[idx], arr[i]);     // Swap current index element with i-th element  
        getPer(arr, idx + 1, ans);  // Recursive call for next index  
        swap(arr[idx], arr[i]);     // Backtrack: Undo the swap to restore original order  
    }  
}  

int main() {  
    vector<int> arr = {1, 2, 3}; // Input array  
    vector<vector<int>> ans;     // Vector to store all permutations  
      
    getPer(arr, 0, ans);         // Call function to generate permutations  
      
    // Printing all generated permutations  
    for (const auto &permutation : ans) {  
        for (int val : permutation) {  
            cout << val << " ";  
        }  
        cout << endl;  
    }       
    return 0;
}  
