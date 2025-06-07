// If a number n is not divisible by any num from  2 to sqrt(n) -> n is prime num. 
#include <iostream>
#include <string>
using namespace std;
 string isPrime(int n){
   for(int i=2; i*i<=n; i++){
        if(n%i==0){ return "Non Prime";
    } else {
        
    }     
   } return "Prime";
 }

int main(){
int n = 42;
cout<<isPrime(n); //output -> Non Prime.
    return 0;
}