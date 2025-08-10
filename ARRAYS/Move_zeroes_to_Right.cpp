#include <iostream>
#include <vector>
using namespace std;

void move(vector<int> &nums){
  int n = nums.size();
  int st = 0;
  int end = n-1;
  while(st<end){
    if(nums[st]==0 && nums[end]!=0){   //WHEN THE START IS 0 AND END IS NOT 0
       swap(nums[st], nums[end]);
        st++;
        end--;
    }
  if(nums[st]!=0){  //WE NEED THE NON ZERO DIG AT LEFT WHICH IS TRUE IN THIS CONDITION.. 
     st++;          //SO WE MOVE THE ST POINTER FORWARD WITHOUT DISTURBING THE DIGIT.
   } else {         // WHEN ST AND END IDX ELEMENT ARE 0, THEN MOVE THE END POINTER TO LEFT CUZ WE NEED THE NON-ZERO TO SWAP IT WITH 0 OF ST.
    end--;
  }
 }
}

  //FN TO DISPLAY THE ARRAY
void display(vector<int> nums){
    for(int val: nums){
         cout<<val<<" ";
    }
}
int main(){
vector<int> nums = {0, 5 ,-1, 0 , 4 , 0, 3};
  move(nums);
  display(nums);
    return 0;
}

//OUTPUT :- 
//3 5 -1 4 0 0 0
//TC- O(n)
//SC- O(1)