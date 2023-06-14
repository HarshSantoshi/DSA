#include <iostream>

using namespace std;
int len(char input[]){
    int length = 0;
    for(int i=0;input[i]!='\0';i++){
        length++;
    }
    return length;
}
void pairS(char input[] , int start){
    if(input[start]=='\0'){
        return;
    }
    pairS(input,start +1);
    if(input[start]==input[start +1]){
        int n= len(input);
        input[n+1]='\0';
        for(int i=n-1;i>=start+1;i--){
            input[i+1]=input[i];
        }
        input[start +1]='*';
    }
}
void pairStar(char input[]) {
    // Write your code here
    pairS(input,0);
}
int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
