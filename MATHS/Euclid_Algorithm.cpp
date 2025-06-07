// Euclid algorithm says that the GCD of two numbers can be found by repeatedly replacing the larger number by the remainder of the division of the larger number by the smaller number until one of the numbers becomes zero. The other number at that point will be the GCD. 
// i.e, gcd(a,b) = gcd(a-b, b) if a > b
//               = gcd(a, b-a) if b > a
// More efficient way is to use the modulo operator:
// i.e, gcd(a,b) = gcd(b, a % b) if a > b

#include <iostream>
using namespace std;
int gcd(int a, int b){
    while(a>0 && b>0){
        if(a>b){        // (i)gcd(20, 12) -> gcd(8, 12).
                        // (iii)gcd(8,4) -> gcd(0, 4).
        a = a % b;      // Replace a with the remainder of a divided by b
        } else{         // (ii)gcd(8, 12) -> gcd(8, 4).
            b = b % a;  // Replace b with the remainder of b divided by a
        }
    } return a + b;     // When one of them becomes zero, return the other number.
}
int main(){
    int a = 20, b = 12;
    cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << "." << endl;
    return 0;
}