#include <iostream>
#include <vector>
using namespace std;

int singleElement(vector <int> &A){
    int n = A.size();
int start = 0, end = n-1;
 //Corner Case
if(n==1){return A[0];}
while(start<=end){

int mid = start + (end-start)/2;
 //Corner case
 if(mid==0 && A[0]!=A[1]){return A[mid];}
//Corner Case
 if(mid==n-1 && A[n-1]!=A[n-2]){return A[mid];}
 //IMP ..agar mid na apne left wale element ke barabar aur na
 // apne right wale element ke barabar hai toh A[mid] hi single element hoga
 if(A[mid-1]!=A[mid] && A[mid+1]!=A[mid]){
    return A[mid];
 }

 if(mid%2 == 0){         //Mid is Even.
    if(A[mid-1]==A[mid]){ // Search in left half.
        end = mid-1;
       

         } else {        //Search in right half.
        start = mid+1;
       }

 } else {                // Mid is Odd.
 if(A[mid-1]==A[mid]){   //Search in Right half
     start = mid+1;

     } else{             //Search in left half.
           end = mid-1;
    }
   }
  } return -1;
}
int main(){
       vector <int> A = {1, 1, 5, 5, 4, 9, 9, 7, 7}; //Example ->  Array with Even Mid.
       vector <int> B = {9, 9, 5, 5, 1, 3, 3};       //Example ->  Array with Odd Mid.
 cout<<"Array A with Even Mid : A = [1, 1, 5, 5, 4, 9, 9, 7, 7] "<<endl;
int res = singleElement(A);
cout<<"The Single element inside the array A is : "<<res<<endl;
cout<<"Array B with Odd Mid : B = [9, 9, 5, 5, 1, 3, 3] "<<endl;
res = singleElement(B);
cout<<"The Single element inside the array B is : "<<res<<endl;
    return 0;
}