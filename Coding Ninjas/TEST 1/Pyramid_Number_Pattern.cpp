#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int i=1;
while(i<=n){
    int spaces=1;
    while(spaces<=(n-i)){
        cout<<" ";
        spaces =spaces+1;
    }
    for(int j=i;j>=1;j--){
        cout<<j;
    }
    for(int k=2;k<=i;k++){
        cout<<k;
    }
    cout<<endl;
    i++;
}
}

