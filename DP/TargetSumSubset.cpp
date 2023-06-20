#include<bits/stdc++.h>
using namespace std;
bool Present(vector<int>&nums , int target){
    int n = nums.size();
    bool dp[n+1][target+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=target;j++){
            if(j>=nums[i]){
                dp[i][j] = dp[i-1][j] ||  dp[i-1][j-nums[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][target];

}
int main(){
    vector<int>nums = {4,9};
    int target = 11;
    if(Present(nums , target)){
        cout<<"The target can be formed with the subsets";
    }
    else{
        cout<<"The target can not be formed";
    }
}