#include<bits/stdc++.h>
using namespace std;
long long minCost(vector<int> &nums, vector<int> &cost)
{
    int n = nums.size();

    long long totalEle = 0;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        vp[i] = {nums[i], cost[i]};
        totalEle += vp[i].second;
    }
    sort(vp.begin(), vp.end());

    int i = 0;
    long long median = 0;
    long long total = (totalEle + 1) / 2;

    while (total > 0 && i < n)
    {
        total -= vp[i].second;
        median = vp[i].first;
        i++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (abs(1ll * nums[i] - median) * (1ll * cost[i]));
    }

    return ans;
}
int main(){
    vector<int>nums = {2 ,41 ,5 ,21 ,3, 234};
    vector<int>cost = {2,51,7,1,3,732};
    cout<<minCost(nums , cost)<<endl;
}