#include<iostream>
using namespace std;
int main(){int n;
cin>>n;
for(int i=n;i>=1;i--){
    for(int j=1;j<=n;j++){
       if(j<=i){
           cout<<j;
       }
       else{
           cout<<"**";
       }
    }
    for(int k=i;k>=1;k--){
        if(k<=i){
            cout<<k;
        }
        else{
            cout<<"*";
        }
    }
    cout<<endl;
}
}