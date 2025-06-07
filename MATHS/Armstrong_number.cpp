
//ARMSTRONG NUMBER -> A NUMBER IS CALLED AN ARMSTRONG NUMBER IF THE ADDITION OF CUBE OF EACH DIGIT IS EQUAL TO THE NUMBER ITSELF.
// Example: 153 is an Armstrong number because 1^3 + 5^3 + 3^3 = 153  

#include <iostream>
using namespace std;
bool isArmstrong(int num){
    int originalNum = num;                   // Store the original number to compare it later.
    int sum = 0;
    while(num > 0){
        int digit = num % 10;
        sum = sum + (digit * digit * digit); // Add the cube of the digit to the sum.
        num /= 10;                           // Remove the last digit.
    }
      return sum == originalNum;
}

int main(){
int num = 370; //True
if(isArmstrong(num)){
    cout << num << " is an armstrong number. "<<endl;
} else { 
    cout<< num << " is not an armstrong number. "<<endl;
}

    return 0;
}
//TC -> O(log(n)).