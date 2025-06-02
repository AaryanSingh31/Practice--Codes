#include <iostream>
#include <vector>
using namespace std;
int maxWater(vector<int> height){
    int lp = 0, rp = height.size() - 1;  //initialistion of left and right pointer.
    int maxwater = INT_MIN;              //initialisation.
    while (lp < rp) {                    
        int width = (rp - lp);                   //width in max case = 7.
        int length = min(height[lp], height[rp]);//length in max case = 7.
        int currentwater = width * length;       //Area in max case = 7*7 = 49.
        maxwater = max(maxwater, currentwater);  //updating the max value.
        if (height[lp] > height[rp]) {           //To get towards max area.
            rp--;
        }
        else if (height[lp] <= height[rp]) {
            lp++;
        }
    }
    return maxwater; //return the max amt of area(maxwater).
}
int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7}; //intialising the vector.
    int result = maxWater(height);                    //calling the fn.
    cout << "The Max Amt of Water stored is : " << result << endl;
    return 0;

}
// output :-
// The Max Amt of Water stored is : 49