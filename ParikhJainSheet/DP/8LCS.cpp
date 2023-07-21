#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(string s , string t , int i , int j){
	if(i>=s.length()){
		return 0;
	}
	if(j>=t.length()){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	if(s[i]==t[j]){
		return dp[i][j]= 1 + solve(s , t  , i+1 , j+1);
	}
	else{
		return dp[i][j] = max(solve(s , t , i+1 , j) , solve(s , t,  i , j+1));
	}
}

int solveTab(string s, string t){
	int n = s.length();
	int m = t.length();
	vector<vector<int>>dp2(n+1 , vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i-1]==t[j-1]){
				dp2[i][j] = 1 + dp2[i-1][j-1];
			}
			else{
				dp2[i][j] = max(dp2[i-1][j] , dp2[i][j-1]);
			}
		}
	}
	return dp2[n][m];
}
int lcs(string s, string t)
{

	return solveTab(s, t);
}
int main()
{
    string s ,  t;
    cin>>s>>t;
    cout << lcs(s,t) << endl;
}