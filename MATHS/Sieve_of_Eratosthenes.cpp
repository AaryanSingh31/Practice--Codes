// AN OPTIMISED ALGORITHM FOR CALCULATING THE PRIME NUMBERS IN A RANGE
#include <iostream>
#include <vector>
using namespace std;
int countPrimes(int N){
    vector<bool> isPrime(N + 1, true);            //Initialised every num as prime.
    int count = 0;
    int ans;
    for (int i = 2; i < N; i++){                  //count primes
        if (isPrime[i]){
            ans = isPrime[i];
            count++;
            for (int j = i * 2; j < N; j = j + i){ //Eliminate the multiples of current prime.
                isPrime[j] = false;                //assigning false to non prime(multiple of primes).
            }
        }
    }
    return count;
}
int main(){
    int N;
    cout << "Enter the num : ";
    cin >> N;
    int res = countPrimes(N);
    cout << "The number of prime numbers less than " << N << " is : " << res << endl;
    return 0;
}
