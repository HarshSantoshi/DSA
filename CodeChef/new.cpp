#include<bits/stdc++.h>
using namespace std;
void solve(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    for(int i=0;i<N;i++){
        if(arr[i]==0){
            cout<<"-1"<<endl;
            return;
        }
    }
    sort(arr,arr+N);
    //-6 8 12 17
    //-9 8 12 17
    if(arr[0]>0){
        cout<<arr[0]-1<<endl;
    }
    int i=0;
    while(arr[i]<0){
        i++;
    }
    cout<<i<<endl;
    int ans = abs(min(arr[i] , -arr[i-1]));
    cout<<ans-1<<endl;
    return;

}//-11 -9 -8 6 1
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}