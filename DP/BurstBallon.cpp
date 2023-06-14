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
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    dp.resize(n + 1, vector<int>(n + 1, -1));
    return solve(1, n, nums);
}
int main(){
    vector<int> nums = { 3 , 1 , 4 , 8};
    int ans = maxCoins(nums);
    cout<<ans<<endl;
    return 0;
}