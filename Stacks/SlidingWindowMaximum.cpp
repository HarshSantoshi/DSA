// https://leetcode.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;


vector<int> nextGreater(vector<int> &nums, int n)
{
    vector<int> ans(n);
    ans[n - 1] = n;
    stack<int> st;
    st.push(n - 1);
    for (int i = n - 2; i >= 0; i--)
    {
        while (st.size() > 0 && nums[i] >= nums[st.top()])
        {
            st.pop();
        }
        if (st.size() == 0)
        {
            ans[i] = n;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans;
    vector<int> nger = nextGreater(nums, n);

    int j = 0;
    for (int i = 0; i <= n - k; i++)
    {
        if (j < i)
        {
            j = i;
        }
        while (nger[j] < i + k)
        {
            j = nger[j];
        }
        ans.push_back(nums[j]);
    }
    return ans;
}
int main(){

    vector<int>nums = {1,3,-1,-3,5,3,6,7};
    int k =3;
    vector<int>res = maxSlidingWindow(nums, k);
    for(int i: res){
        cout<<i<<" ";
    }
    return 0;
}