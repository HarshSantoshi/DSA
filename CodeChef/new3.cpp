#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int N , Q;
    cin>>N>>Q;
    vector<int>arr(N,0);
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    vector<pair<int,int>>queries;
    for(int i=0;i<Q;i++){
        int a , b ;
        cin>>a>>b;
        pair<int,int>p;
        p.first=a;
        p.second=b;
        queries.push_back(p);
    }
    
    for(int i=0;i<Q;i++){
        int left = queries[i].first;
        cout<<"left"<<left<<endl;
        
        int right = queries[i].second;
        cout<<"right"<<right<<endl;
        int Damage = arr[left-1];
        // cout<<"DA"<<Damage<<endl;
        int ans =Damage;
        for(int j=left;j<=right;j++){
            if(arr[j]==ans){
                ans--;
            }
            else if(arr[j]>ans){
                Damage++;
                ans=Damage;
            }
            cout<<"ans"<<ans<<" ";
        }
        cout<<endl;
        cout<<Damage<<endl;
    }
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
// 2
// 5 3
// 1 3 2 2 1
// 2 4
// 3 4
// 4 5
// 9 4
// 5 6 3 5 4 4 3 2 1
// 1 3
// 2 6
// 3 7
// 6 9