#include <iostream>
#include <cstring>
using namespace std;

void removeAllOccurrencesOfChar(char s[], char c) {
    int i=0,j=0;
    while(i<strlen(s)){
        if(s[i]==c){
            i++;
        }
        else{
            s[j]=s[i];
            j++;
            i++;
        }
    }
    s[j]='\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}