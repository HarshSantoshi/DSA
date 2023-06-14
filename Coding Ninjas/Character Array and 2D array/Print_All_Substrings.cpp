
// For a given input string(str), write a function to print all the possible substrings.
#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(char input[]) {
    // Write your code here
   int m =0;
   while(input[m] !='\0'){
        for(int i=m;i<=strlen(input);i++){
            for(int j=m;j<i;j++){
                cout<<input[j];
            }
             cout<<endl;
        }
        
         m++;
         }
    }

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}