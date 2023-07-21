#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(vector<int>arr, int n)
{
    // Write Your Code here
    int ans = 1;
    vector<int> dp(n + 1, 1);
    for (int i = 0; i < n; i++)
    {
        int maxi = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                maxi = max(maxi, dp[j]);
            }
        }
        dp[i] = 1 + maxi;
        ans = max(ans, dp[i]);
    }
    return ans;
}
int LISusingBinarySearch(vector<int> nums)
{
    vector<int> temp;
    temp.push_back(nums[0]);
    int length = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > temp.back())
        {
            temp.push_back(nums[i]);
            length++;
        }
        else
        {
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }
    return length;
}

int main()
{
    vector<int>arr = {1, 8, 3, 11, 9};
    cout << longestIncreasingSubsequence(arr, 4) << endl;
}