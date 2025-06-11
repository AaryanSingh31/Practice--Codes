#include <iostream>
using namespace std;
int fact(int n){
        if(n==1 || n==0){     //Base Case to stop recursion. ##Most Imp.
            return 1;
        }
        return n * fact(n-1); //Recursive call.
    }

int main(){
   int n;
   cout <<"Enter the number : ";
   cin>>n;
  cout<< fact(n); 
    return 0;
}
// Output :-
// eg -> 5
// 120
// TC -> O(n)
// SC -> O(n)