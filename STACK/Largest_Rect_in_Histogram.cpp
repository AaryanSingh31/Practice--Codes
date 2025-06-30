#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    vector<int> height = {2, 1, 5, 6, 2, 3};
    stack<int> s;
    int n = height.size();
    vector<int> right(n, 0); // to store the index of the smaller element for the width calculation
                             // for smaller element in the right side of the of the histogram for the current bar in the stack.
    for (int i = n - 1; i > 0; i--){ // Backward loop for right side
        while (s.size() > 0 && height[s.top()] >= height[i]){
            s.pop();         // remove the bigger element from stack.
        }
        if (s.size() == 0){  // if there is no smaller element to the right of current element.
            right[i] = n;    // assign the size of the array to the right[i] i.e, full length of the histogram till the last.
        }
        else{
            right[i] = s.top();
        }
        s.push(height[i]);   // push the current Bar value in the stack for the next iteration.
    }
    // empty the stack for storing the left side larger values
    while (s.size() != 0){
        s.pop();
    }
    // for smaller element in the right side of the of the histogram for the current bar in the stack.
    vector<int> left(n, 0);
    for (int i = 0; i < n; i++){ // forward loop for left
        while (s.size() > 0 && height[s.top()] >= height[i]){
            s.pop();                // remove the bigger element from stack.
        }
        if (s.size() == 0){         // if there is no smaller element to the left of current element.
            left[i] = -1;           // assign the size of the array to the left[i] i.e, full length of the histogram till the first.
        }
        else{                       // if there is any larger value i.e, stoping bar -> s.top()...
            left[i] = s.top();      // assign the index of stoping bar in the left vector.
        }
        s.push(height[i]);          // push the current Bar value in the stack for the next iteration.
    }
    // AFTER THE BOTH ITERATIONS WE CAN CAL THE AREA CUZ WE HAVE BOTH HEIGHT AND WIDTH(CAL BY FORMULA.. WIDTH = RIGHT VEC INDEX - LEFT VECT INDEX - 1)
    int ans = 0;                    // initilising the var for storing the max area.
    for (int i = 0; i < n; i++){
        int currArea = (height[i]) * (right[i] - left[i] - 1); //Formula used.
        ans = max(ans, currArea); 
    }
    cout << "Largest Rectangle Area : " << ans <<" units."<< endl;

    return 0;
}
// Output :-
// Largest Rectange Area : 20 units