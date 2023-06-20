#include<bits/stdc++.h>
using namespace std;
int CountPermutations(vector<int>&nums , int target){
    int n = nums.size();
    int dp[target+1] ;
    for(int i=1;i<=target;i++){
        dp[i] =0;
    }
    dp[0] = 1;
    for(int i=1;i<=target;i++){
        for(int j = 0 ;j<nums.size();j++){
            if(i-nums[j]>=0)
                dp[i] += dp[i-nums[j]];
            else{
                dp[i]+=0;
            }
        }
    }


    return dp[target];
}
int main(){
    vector<int>nums = {2,3,5};
    int target = 7;
    cout<<CountPermutations(nums , target)<<endl;
}