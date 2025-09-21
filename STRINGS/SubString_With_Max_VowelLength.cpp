
#include <iostream>
#include <string>
bool isVowel(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
           c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}
using namespace std;
int maxVowelLength(const string &s, int k){
     int n = s.size();
     int maxLength = 0;
     int count = 0;
     //Initial Window
     for(int i = 0; i < k; i++){
        if(isVowel(s[i])) count++; //Count the number of Vowels in the Initial Window
     }
     maxLength = count;  //Set the maxLength to the count of Vowels in the Initial Window
     //Slide the window
     for(int i = k; i < n; i++){
        if(isVowel(s[i])) count++; //if the next char is vowel.. Increase the Curr count of Vowels inside the Window
        if(isVowel(s[i-k])) count--; //if the char going out of the Window is vowel.. Decrease the count
        maxLength = max(maxLength, count); //Update the maxLength
     }
     return maxLength;
}
int main(){
    string s = "abciiidef";
    int k = 3;
    cout << maxVowelLength(s, k) << endl;  // Output: 3
    return 0;
}
//leetcode: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
// Time Complexity: O(n)
// Space Complexity: O(1)
