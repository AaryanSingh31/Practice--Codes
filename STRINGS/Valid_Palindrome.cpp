#include <iostream>
#include <string>
using namespace std;
   // To Chk if the char is AlphaNumeric digit.
bool isAlphaNum(char c){ 
    if (c >= '0' && c <= '9')     //AlphaNumeric digit.
        return true;
    if (c >= 'a' && c <= 'z') //AlphaNumeric digit.
        return true;
    if (c >= 'A' && c <= 'Z') //AlphaNumeric digit.
        return true;
    else{
        return false;        // Not AlphaNumeric digit.
    }
}
// Fn to chk if the string is a palindrome. 
bool isPalindrome(string s){
    int n = s.length();
    int st = 0, end = n - 1;
    while (st < end){
        // If st pointer!=AlphaNum, then move the st pointer to next char.
        if (!isAlphaNum(s[st])){
            st++;
            continue; // continue to search 
        }
        // If end pointer!=AlphaNum, then move the end pointer to previous char.
        if (!isAlphaNum(s[end])){
            end--;
            continue; // continue to search 
        }
        // If st pointer == end pointer move both pointer to find next palindrome 
        if (tolower(s[st]) == tolower(s[end])){ //tolower -> Inbuilt c++ fn to convert uppercase letters to lowercase. 
            st++, end--;
        }
        else{ //If st pointer != end pointer.
            return false;
        }
    }
    //If we Don't get false inside the while loop i.e, 
    //all the conditions got satisfied (The string is palindrome), so we return true
    return true;
}
    //Fn to print the output.
     void print(string str){
     if (isPalindrome(str)){ 
        cout << "Valid palindrome." << endl;
    }
    else{
        cout << "Invalid palindrome." << endl;
      }
     }

int main(){
cout<<"string s1 = Ac3/e3c&a"<<endl;
    string s1 = "Ac3/e3c&a";    //Eg1 string
    string s2 = "19823981";  //Eg2 string
    isPalindrome(s1); //Fn call for s1
     print(s1);       //print s1
cout<<"string s2 = 19823981"<<endl;
    isPalindrome(s2); //Fn call for s2
     print(s2);       //print s2

    return 0;
}