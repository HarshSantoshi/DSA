#include<bits/stdc++.h>
using namespace std;
int dp[151][151];
bool solve(string a , string b , int i , int j , string c , int k){
	if(i>=a.length() && j>=b.length() && k>=c.length()){
		return true;
	}
	if( i<a.length()&& j<b.length() && k<c.length() && a[i]==b[j] && a[i]!=c[k]){
		return false;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	else if( i<a.length()&& j<b.length() && k<c.length() && a[i]==b[j] && a[i]==c[k]){
		return dp[i][j] =  solve(a, b , i+1 , j , c , k+1)|| solve(a , b , i , j+1 , c ,k+1);
	}
	else if( i<a.length()&&k<c.length() && a[i]==c[k]){
		return  solve(a , b , i+1 , j , c , k+1);
	}
	else if( j<b.length() && k<c.length() && b[j]==c[k]){
		return  solve(a , b , i , j+1 , c, k+1);
	}

}
int solveMemo(string A , string B , string C){
	if(A.length()+B.length()!=C.length())return false;
	vector<vector<int>>dp(A.length()+1, vector<int>(B.length()+1, 0));
	for (int i = 0; i <= A.length(); ++i) {
		for (int j = 0; j <= B.length(); ++j) {
			if (i == 0 && j == 0){
				dp[i][j] = true;
			}
			else if (i == 0) {
				if (B[j - 1] == C[j - 1])dp[i][j] = dp[i][j - 1];
			}
			else if (j == 0) {
				if (A[i - 1] == C[i - 1])dp[i][j] = dp[i - 1][j];
			}
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]){
				dp[i][j]= (dp[i - 1][j]|dp[i][j - 1]);
			}    
			else if (A[i - 1]!=C[i + j - 1]&& B[j - 1]==C[i + j - 1]){
				dp[i][j] = dp[i][j - 1];
			}    
			else if (A[i - 1]==C[i + j - 1]&&B[j - 1]!=C[i + j - 1]){
				dp[i][j] =dp[i - 1][j];
			}
		}
	}
	return dp[A.length()][B.length()];
}

bool isInterleave(string a, string b, string c){
	
	if(a.length() + b.length() != c.length()){
		return false;
	}
	memset(dp , -1 , sizeof(dp));
	int n = c.length();
	return solve(a , b , 0 , 0 , c ,0);
}
int main(){
    string a, b , c;
    cin>>a>>b>>c;
    cout<<isInterleave(a , b , c)<<endl;
}