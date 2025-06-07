#include <iostream>
using namespace std;

int main(){
// FINDING GCD USING BRUTE FORCE METHOD.
   int a=20,b=12;
    int gcd = 1;
    //CORNER CASES
    if(a==0){ 
    gcd = b;
    } else if(b==0){
        gcd = a;
    } else if(a==b){
        gcd = a; // or b
    //Logic starts here.
    }
    for(int i=1; i<=min(a,b); i++){
        if(a % i == 0 && b % i ==0){
            gcd = i; // Update gcd if i is a common divisor.
      }
    }
    cout << "GCD of " << a << " and " << b << " is " << gcd <<"."<< endl;
    return 0;
}