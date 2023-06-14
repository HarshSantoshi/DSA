#include <iostream>
using namespace std;
#include <string.h>

void printAllPossibleCodes_(string a , string output[] , int m )
{
    if((a.empty()))
    {
        for(int i = 0 ; i < m ; i++)
        {
            cout << output[i];
        }
        cout << endl;
        return;
    }
    if(a[0] >= '1' && a[0] <= '9')
    {
    int alphaInt = a[0] - '0';
    output[m] = alphaInt + 'a' - 1; 
    printAllPossibleCodes_(a.substr(1) ,output , m+1);
    }
    int alphaInt1 = 10*(a[0] - '0') + a[1] - '0';
    if(alphaInt1 >= 10 && alphaInt1 <= 26)
    {
        output[m] = alphaInt1 + 'a' - 1;
        printAllPossibleCodes_(a.substr(2) , output , m+1);
    }
}
void printAllPossibleCodes(string input) {
    string output[10000];
    printAllPossibleCodes_(input , output , 0);
}



int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
