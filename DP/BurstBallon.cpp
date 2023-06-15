// https://leetcode.com/problems/burst-balloons/description/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int solve(int i, int j, vector<int> &nums)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int maxi = INT_MIN;
    for (int idx = i; idx <= j; idx++)
    {
        int coins = nums[idx] * nums[i - 1] * nums[j + 1] + solve(i, idx - 1, nums) + solve(idx + 1, j, nums);
        maxi = max(maxi, coins);
    }
    return dp[i][j] = maxi;
}
int solveTab(vector<int>&nums , int n ){
    vector<vector<int>>dp2(n+2 , vector<int>(n+2 , 0));
    int maxi = INT_MIN;
    for(int i= n ;i>=1;i--){
        for(int j= 1;j<=n;j++){
            if(i>j){
                continue;
            }
            int maxi = INT_MIN;
            for (int idx = i; idx <= j; idx++)
            {
                int coins = nums[idx] * nums[i - 1] * nums[j + 1] + dp2[i][idx-1] + dp2[idx+1][j] ;
                maxi = max(maxi, coins);
            }
            dp2[i][j] = maxi;
        }
       
    }
    return dp2[1][n];
    
}
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    dp.resize(n + 1, vector<int>(n + 1, -1));
    return solveTab(nums , n);
    return solve(1, n, nums);
}
int main(){
    vector<int> nums = { 3 , 1 , 4 , 8};
    int ans = maxCoins(nums);
    cout<<ans<<endl;
    return 0;
}