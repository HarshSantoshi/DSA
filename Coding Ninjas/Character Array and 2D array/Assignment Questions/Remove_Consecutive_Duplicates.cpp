#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char s[]) {
    int i=1;
    int j=1;
    char last_char=s[0];
    while(s[i]!='\0'){
        if(s[i]==last_char)
        {
            i++;
        }
        if(s[i]!=last_char)
        {
            s[j]=s[i];
            j++;
            last_char=s[i];
            i++;
        }
      
        
    }
s[j]='\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}