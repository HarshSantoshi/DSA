#include <bits/stdc++.h> 
int findMinimumCost(string str) {

  // Write your code here

  int n= str.length();
  if(n%2!=0)return -1;
  int ans=0;
  stack<char>st;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '{') {
      st.push(str[i]);
    } 
    else {
      if (st.empty()) 
      {
        st.push('{');
        ans++;
        
      } 
      else
      {
        st.pop();
      }
    }
  }
  ans += st.size() / 2;
  return ans;
}
  // int open =0;
  // int close =0;
  // for (int i = 0; i < n; i++) {
  //   if (str[i] == '}' && !st.empty()) {
  //     if (st.top() == '{'){
  //       st.pop();
  //     }
  //     else{
  //       st.push(str[i]);
  //     }
        
  //   } 
  //   else {
  //     st.push(str[i]);
  //   }
  // }

  // while(!st.empty()){
  //   if(st.top()=='{'){
  //     open++;
  //   }
  //   else{
  //     close++;
  //   }

  // }

  // int ans = max(open, close) - (n / 2);
  //  return ans;

  // int totalBracket = open + close;
  // if(open==close){
  //   return 0;
  // }
  // if(totalBracket%2==0){
  //   int ans = max(open , close) - (totalBracket/2);
  //   return ans;
  // }
  // else{
  //   return -1;
  // }

