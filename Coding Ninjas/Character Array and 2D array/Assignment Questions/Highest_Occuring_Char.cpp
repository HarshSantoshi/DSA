#include <iostream>
#include <cstring>
using namespace std;

char highestOccurringChar(char s[]) {
    // Write your code here
    int freq[256]={0};
    int n =strlen(s);
    for(int i=0;i<n;i++){
        freq[s[i]]++;
    }
    int max=-1;
    char ans;
    for(int i=0;i<n;i++){
        if(max<freq[s[i]]){
            max=freq[s[i]];
            ans=s[i];
        }
    }
    return ans;
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    cout << highestOccurringChar(str);
}