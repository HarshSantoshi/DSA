#include<bits/stdc++.h>
using namespace std;
int PathWithMaximumSum( vector<vector<int>>&arr , int n , int x , int y){
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return INT_MIN;
    }
    else if (y == n - 1) {
        return arr[x][y];
    }
   
    int topRight = PathWithMaximumSum(arr , n , x-1 , y+1);
    int right = PathWithMaximumSum(arr , n , x , y+1) ;
    int bottomRight =  PathWithMaximumSum(arr , n , x+1 , y+1);
    return arr[x][y] + max({right , topRight ,bottomRight});
}
int main(){
    int N = 6;
    vector<vector<int>>arr(N , vector<int>(N,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    int maxi = INT_MIN;
    for(int i=0;i<N;i++){
        maxi = max(maxi , PathWithMaximumSum(arr , N , i , 0));
    }
    cout<<maxi<<endl;

}
