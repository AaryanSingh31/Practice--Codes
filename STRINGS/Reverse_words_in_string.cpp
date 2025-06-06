#include <iostream>
#include <string>
#include <algorithm> //imp header file for reverse fn
using namespace std;
string revWords(string s){
    int n = s.length();
    reverse(s.begin(), s.end());      // Reverse the whole string (Eg OUTPUT for the sky is blue -> eulb si yks eht)
    string ans = "";                  // Initialise string to store the words.
    for (int i = 0; i < n; i++){
        string word = "";             // to store each word and reinitialise after each iteration to store the new word
        // This while loop runs until we get a space
        //(If we get the space we'll move to the for loop for next iteration with the updated val if i in while loop )
        while (i < n && s[i] != ' '){ // Loop runs only if i is not an empty space.(i.e, spaces are being skipped).
            word += s[i];             // Add the letter in ith index to the string
            i++;

      } // After every completion of while loop we'll reverse every letter which is in word string
        reverse(word.begin(), word.end());
        if (word.length() > 0){
            ans += " " + word;        // Store that reversed word to ans string with a space before the word.
        }
    }   // Removing the space before the first word
    if (!ans.empty() && ans[0] == ' '){
        ans = ans.substr(1);          //print the ans from the index 1 (because there is a space at idx 0 which we don't want in our output.)
    }
    return ans;
}

int main(){
    string s1;
    cout<<"Enter the string : ";     
    getline(cin,s1);                  //input fn for string.
    cout << revWords(s1);
    return 0;
}
// Input Example -> This is car race
// output -> race car is this