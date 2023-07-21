#include<bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<long>dp(value+1 , 0);
    dp[0] =1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=value;j++ ){
            if(j>=denominations[i])
                dp[j] += dp[j-denominations[i]];
            
        }
    }
    return dp[value];
}
int main(){
    int n ;
    cin>>n;
    int * denominations = new int[n];
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        denominations[i] = a;
    }
    int target ;
    cin>>target;
    cout<<countWaysToMakeChange(denominations , n , target)<<endl;
}