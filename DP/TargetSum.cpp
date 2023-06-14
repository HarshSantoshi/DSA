//https://leetcode.com/problems/target-sum/description/
class Solution {
public:
    /*********Using Memoisation*********/
    // int dp[21][1001];
    // int solve(vector<int>&nums , int target , int idx){     
    //     if(idx == 0){
    //         if(target == 0 && nums[0] == 0 )return 2;
    //         if(target == 0 || nums[0]== target)return 1;
    //         return 0;
    //     }
       
    //     if(dp[idx][target]!=-1){
    //         return dp[idx][target];
    //     }

    //     int include = 0;
    //     if(target-nums[idx]>=0)
    //         include= solve(nums , target - nums[idx] , idx-1);
    //     int exclude = solve(nums , target , idx-1);
    //     return dp[idx][target] = include + exclude;
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int totalSum  = accumulate(nums.begin() , nums.end() , 0);
    //     //S2 - S1 = target
    //     //S2 + S1 = totalSum
    //     // Therefore ,  S1 = (TotalSum - target)/2;
    //     memset(dp ,-1 , sizeof(dp));
    //     if(totalSum - target <0 || (totalSum - target)%2){
    //         return 0;
    //     }
    //     int sumTobeFined = (totalSum - target)/2;
    //     int n  = nums.size();
    //     int ways = solve( nums , sumTobeFined , n-1);
    //     return ways;
    // }
    /************Using Tabulation**********/
    // int solveTab(vector<int>&nums , int target){
    //     int n  = nums.size();
    //     vector<vector<int>>dp(n , vector<int>(target +1 , 0));
    //     for(int i=0;i<n;i++){
    //         dp[i][0] = 1 ;
    //     }
        
    //     if(nums[0]==0)dp[0][0]=2;
    //     if(nums[0]!=0 and target>=nums[0]) dp[0][nums[0]] =1;
    //     for(int idx = 1 ;idx<n;idx++ ){
    //         for(int sum = 0 ; sum<= target ;sum++){
    //             int include = 0;
    //             if(sum-nums[idx]>=0)
    //                 include= dp[idx-1][sum-nums[idx]];
    //             int exclude = dp[idx-1][sum];
    //             dp[idx][sum] = include + exclude;
    //         }
    //     }
    //     return dp[n-1][target];
    // }
    // int solve(int n , int target ,vector<int>&nums){
    //     int totalSum = accumulate(nums.begin() , nums.end() , 0);
    //     if(totalSum - target <0 || (totalSum - target)%2){
    //         return 0;
    //     }
    //     int sumTobeFined = (totalSum - target)/2;
    //     return solveTab( nums , sumTobeFined );
        
    // }
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     int n  = nums.size();
    //     return solve( n , target , nums);
    // }

    /*********Space Optimization***********/

    int solveSO(vector<int>&nums , int target){
        int n  = nums.size();
        // vector<vector<int>>dp(n , vector<int>(target +1 , 0));
        vector<int>prev(target+1 , 0) , curr(target+1 ,0);
        // for(int i=0;i<n;i++){
        //     dp[i][0] = 1 ;
        // }
        prev[0] = 1 ;
        if(nums[0]==0)prev[0]=2;
        if(nums[0]!=0 and target>=nums[0]) prev[nums[0]] = 1;
        for(int idx = 1 ;idx<n;idx++ ){
            for(int sum = 0 ; sum<= target ;sum++){
                int include = 0;
                if(sum-nums[idx]>=0)
                    include= prev[sum-nums[idx]];
                int exclude = prev[sum];
                curr[sum] = include + exclude;
            }
            prev = curr;
        }
        return prev[target];
    }
    int solve(int n , int target ,vector<int>&nums){
        int totalSum = accumulate(nums.begin() , nums.end() , 0);
        if(totalSum - target <0 || (totalSum - target)%2){
            return 0;
        }
        int sumTobeFined = (totalSum - target)/2;
        return solveSO( nums , sumTobeFined );
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n  = nums.size();
        return solve( n , target , nums);
    }
};