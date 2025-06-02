#include <iostream>
using namespace std;

double myPow(double x, int n){
    //corner cases
    if (n == 0){    
        return 1;
    }
    if (n == 1){
        return x;
    }    
     //Convert negative power to positive.
    long long int N = n;
    if (N < 0){
        x = 1 / x;
        N = -N;
    }
    //Convert the power to binary.
    double ans = 1;
    while (N > 0){
        if (N % 2 == 1)
        {
            ans *= x; 
        }
    //Updating the num to its power to decrease the multiplication steps.
    //That means = x^2 -> x^4 -> x^8 -> x^16 -> x^32, ...     
        x *= x;
        N /= 2; //Divide by 2 to move to number to its next power.
    }
    return ans;
}
int main(){
    double x;
    int n;
    cout<<"Enter the number : ";
    cin>>x;
    cout<<"Enter the power : ";
    cin>>n;
    
    double result = myPow(x, n); //Function call.
    cout << x << " raise to power " << n << " is : " << result << endl;

    return 0;
}
