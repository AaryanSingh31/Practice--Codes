#include <iostream>
using namespace std;
int sum(int n){
    if (n == 0){  //Base case.
        return 0;
    }
    int ans = n + sum(n - 1); //Recursive call.
    return ans;
}
int main(){
    int n = 6;
    cout << sum(n);
    return 0;
}
