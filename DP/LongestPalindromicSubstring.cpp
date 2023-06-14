#include<bits/stdc++.h>
using namespace std;

  string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>>grid(n,vector<bool>(n,false));

    int start = 0;
    int maxLength = 1;
    // for maxLength == 1;
    for(int i=0;i<n;i++){
        grid[i][i] =true;
    }
    //for maxLength == 2
    for(int i=0;i<n-1;++i){
        if(s[i+1] == s[i]){
            grid[i][i+1] = true;
            maxLength = 2;
            start = i;
        }
    }

    //for maxLength == 3

   for (int k = 3; k <= n; k++) {
        for (int i = 0; i <= n - k + 1; i++) {
            if (s[i] == s[i + k - 1] && grid[i + 1][i + k - 2]) {
                grid[i][i + k - 1] = true;
                if (k > maxLength) {
                    maxLength = k;
                    start = i;
                }
            }
        }
    }
    string ans = "";
    for(int i=start ;i<start + maxLength ;i++){
        ans+=s[i];
    }
    return ans;
}
int main(){
    string s = "bb";
   
    string ans =  longestPalindrome(s);
    
    cout<<ans<<endl;
    return 0;
}