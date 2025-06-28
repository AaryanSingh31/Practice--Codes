
// SPAN = TIME DURATIION WHERE PRICE REMAINS EQUAL TO OR LESS THAN TODAY'S PRICE IN CONSECTIVE DAYS(ALSO INCLUDE TODAY'S PRICE IN SPAN)
//  INSHORT span <= today price
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    int n = prices.size();
    stack<int> s;          // to store the prevHigh idx before current day.
    vector<int> ans(n, 0); // to Store the span for each day
    for (int i = 0; i < n; i++){
        while (s.size() > 0 && prices[s.top()] < prices[i]){
            s.pop(); // remove the top if it is smaller than current day since we only neeed larger prices.
        }
        if (s.size() == 0){ // if there is no greater price than today... i.e, the whole prev indeces (each idx represent a day) are span.
            ans[i] = i + 1; // for current idx, span = idx+1;
        }
        else{ // if the stack is not empty i.e, there exists a greater price.. so the in this case the span will be,
            ans[i] = i - s.top(); //(current idx - greater price idx(s.top) gives the span)
        }
        s.push(i); // push the current day idx in stack for the next iteration.
    }
    // print the span values
    for (int val : ans){
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
// Output:-
// 1 1 1 2 1 4 6
// TC -> O(n) & SC -> O(n) (for stack and ans vector)
