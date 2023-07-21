#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    int ans = 0;
    dp[0][0] = -prices[0];
    for (int i = 1; i < n; i++)
    {
        if (dp[i - 1][1] - prices[i] > dp[i - 1][0])
        {
            dp[i][0] = dp[i - 1][1] - prices[i];
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
        }
        if (prices[i] + dp[i - 1][0] - fee > dp[i - 1][1])
        {
            dp[i][1] = prices[i] + dp[i - 1][0] - fee;
        }
        else
        {
            dp[i][1] = dp[i - 1][1];
        }
    }
    return dp[n - 1][1];
}
int main(){
    vector<int>prices = { 1 , 4 , 2 ,8 , 9 ,3 , 10 ,11 , 4 , 12 , 6};
    int fee = 3;
    cout<<maxProfit(prices , fee)<<endl;

}