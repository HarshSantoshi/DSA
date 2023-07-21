#include <bits/stdc++.h> 
using namespace std;
int maxProfit(vector<int>& prices,int n) {
    vector<int>btbs(n,0);
    int leastPrice = prices[0];
    int bestTimeProfit =0;
    for(int i=1;i<n;i++){
        leastPrice = min(leastPrice , prices[i]);
        int profit = prices[i] - leastPrice;
        bestTimeProfit =max(bestTimeProfit, profit);
        btbs[i] = bestTimeProfit;
    }
    vector<int>btss(n,0);
    int bestPrice = prices[n-1];
    int bestBuyProfit = 0;
    for(int i=n-2;i>=0;i--){
        bestPrice = max(prices[i] , bestPrice);
        int profit = bestPrice - prices[i];
        bestBuyProfit = max(bestBuyProfit , profit);
        btss[i] = bestBuyProfit;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans , btbs[i] + btss[i]);
    }
    return ans;
}

int main(){
    vector<int>prices = {6,10,11,4,13,20,5,2,1,7};
    cout<<maxProfit(prices , prices.size())<<endl;
}