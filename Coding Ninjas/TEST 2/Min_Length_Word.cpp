#include<iostream>

using namespace std;
#include<string.h>
#include<climits>
void minLengthWord(char input[], char output[]){
    int n=strlen(input);
    int mini=INT_MAX;
    int start=-1;
    int cnt=0;
    for(int i=0;i<=n;i++){
        if(input[i]!=' ' && i!=n){
            cnt++;
        }
         else if(cnt<mini||(i==n &&cnt<mini)){
            mini=cnt;
            start=i-mini;
            cnt=0;
        }
        else{
            cnt=0;
        }
     }
    for(int i=0;i<mini;i++){
         output[i]=input[i+start];
    }
}




int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
