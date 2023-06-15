//https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1
#include<bits/stdc++.h>
using namespace std;
string printMinNumberForPattern(string S)
{
    // code here
    int n = S.length();
    int num = 1;
    string ans = "";
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (S[i] == 'D')
        {
            st.push(num);
            num++;
        }
        else
        {
            st.push(num);
            num++;
            while (!st.empty())
            {
                ans += to_string(st.top());

                st.pop();
            }
        }
    }
    st.push(num);
    while (!st.empty())
    {
        ans += to_string(st.top());

        st.pop();
    }
    return ans;
}
int main(){
    string s = "DIIDDI";
    string ans = printMinNumberForPattern(s);
    cout<<ans<<endl;
    return 0;
}