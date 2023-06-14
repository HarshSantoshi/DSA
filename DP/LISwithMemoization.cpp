class Solution {
public:
    // int lengthOfLIS(vector<int>& nums) {
    //     int ans = 1, n = nums.size();
    //     vector<int> dp(n, 1);
    //     for(int i = 0; i < n; i++) 
    //         for(int j = 0; j < i; j++) 
    //             if(nums[i] > nums[j]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //                 ans = max(ans, dp[i]);
    //             }
				   
    //     return ans;
    // }
    int dp[2501][2503];
    int solve(int idx , int prev_indx , vector<int>&nums){
        if(idx == nums.size()){
            return 0;
        }
        if(dp[idx][prev_indx+1] != -1){
            return dp[idx][prev_indx+1];
        }
        int exclude = solve(idx+1 , prev_indx , nums);
        int include = 0;
        if(prev_indx == -1 || nums[idx]>nums[prev_indx])
        include = solve(idx + 1 , idx , nums) + 1;

        return dp[idx][prev_indx+1] = max(include , exclude);
    }
    int solveTab(vector<int>&nums, int n){
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));
        for(int curr = n-1 ;curr>=0 ;curr--){
            for(int prev = curr-1 ; prev>=-1;prev--){
                int exclude = dp[curr+1][prev + 1];
                int include = 0;
                if(prev == -1 || nums[curr]>nums[prev])
                include = dp[curr + 1][prev + 1] + 1;
                dp[curr][prev+1] max(include, exclude)
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int n = nums.size();
        return solveTab(nums , n);
        return solve( 0 , -1  , nums);
    }
};