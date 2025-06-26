#include <iostream>
#include <stack>
using namespace std;
bool isValid(string str){
    stack<char> st; // stack to store the opening brackets.
    // Iterate through the string.
    for (int i = 0; i < str.size(); i++){
        if (str[i] == '(' || str[i] == '{' || str[i] == '['){                    // opening brackets.
            st.push(str[i]); // push the opening brackets into the stack.
        }
        else{ // closing brackets
            if (st.size() == 0)
                return false; // if the stack is empty and we encounter a closing bracket, it means there is no opening bracket for it.
            // Now we check if the top of the stack matches with the current closing bracket.
            if (st.top() == '(' && str[i] == ')' || st.top() == '{' && str[i] == '}' || st.top() == '[' && str[i] == ']'){
                st.pop(); // pop the top if the closing bracket is same as the top bracket i.e, pair exists.
            }
            else{ // No match is found.
                return false;
            }
        }
    }
    return st.size() == 0; // At last if the stack becomes empty that means all the matches are correct.
}
int main(){
    string str = "[({}){})]";
    if (isValid(str)){
        cout << str << " is a Valid Parentheses. ";
    }
    else{
        cout << str << " is an Invalid Parentheses." << endl;
    }
    return 0;
}
// Output:-
// [({}){})] is an Invalid Parentheses.
// TC - O(n)