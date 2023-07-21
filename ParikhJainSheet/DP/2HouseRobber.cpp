#include<bits/stdc++.h>
using namespace std;
int maxMoneyLooted(vector<int> &houses, int n)
{
	vector<int>dp(n+1 , 0);
	dp[1] = houses[0];
	for(int i=2;i<=n;i++){
		dp[i] = max(dp[i-2] + houses[i-1] , max(dp[i-1] , houses[i-1]));
	}
	return dp[n];
}
int maxMoneyLootedSO(vector<int> &houses, int n)
{

    int prev2 =0 ;
    int prev1 = houses[0];

    int curr =prev1;
	for(int i=2;i<=n;i++){
		curr = max(prev2 + houses[i-1] , max(prev1 , houses[i-1]));
        prev2 = prev1;
        prev1 = curr;
	}
	return prev1;
}
int main(){
    vector<int>houses = {10 , 2 , 3 , 11};
    int n = houses.size();
    cout<<maxMoneyLootedSO(houses , n)<<endl;
}