#include<bits/stdc++.h>
using namespace std;
int dp[101];
int solve(vector<int>&prices , int len){
	if(len==0){
		return 0;
	}
	if(dp[len]!=-1){
		return dp[len];
	}
	int ans = 0;
	for(int i=1;i<=prices.size();i++){
		if(len-i>=0)
		ans = max(ans , solve(prices , len - i)+prices[i-1]);
	}
	return dp[len]= ans;
}
int solveTab(vector<int>&prices , int len){
	vector<int>dp2(len+1 , 0);
	for(int i=1 ;i<=len;i++){
		for(int j=1;j<=prices.size();j++){
			if(j>=i)
			dp2[i] = max(dp[i] , dp2[j-i] + prices[i-1]);
		}
	}
	return dp2[len];
}
int solveLR(vector<int>&prices , int n){
	vector<int>nprices(n+1) ;
	for(int i=0;i<n;i++){
		nprices[i+1] = prices[i];
	}
	vector<int>dp(n+1,0);
	dp[1] =nprices[1];
	for(int i=2;i<=n;i++){
		dp[i] = nprices[i];
		int Lidx = 1;
		int rightidx = i-1;
		while(Lidx <= rightidx){
			dp[i] = max(dp[i] , dp[Lidx] + dp[rightidx]);
			Lidx++;
			rightidx--;
		}
	}
	return dp[n];
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
	memset(dp,-1,sizeof(dp));
	return solveTab(price , n);
}
int main(){
    vector<int>price = {1 ,3 ,5 ,9, 10};
    int n = 5;
    cout<<cutRod(price , n)<<endl;
}