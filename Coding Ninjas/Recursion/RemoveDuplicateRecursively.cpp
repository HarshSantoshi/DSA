#include <iostream>
using namespace std;
#include<cstring>
void removeConsecutiveDuplicates(char *input) {
	if(input[0]=='\0'){
        return ;
    }
    removeConsecutiveDuplicates(input+1);
    if(input[0]==input[1]){
        for(int i=1;i<=strlen(input);i++){
            input[i-1]=input[i];
        }
    }
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}