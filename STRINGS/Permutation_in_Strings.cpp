#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool chkInclusion(string s1, string s2){
    // check if s1.length > s2.length
    if (s1.length() > s2.length()){ // Permut is not possible
        return false;
    }
    // Cal freq for s1.
    vector<int> freq1(26, 0);
    for (int ch : s1){
        freq1[ch - 'a']++;
    }
    // Cal freq for slide window of s2( of length s1).
    vector<int> freq2(26, 0);
    for (int i = 0; i < s1.length(); i++){
        freq2[s2[i] - 'a']++;
    }
    // chk if 1st window is a permutation
    if (freq1 == freq2){
        return true;
    }
    // Slide the window in s2 for next letter
    for (int i = s1.length(); i < s2.length(); i++){
        freq2[s2[i] - 'a']++;               // add next char
        freq2[s2[i - s1.length()] - 'a']--; // remove the leftmost char from window.

   // chk if new window char freq matches with s1 freq.
        if (freq2 == freq1){
            return true;
        }
    }
   //No Permutation found.  
    return false;
}

int main(){
    string s1 = "ab";
    string s2 = "eodcbaooao";
    if (chkInclusion(s1, s2)){ // Print if permutation exists or not.
        cout << "Permutation Exists." << endl;
    }
    else{
        cout << "No Such permutation exists." << endl;
    }
    return 0;
}

// OUTPUT:-
// Permutation exists.
// TC O(1) -> Almost constant because 26 size array is used which is negligible. 
// SC O(1) -> Same as above, 26 size array is used.