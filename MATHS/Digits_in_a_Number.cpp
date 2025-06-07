#include <iostream>
using namespace std;
 // Fn to count the num of digits.
int numOfDig(int num){
    int count = 0;
    while (num > 0){
        num /= 10; // Remove the last digit.
        count++;
    }
    return count;
}
 //Fn to find the sum of the digits.
int sumOfDig(int num){
    int sum = 0;
    while (num > 0){
        int dig = num % 10; // Get the last digit.
        sum = sum + dig;    // Add the last digit to the sum.
        num = num / 10;     // Remove the last digit.
    }
    return sum;
}
//Fn to reverse the number.
void RevDig(int num){
    while (num > 0){
        int ans = num % 10; // Get the last digit.
        cout << ans << "";  // Print the last digit.
        num /= 10;          // Remove the last digit.
    }
}

int main(){
    int num = 123;
    cout << numOfDig(num) << endl;
    ; // Count the number of digits -> 3.
    cout << sumOfDig(num) << endl;
    ;              // Sum the digits -> 6
    RevDig(num); // Reverse the digits. -> 321
    return 0;
}