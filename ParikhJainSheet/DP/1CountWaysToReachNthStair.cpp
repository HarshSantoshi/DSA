#include <bits/stdc++.h> 
using namespace std;
int dp[100003];
int mod = 1e9+7;
int solve(int n){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = (solve(n-1) + solve(n-2))%mod;
}
int solveTab(int n){
    vector<int>dp2(n+1 , 0);
    dp[1]=1;
    dp[0]=1;
    for(int i=2;i<=n;i++){
        dp[i] = (dp[i-1]+dp[i-2])%mod;
    }
    return dp[n];
}
int solveSpaceOpt(int n){

    int prev2 = 1;
    int prev1 = 1;
    int curr =1;
    for(int i=2;i<=n;i++){
        curr = (prev2 + prev1 )%mod;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int countDistinctWays(int n) {
   memset(dp,-1,sizeof(dp));
//    return solve(n);

// return solveTab(n);
return solveSpaceOpt(n);
}
int main(){
    int  n ;
    cin>>n;
    cout<<countDistinctWays(n)<<endl;
}