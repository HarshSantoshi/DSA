  public:

    //Function to return max value that can be put in knapsack of capacity W.
    // int solve(int wt[] , int val[] , int W  , int idx){
        
    //     if(idx<0){
    //         return 0;
    //     }
    //     if(dp[idx][W]!=-1)
    //     {
    //         return dp[idx][W];
    //     }
    //     int include  =0;
    //     if(W-wt[idx]>=0)
    //         include= solve( wt , val , W- wt[idx] , idx -1) + val[idx];
    //     int exclude = solve( wt , val , W , idx -1);
    //     return dp[idx][W] = max(include, exclude) ;
    // }
    int knapSack(int W, int wt[], int val[], int n) 
    
    {
        // vector<vector<int>>dp(n , vector<int>(W+1 , 0));
        vector<int>prev(W+1 , 0) , curr(W+1 , 0);
        for(int i=wt[0];i<=W;i++){
            prev[i] = val[0];
        }
        for(int idx =1 ;idx<n;idx++){
            for(int WT = 0 ;WT <= W ;WT++){
                int include  =0;
                if(WT-wt[idx]>=0)
                    include= prev[WT - wt[idx]] + val[idx];
                int exclude = prev[WT];
                curr[WT] = max(include, exclude) ;
            }
            prev = curr;
        }
        return prev[W];
        // return solve( wt , val , W , n-1);
    }