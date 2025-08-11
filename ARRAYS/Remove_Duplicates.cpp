#include <iostream>
#include <vector>
using namespace std;

int removeDup(vector<int> &nums){
    int n = nums.size();
    int i = 0;                  //TRACKS THE LEFT POINTER
    for(int j = 1; j < n; j++){ //TRACKS THE RIGHT POINTER J++ UNTIL YOU GET THE DIFFERENT ELEMENT IN J
        if(nums[j]!=nums[i]){
            i++;                //MOVE THE LEFT POINTER
            nums[i]=nums[j];    //ASSIGN THAT DIFFERENT VALUE OF ELEMENT J IN ITH POSITION.
        }
    }
    //RESIZE INBUILT FN
     nums.resize(i+1);         //I POINTER WILL BE AT THE LAST OF UNIQUE ELEMENT.
     return i+1;               //RETURN THE NO OF UNIQUE ELEMENTS
}
int main(){
    vector<int> arr = {0,0,1,1,1,2,2,3,4};
    cout<<removeDup(arr); //5
    return 0;
}
// OUTPUT - 5
//TC - O(n).
//SC - O(1).
