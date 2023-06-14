#include <iostream>
#include <string>
#include <cstring>
#include<vector>
using namespace std;

void printPermutationsHelper(string input, string output)
{
    if (input.empty())
    {
        // cout << output << endl;
        ans.push_back(output);
        return;
    }
    for (int i = 0; i < input.length(); i++)
    {
        string rest = input.substr(0, i) + input.substr(i + 1);
        printPermutationsHelper(rest, output + input[i]);
    }
}

void printPermutations(string input)
{
   
    printPermutationsHelper(input, "");
   for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
   }
     return ;
}
 


int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}