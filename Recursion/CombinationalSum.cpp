#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> &candidates, int target, int idx, vector<int> &temp , vector<vector<int>>&ans)
{

    if (idx == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
           
        }
        return ;
    }
    if (candidates[idx] <= target)
    {
        temp.push_back(candidates[idx]);
        solve(candidates, target - candidates[idx], idx, temp , ans);
        temp.pop_back();
    }
    solve(candidates , target , idx+1 , temp , ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(candidates, target, 0, temp, ans);
    return ans;
}
int main()
{
    vector<int> nums = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> res = combinationSum(nums, target);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}