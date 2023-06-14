#include <iostream>
#include <string>
using namespace std;

# include <stack>
bool isBalanced(string exp){
	stack<char> s1;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='('){
            s1.push(exp[i]);
        }
        else if (exp[i]==')'){
            if(s1.empty()){
                return false;
            }
            char topChar = s1.top();
            s1.pop();
            if(exp[i]==')' && topChar == '('){
                continue;
            }
            else {
                return false;
            }
        }
    }
    return s1.empty();
    }

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}