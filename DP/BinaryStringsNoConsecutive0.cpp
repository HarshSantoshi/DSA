#include<bits/stdc++.h>
using namespace std;
int CountBinaryStrings(int n ){
    int ozero = 1; // string ending at 0
    int oone = 1;  //string ending at 1
    int total = ozero + oone;
    for(int i=2;i<=n;i++){
        int nzero = oone;
        int none = total;
        total = nzero + none;
        ozero = nzero;
        oone = none;
    }
    return total;
}
int main(){
   int n ;
   cin>>n;
   cout<<CountBinaryStrings(n)<<endl;
  
}