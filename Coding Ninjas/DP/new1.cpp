#include <bits/stdc++.h>
using namespace std;
 

int minOperation(string &s)
{
    int n = s.size();
    int pos = -2;
 
    
    for (int i = 0; i < s.size(); i++) {
 
       
        if (s[i] == '1') {
 
            pos = i;
            break;
        }
    }
 
   
    if (pos == -2) {
      // cout<<0<<endl;
       return 0;
    }
 int last =1;
 int count =0;
   for(int i=pos+1;i<n;i++){
    if(s[i]=='0'){
        
    }
   }

}
 

int main()
{
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       string s;
      cin>>s;
 
   cout<< minOperation(s)<<endl;
   
    }
    
}