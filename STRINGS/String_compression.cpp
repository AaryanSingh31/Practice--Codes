#include <iostream>
#include <vector>
using namespace std;

int compress(string &s){
    int n = s.length();                
    int idx = 0;         //index to store the final compressed Arr.
    for (int i = 0; i < n; i++){
        char ch = s[i];  //Store the current char to ch
        int count = 0;   //var for store the count the char.
        while (i < n && s[i] == ch){ //Loop will run until we get a diff char from previous.
            count++;                      
            i++;                     //Move to next char and check again if it's same as before
        }
      //after the while loop end i.e, we got the char and it's count.   
        if (count == 1){            
            s[idx++] = ch; //Assign the char value at idx and increase idx. 
        }
        else{              // if count>1 then,
            s[idx++] = ch; //Assign that char to idx and increase the idx
            string str = to_string(count); //convert the (int) count to (string) count and store it in new string called str .
            for (char val : str){           //using for each loop
                s[idx++] = val;            //Assigning the count string in the s string.
            }
        }
        i--; //Earlier in the main for loop we've done the i++ two times ((1st in main for loop and second in while loop)) .. so we've to do i-- one time to get to the next iteraion.
    }
    return idx; //Return the new compressed length of string(Which is same as at how many idxes we've reached till.) 
}
int main(){
    string s = "abbccc"; //length = 6
    int compressLength = compress(s);
    for (int i = 0; i < compressLength; i++){ //print the new compressed char array.
        cout << s[i] << ""; //length = 5
    }
    cout << endl;
    cout << compressLength << endl;           //Print the length of compressed length.
    return 0;
}
// Output:-
// a b 2 c 3 -> new compressed stirng.
// 5         ->  comressed string length.