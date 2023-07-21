#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<int> &nums, int idx)
{
    int n = nums.size();
     
    vector<vector<int>>ans;
    vector<int>temp;
     temp.push_back({});
     ans.push_back(temp);
    for(int i=1;i<(1<<n);i++){
        int j =0;
        int ele = i;
        vector<int>temp;
        while(ele>0){
            int lastBit = ele & 1;
            if(lastBit==1){
                temp.push_back(nums[j]);
            }
            j++;
            ele=ele>>1;
            
        }
        ans.push_back(temp);
    }
    return ans;
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans = solve(nums, 0);
    set<vector<int>>out;
    for(auto i:ans){
        sort(i.begin(), i.end());
       out.insert(i);
    }
    vector<vector<int>>res;
   
    for(auto i : out){
       res.push_back(i);
       
    }
    return res;
}
int main(){
    vector<int>nums = {4,4,4,1,4};
    vector<vector<int>>ans = subsetsWithDup(nums);
    for(auto i:ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}