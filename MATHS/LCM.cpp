   // WE KNOW THAT GCD(A, B) * LCM(A, B) = A * B => lcm(a, b) = (a * b) / gcd(a, b)
#include <iostream>
using namespace std;
int gcd(int a, int b){
    while(a>0 && b>0){
    if(a>b){
        a = a % b;
    } else {
        b = b % a;
    }
}
    return a + b;
}
int lcm(int a, int b){ 
    return (a*b) / gcd(a,b); //Using the above formula to find lcm.
}
int main(){
int a = 20, b = 12;
    cout << "LCM of " << a << " and " << b << " is " << lcm(a, b) << "." << endl;
    return 0;

}