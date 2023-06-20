#include <bits/stdc++.h>
using namespace std;
vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> solve(string digits)
{
    if (digits.length() == 0)
    {
        vector<string> temp;
        temp.push_back("");
        return temp;
    }
    char ch = digits[0];
    string newString = digits.substr(1);
    vector<string> sans = solve(newString);
    vector<string> ans;
    string codeforch = mappings[ch - '0'];
    for (int i = 0; i < codeforch.length(); i++)
    {
        char chcode = codeforch[i];
        for (string smallstr : sans)
        {
            ans.push_back(chcode + smallstr);
        }
    }
    return ans;
}
vector<string> letterCombinations(string digits)
{
    vector<string> ans;
    if (digits.length() == 0)
    {
        return ans;
    }
    ans = solve(digits);
    return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> res = letterCombinations(s);
    for (auto i : res)
    {
        cout << i << " ";
    }
}