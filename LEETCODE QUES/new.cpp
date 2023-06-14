vector<int> dp;
     public:
     bool canJump(vector<int>& nums) {
        int n = nums.size();
          dp.assign(n,-1);
          return solve(0,nums,n);   
     }
     bool solve(int i,vector<int> nums, int n){
        
        if(i==n-1) return true;
        if(dp[i]!=-1) return dp[i];
        int reachable=i+nums[i];
        
        for(int k=i+1;k<=reachable;k++){
             if(solve(k,nums , n)){
                return dp[i]=true;
             } 
        }
        return dp[i]=false;
    }