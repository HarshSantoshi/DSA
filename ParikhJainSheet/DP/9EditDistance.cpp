#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];
int solve(string s, string t, int i, int j)
{
    if (i >= s.length())
    {
        return t.length() - j;
    }
    if (j >= t.length())
    {
        return s.length() - i;
    }
    if (s == t)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] == t[j])
    {
        return dp[i][j] = solve(s, t, i + 1, j + 1);
    }
    else
    {
        int insert = solve(s, t, i, j + 1);
        int deleteEle = solve(s, t, i + 1, j);
        int replace = solve(s, t, i + 1, j + 1);
        return dp[i][j] = 1 + min({insert, deleteEle, replace});
    }
}
int solveTab(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int insert = dp[i][j - 1];
                int deleteEle = dp[i - 1][j];
                int replace = dp[i - 1][j - 1];
                dp[i][j] = 1 + min({insert, deleteEle, replace});
            }
        }
    }
    return dp[n][m];
}
int editDistance(string str1, string str2)
{
    if (str1 == str2)
        return 0;
    // memset(dp , -1 , sizeof(dp));
    return solveTab(str1, str2);
    // return solve(str1 , str2 ,0 ,0);
}
int main()
{
    string s ,  t;
    cin>>s>>t;
    cout << editDistance(s,t) << endl;
}