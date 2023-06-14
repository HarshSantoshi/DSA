#include <bits/stdc++.h> 
using namespace std;
string binaryShopping(string S, int P)
{
    // Write your code here.   
    // int n = S.length();
    // string res="";
    // int x=0;
    // int count =0;
    // int first1=0;
    // int second1=0;
    // for( int i=n-1;i>=0;i--){
    //     if(count==2){
    //         x=i;
    //         break;
    //     }
    //     if(S[i]=='1' && count==0){
    //        first1 =i;
    //         count++;
    //     }
    //     else if(S[i]=='1' && count==1){
    //         second1=i;
    //         count++;
    //     }

    // }

    // for(int i=0;i<n;i++){
    //     if(i==first1 || i==second1){
    //         res+='0';
    //     }
    //     else{
    //         res+=S[i];
    //     }
    // }

    // return res;

      int count = 0;

      int n = S.length() - 1;

      if (n == 0)

      {
        S[0] = '1';
        return S;
      }
      for (int i = n; i >= 0; i--) {
        if (S[i] == '1') {
          S[i] = '0';
          count++;
        }
        if (count == 2)
          break;
      }

      if (count == 2 || count == 0)
        return S;
      if (count < 2)

      {
        S[0] = '1';
        return S;
      }
    }
