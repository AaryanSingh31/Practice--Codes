#include <iostream>
#include <algorithm>
using namespace std;
bool isPalindrome(int num) {
    int original = num; // Store the original number
    int revNum = 0;

    while (num > 0) {
        int digit = num % 10; // Get the last digit
        revNum = revNum * 10 + digit; // Build the reversed number
        num /= 10; // Remove the last digit
    }

    return original == revNum; // Check if the original and reversed numbers are equal
}

int main(){
    int num = 12321;
    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }
    return 0;
}