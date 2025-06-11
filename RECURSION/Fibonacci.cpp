#include <iostream>
using namespace std;
int fib(int n){
    if(n == 0 | n == 1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
int n = 15;
cout<<fib(n);
    return 0;
}


// Logic for fibonacci :-
// Tn = T(n-1) + t(n-2)
//TC -> O(2^n)
//SC -> O(n).