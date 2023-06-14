//https://leetcode.com/problems/shortest-palindrome/description/

class Solution {
#include<bits/stdc++.h>
#include<vector>
public:
    int LPS(string s){
        //Length of Longest proper prefix which is also proper suffix
        int len = 0;
        int n = s.length();
        vector<int>lps(n,0);
        int i=1;
        while(i<s.length()){
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
                i++;
                
            }
            else{
                if(len!=0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps[n-1];
    }
    string shortestPalindrome(string s) {
        int n  = s.length();
        if(n==0){
            return s;
        }
        string rev = s;
        reverse(rev.begin() , rev.end());
        string long_s = s + "+" + rev;
        int longestPalindromeLength = LPS(long_s);
       
        string res = "";
        for(int i=n-1;i>=longestPalindromeLength;i--){
            res+=s[i];
        }
        res +=s;
        return res;
    }
};