#include <bits/stdc++.h>
using namespace std;
long long countWays(int n, int k)
{
    // code here
    if (n <= 1)
    {
        return k;
    }
    long long same = k;
    long long diff = k * (k - 1);
    int mod = 1e9 + 7;
    long long total = same + diff;
    for (int i = 3; i <= n; i++)
    {
        same = (diff) % mod;
        diff = ((total) * (k - 1)) % mod;
        total = (same + diff) % mod;
    }

    return (total) % mod;
}
int main(){
    int n  , k;
    cin>>n>>k;
    cout<<countWays(n,k)<<endl;
}