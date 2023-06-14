
/*Ques:Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.*/
#include <iostream>

using namespace std;
#include<cstring>
bool checkAB(char input[]) {
	// Write your code here
    int n= strlen(input);
    if(n==0){
        return 1;
    }
    if(input[0]=='a'){
       if(strlen(input+1) >1 && input[1]=='b' && input [2]=='b'){
           return checkAB (input+3);
       }
        else {return checkAB(input+1);}
    }
    else{
        return false;
    }

}




int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
