#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

char firstUniqChar(string str){
    unordered_map<char, int> m; //unordered map for storing the count of every ch
    queue<int> q; //q should only contain unique char .. if any repeating char appear at front.. pop it.
    for(char ch : str){ //Store the count and char in the map.
        m[ch]++;
        q.push(ch);
    }
  //Remove the ch from the front of the queue if they are repeated i.e, count>1
  while(!q.empty() && m[q.front()]>1){
    q.pop();
  }
  if(!q.empty()){ // After poppping only the UNIQUE char will be left in the queue.. its front will be the first unique ch so .. return q.front
    return q.front();
  } else { //If Q becomes empty i.e, NO unique char found in the string.
    return ' ';
  }
}
int main(){
    string s = "assassination";
    char result = firstUniqChar(s);
    if(result!=' '){ //If Q is Not Empty then,
        cout<<"First Unique Char of string "<<s<< " is "<<result<<endl;
    } else { //The Q is empty.
        cout<<"No Unique Char found."<<endl;
    }
    return 0;
}
// Output:-
// First Unique Char of string assassination is t
//TC- O(n), SC - O(n).
/*
🧠 Dry Run | Visualisation for: "assassination"

Step | Char | Frequency Map (m[ch])         | Queue (q)             | Front | Action
-----|------|-------------------------------|------------------------|--------|----------------------------
 1   | a    | {a:1}                         | a                      | a      | First time → push
 2   | s    | {a:1, s:1}                    | a, s                   | a      | First time → push
 3   | s    | {a:1, s:2}                    | a, s, s                | a      | s count > 1, skip
 4   | a    | {a:2, s:2}                    | a, s, s, a             | a      | a repeated → pop a
 5   | s    | {a:2, s:3}                    | s, s, a                | s      | s repeated → pop s
 6   | s    | {a:2, s:4}                    | s, a                   | s      | s repeated → pop s
 7   | i    | {a:2, s:4, i:1}               | a, i                   | a      | i first time → push
 8   | n    | {a:2, s:4, i:1, n:1}          | a, i, n                | a      | n first time → push
 9   | a    | {a:3, s:4, i:1, n:1}          | a, i, n, a             | a      | a repeated → pop a
10   | t    | {a:3, s:4, i:1, n:1, t:1}     | i, n, a, t             | i      | t first time → push
11   | i    | {a:3, s:4, i:2, n:1, t:1}     | i, n, a, t, i          | i      | i repeated → pop i
12   | o    | {a:3, s:4, i:2, n:1, t:1, o:1}| n, a, t, i, o          | n      | o first time → push
13   | n    | {a:3, s:4, i:2, n:2, t:1, o:1}| n, a, t, i, o, n       | n      | n repeated → pop n

✅ Final Queue after popping repeated: a, t, i, o, n  
→ a (repeated) → pop  
→ t (unique) ✅

🎯 Answer: 't' is the first unique character
*/