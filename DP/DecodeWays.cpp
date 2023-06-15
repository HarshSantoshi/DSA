#include<bits/stdc++.h>
using namespace std;
int solve(string s, int idx, int n)
{
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int oneDigit = s[i] - '0';
        int twoDigit = (s[i] - '0') + (s[i - 1] - '0') * 10;
        if ((s[i - 1] - '0') == 0)
        {
            twoDigit = 0;
        }
        if (oneDigit > 0)
        {
            dp[i] = dp[i - 1];
        }
        if (twoDigit <= 26 && twoDigit > 0)
        {
            if (i >= 2)
            {
                dp[i] += dp[i - 2];
            }
            else
            {
                dp[i] += 1;
            }
        }
    }
    return dp[n - 1];
}
int numDecodings(string s)
{
    if (s[0] == '0')
    {
        return 0;
    }
    int n = s.length();
    if (n == 1)
    {
        return 1;
    }
    return solve(s, 0, n);
}
int main(){
    string s = "226713";
    int ans = numDecodings(s);
    cout<<ans<<endl;
    return 0;
}