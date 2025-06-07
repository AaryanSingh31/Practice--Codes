#include <iostream>
using namespace std;
int reverse(int n){
    int revdig = 0;
    while(n > 0){
        int dig = n % 10; 
        revdig = revdig *10 + dig; // Adding the digit to the reversed number
        n = n/10; //remove the reversed digit from the org num.
    }
    return revdig;
}
int main(){
    int num = 123405;
    cout << "Reverse of " << num << " is " << reverse(num) << "." << endl;
    return 0;
}