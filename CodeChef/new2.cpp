#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void solve(){
    ll N,M;
    cin>>N>>M;
    ll budget[N] , Bonus[M];
    for(int i=0;i<N;i++){
        cin>>budget[i];
    }
    for(int i=0;i<M;i++){
        cin>>Bonus[i];
    }
    ll maxAns=INT_MIN;
    for(int i=0;i<M;i++){
        ll sum=0;
        for(int j=0;j<N;j++){
            sum+=(budget[j])/(i+1);
        }
        maxAns = max(maxAns , sum*Bonus[i]);
    }
    cout<<maxAns<<endl;
    return;
    
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
