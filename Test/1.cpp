#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<bits/stdc++.h>

bool possible(int mid ,  vector<int>&arr , int size , int N){
    int cnt =0;
    int sum =0;
    for(int i=0;i<size;i++){
        if(arr[i]>mid){
            return false;
        }
        sum+=arr[i];
        if(sum>mid){
            cnt ++;
            sum =arr[i];
        }
    }
    cnt ++;
    if(cnt<=N){
        return true;
    }
    return false;
}
int Helper(vector<int>&arr , int size , int N , int low , int high){
    int ans =0;
    while(low<=high){
        int mid = low + (high- low)/2;
        if(possible(mid , arr , size , N)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
void solve(){
    int N , M;
    cin>>N>>M;
    vector<int>arr(M,0);
    for(int i=0;i<M;i++){
        int a ;
        cin>>a;
        arr[i] = a;
    }
    int sum =0;
    int mxEle = 0;
    for(int i=0;i<M;i++){
        sum+= arr[i];
        mxEle = max(mxEle , arr[i]);
    }
    int ans = Helper(arr , M , N , mxEle , sum);
    cout<<ans<<endl;
    
}

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}