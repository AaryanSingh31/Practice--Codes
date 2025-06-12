#include <iostream>
#include <vector>
using namespace std;
       //FN TO PLACE THE QUEEN AT SAFE POSITION
bool isSafe(vector<string> &board, int row, int col, int n){
    for (int j = 0; j < n; j++){       //if 2nd queen is in the row of current queen.
        if (board[row][j] == 'Q'){
            return false;
        }
    }
    for (int i = 0; i < n; i++){      //if 2nd queen is in the col of current queen.
        if (board[i][col] == 'Q'){
            return false;
        }
    }
    int i = row, j = col;
    while (i >= 0 && j >= 0){         //if 2nd queen is in the left diag(upper to current queen) of current queen.
        if (board[i--][j--] == 'Q'){
            return false;
        }
    }
    i = row, j = col;
    while (i >= 0 && j < n){          //if 2nd queen is in the right diag(upper to current queen) of current queen.
        if (board[i--][j++] == 'Q'){
            return false;
        }
    }
    return true;                      //If all the conditions are not met.. we found a safe place .. return true.
}
     //FN TO GET ALL THE CONFIGURATIONS
void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
    if (row == n){                   //BASE CASE
        ans.push_back(board);        //When the base case hits, store the current config of board into ans.
        return;
    }
    for (int j = 0; j < n; j++){
        if (isSafe(board, row, j, n)){//if safe
            board[row][j] = 'Q';              //assign Q at that position
            nQueens(board, row + 1, n, ans);  //Recursive call
            board[row][j] = '.';              //While backtracking assign '.' to the wrong place of Q
        }
    }
}
int main(){
    int n;
    cout << "Enter N : ";
    cin >> n;
    vector<string> board(n, string(n, '.')); //Initialise the board array with '.'
    vector<vector<string>> ans;              //vector to store the config
    nQueens(board, 0, n, ans);               //Call the fn.

    // Print all the config
    for (int i = 0; i < ans.size(); i++){        // for all the boards
        for (int j = 0; j < ans[i].size(); j++){ // for each board
            cout << ans[i][j] << " " << endl;   
        }
        cout << endl;
    }
    cout << endl;
    cout << "Total no. of possible Configurations : " << ans.size() << endl;
    return 0;
}
// Output :-
// for n = 4
// .Q..
// ...Q
// Q...
// ..Q.

// ..Q.
// Q...
// ...Q
// .Q..

// Total no. of possible Configurations : 2