#include <iostream>
#include <cstring>
using namespace std;


void reverseEachWord( char a[]){
    int i,j,k;
    char temp;
    for(i=j=k=0;a[i];i++){
        if(a[i]==' ' || a[i+1]=='\0'){
            for (k=(a[i]==' '?i-1:i);j<k;j++,k--){
                temp=a[j];
                a[j]=a[k];
                a[k]=temp;
            }
            j=i+1;
        }
    }
}


int main() {
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}