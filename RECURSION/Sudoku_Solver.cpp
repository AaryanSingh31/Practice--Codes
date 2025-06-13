#include <iostream>
#include <vector>
using namespace std;
   //FN TO CHECK WHETHER PLACING A DIGIT IS SAFE OR NOT.
bool isSafe(const vector<vector<char>> &board, int row, int col, char dig){
    // horizontal .. CHECKING IN A ROW FOR DUPLICATE 
    for (int j = 0; j < board.size(); j++){
        if (board[row][j] == dig)
            return false;
    }
    // Vertical .. CHECKING IN THE COL FOR DUPLICATE
    for (int i = 0; i < board.size(); i++){
        if (board[i][col] == dig)
            return false;
    }
    // Grid.. CHECKING THE 3X3 SEGMENT FOR ANY DUPLICATE 
    int stRow = (row / 3) * 3;
    int stCol = (col / 3) * 3;
    for (int i = stRow; i <= stRow + 2; i++){
        for (int j = stCol; j <= stCol + 2; j++){
            if (board[i][j] == dig)
                return false;
        }
    }
    return true; //IF NO FALSE IS RETURNED I.E, THE PLACE IS SAFE TO FILL WITH DIG.
}

      //FN TO SOLVE SUDOKU.
bool sudoku(vector<vector<char>> &board, int row, int col){
    int n = board.size();
    if (row == n) //BASE CASE
        return true;
    if (col == n)
        return sudoku(board, row + 1, 0); //RECURSE WITH NEXT COL
    if (board[row][col] != '.')           //IF PLACE IS NOT EMPTY, THEN
        return sudoku(board, row, col + 1);//RECURSE FROM THE NEXT PLACE
        //IF THE PLACE IS EMPTY, THEN
    for (char dig = '1'; dig <= '9'; dig++){
        if (isSafe(board, row, col, dig)){
            board[row][col] = dig; //ASSINING THE DIG TO PLACE AFTER CHECKING IF ITS SAFE.
            if (sudoku(board, row, col + 1)) //MOVE TO NEXT PLACE 
                return true;            //IF ALL THE PLACES ARE FILLED CORRCTLY , RETURN TRUE TO FN
            board[row][col] = '.';      //IN BACKTRACKING, IF PLACES ARE NOT CORRECTLY FILLED, THEN EMPTY THE PLACE TO FILL IT AGAIN BY CORRECT DIG.
        }
    }
    return false;                       //IF CAN'T BE FILLED CORRECTLY IN ANY SCEANARIO RETURN FALSE.
}
     //HELPER FN TO CALL THE ACTUAL FN.
void solve(vector<vector<char>> &board){
    sudoku(board, 0, 0); // CALLING THE ACTUAL FN FROM HELPER FN, AND INITIALISAION IS ALSO DONE IN HELPER FN.
}

int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    solve(board); //CALLING THE HELPER FN , WHICH WILL CALL THE ACTUAL FN.

    //    PRINTING THE SOLVED SUDOKU IF EXISTS.
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
// OUTPUT:-
// 5 3 4 6 7 8 9 1 2 
// 6 7 2 1 9 5 3 4 8 
// 1 9 8 3 4 2 5 6 7 
// 8 5 9 7 6 1 4 2 3 
// 4 2 6 8 5 3 7 9 1 
// 7 1 3 9 2 4 8 5 6 
// 9 6 1 5 3 7 2 8 4 
// 2 8 7 4 1 9 6 3 5 
// 3 4 5 2 8 6 1 7 9 