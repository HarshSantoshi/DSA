// #include <bits/stdc++.h>
// using namespace std;
// // int board[10][10];

// // bool isPossible(int n, int row, int col)
// // {
// //     //We only need to check vertically up, diagonally left and diagonally right
// //     //Verticaly up
// //     for (int i = row - 1; i >= 0; i--)
// //     {
// //         if (board[i][col] == 1)
// //         {
// //             return false;
// //         }
// //     }

// //     //Diagonally left
// //     for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
// //     {
// //         if (board[i][j] == 1)
// //         {
// //             return false;
// //         }
// //     }

// //     //Diagonally right
// //     for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
// //     {
// //         if (board[i][j] == 1)
// //         {
// //             return false;
// //         }
// //     }

// //     return true;
// // }

// // void printAllPossibleCombination(int n, int row)
// // {
// //     if (row == n)
// //     {
// //         //Found a possible combination
// //         //Print the combination
// //         //Return
// //         for (int i = 0; i < n; i++)
// //         {
// //             for (int j = 0; j < n; j++)
// //             {
// //                 cout << board[i][j] << " ";
// //             }
// //         }
// //         cout << endl;
// //         return;
// //     }
// //     //Checking for possible correct position to place queen in reach row
// //     for (int i = 0; i < n; i++)
// //     {
// //         if (isPossible(n, row, i))
// //         {
// //             board[row][i] = 1;
// //             printAllPossibleCombination(n, row + 1);
// //             board[row][i] = 0;
// //         }
// //     }
// // }

// // void nQueens(int n)
// // {
// //     //Puting 0 at each element of board matrix
// //     memset(board, 0, 10 * 10 * sizeof(int));
// //     //Printing all possible solutions
// //     printAllPossibleCombination(n, 0);
// // }

// int main()
// {
//     int n;
//     cin >> n;
//    vector<vector<string>>ans= nQueens(n);
//    for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         cout<<ans[i][j];
//     }
//    }
//     return 0;
// // }


#include<iostream>
#include<vector>
#include<string.h>
#include<unordered_map>
using namespace std;

// bool isSafe(int row, int col ,vector<string> &board  ,int n){
//     int x= row; 
//     int y=col;
//     //Same row
//     while(y>=0){
//         if(board[x][y]=='Q'){
//             return false;
           
//         }
//          y--;
//     }

//     //Same diagonal
//     y=col;x=row;
//     //upper triangle
//     while(x>=0 &&y>=0){
//         if(board[x][y]=='Q'){
//             return false;
           
//         }
//          y--;
//          x--;
//     }

//     y=col;x=row;
//     //lower triangle
//     while(x<n &&y>=0){
//         if(board[x][y]=='Q'){
//             return false;
           
//         }
//          y--;
//          x++;
//     }
//     return true;

// }

void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n ,unordered_map<int,bool>&checkDo , unordered_map<int,bool>&checkR , unordered_map<int,bool>&checkUp)
{
    
    if (col == n)
    {
    ans.push_back(board);
            return ;
        
    }
    //Solving for 1 case and rest recursion will take care
    for(int row = 0;row<n;row++){
          if(checkR[row]==false && checkDo[row+col] ==false && checkUp[n-1+col-row] ==false){
            board[row][col]='Q';
            // Solve for next cols
            checkR[row]=true;
            checkDo[row+col]=true;
            checkUp[n-1+(col-row)]=true;
            solve(col+1,ans,board,n , checkDo,checkR,checkUp);
            //Backtracking
            board[row][col]='.';
            checkR[row]=false;
            checkDo[row+col]=false;
            checkUp[n-1+(col-row)]=false;
        }
        
    }
}
vector<vector<string>> solveNQueens(int n , unordered_map<int,bool>&checkDo , unordered_map<int,bool>&checkR ,unordered_map<int,bool>&checkUp)
{
   vector<string> board(n, string(n, '.'));
   vector<vector<string>> ans;
    solve(0, ans, board, n , checkDo,checkR,checkUp);
    return ans;
}

int main(){
int n ;
  cin>>n;

unordered_map<int,bool>checkR;
    for(int i=0;i<n;i++){
        checkR[i]=false;
    }
    unordered_map<int,bool>checkUp;
    for(int i=0;i<2*n-1;i++){
        checkUp[i]=false;
    }
    unordered_map<int,bool>checkDo;
    for(int i=0;i<2*n-1;i++){
        checkDo[i]=false;
    }
  vector<vector<string>>res =solveNQueens(n ,checkDo,checkR,checkUp);

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<res[i][j];
    }
    cout<<endl;
}
  }