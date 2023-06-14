//https://practice.geeksforgeeks.org/problems/last-match1928/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
class Solution{   
public:
    vector<int>LPS(string combinedString){
        int len = 0;
        int  n = combinedString.length();
        vector<int>lps(n,0);
        
        int i=1;
        while(i<n){
            if(combinedString[i]==combinedString[len]){
                len++;
                lps[i] =  len;
                i++;
            }
            else{
                if(len>0){
                    len = lps[len-1];
                }
                else{
                    lps[i] =0;
                    i++;
                }
            }
        }
        return lps;
    }
    int findLastOccurence(string A,string B){
        //Code Here
        string combinedString = B + "#" + A;
        vector<int>lps = LPS(combinedString);
        int n = combinedString.length();
        int b = B.length();
        int ans =-1;
        for(int i=b;i<n;i++){
            if(lps[i]==b){
                ans =  i-2*b+1;
            }
        }
        return ans;
    }
};