// #include<bits/stdc++.h>
// using namespace std;
// bool isPossible(int val , int row , int col ,int n, vector<vector<int>>&board){
//    for(int i=0;i<n;i++){
//     //check for row
//     if(board[row][i]==val){
//         return false;
//     }
//     //check for col
//     if(board[i][col]==val){
//         return false;
//     }
//     if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val){
//         return false;
//     }

//    }
//    return true;
// }
// bool solve(vector<vector<int>>&board){
//     int n= board[0].size();
//     for(int  row = 0; row< n ;row++){
//         for(int col=0;col<n;col++){
//             //empty cells
//             if(board[row][col]==0){
//                 for(int val =1;val<=9;val++){
//                     if(isPossible(val , row , col ,n , board)){
//                         board[row][col]=val;
//                        bool  Solution_possible = solve(board);
//                         if(Solution_possible){
//                             return true;
//                         }
//                         else{
//                             //Backtrack
//                             board[row][col]=0;
//                         }
//                     }
//                 }
//                 return false;
//             }
//         }
//     }
//     return true;
// }
// void sudokuSolver(vector<vector<int>>&ans){
//    if(solve(ans)){
//     cout<<"True"<<endl;
//    }
//    else{
//     cout<<"False"<<endl;
//    }
//    return;
// }
// int main(){
//     // int arr[9][9];
//     vector<vector<int>>ans;
    
//     // write your code here
//     // vector<vector<int>> v;
//     int  a;
//     // taking input into 2D vector from user
//     for(int i=0 ; i<9 ; i++) {
//          vector<int> p;
//          for(int j=0 ; j<9 ; j++) {
//               cin>>a;
//               p.push_back(a);
//          }
//          ans.push_back(p);
//     }
//    sudokuSolver(ans);
//     return 0;
// }






#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int row , int col , vector<vector<char>>&board ,char val){
    for(int i=0;i<9;i++){
        if(board[row][i]==val)return false;

        if(board[i][col]==val)return false;

        if(board[3*(row/3) +i/3][3*(col/3) +i%3]==val)return false;

    }
    return true;
}
bool solve(vector<vector<char>>&board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){

            if(board[i][j]=='.'){

                for(char val = '1' ;val<='9';val++){
                    if(isSafe(i ,j ,board , val)){
                        board[i][j]=val;
                        bool solveforMore = solve(board);
                        if(solveforMore){
                            return true;
                        }
                        else{
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
 void solveSudoku(vector<vector<char>>& board) {
       solve(board); 
    }
int main(){
    int n;
    cin>>n;
    vector<vector<char>>ans;
    char  a;
    // taking input into 2D vector from user
    for(int i=0 ; i<9 ; i++) {
         vector<char> p;
         for(int j=0 ; j<9 ; j++) {
              cin>>a;
              p.push_back(a);
         }
         ans.push_back(p);
    }
    

    solveSudoku(ans);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}