#include<bits/stdc++.h>
using namespace std;
int CountWays(vector<int>&nums , int target){
    int n = nums.size();
    int dp[target+1] ;
    for(int i=1;i<=target;i++){
        dp[i] =0;
    }
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<=target;j++){
            if(j>=nums[i])
                dp[j] += dp[j-nums[i]];
            else dp[j] += 0;

            if(j==0){
                dp[j] =1;
            }
           
        }
        
    }
    return dp[target];
}
int main(){
    vector<int>nums = {2,3,5};
    int target = 7;
    cout<<CountWays(nums , target)<<endl;
}