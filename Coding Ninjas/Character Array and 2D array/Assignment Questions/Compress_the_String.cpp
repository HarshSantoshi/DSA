#include <iostream>
#include <cstring>
#include<string>
using namespace std;

string getCompressedString(string &input) {
    // Write your code here.
    int len = input.length(); // find length of the string
    char output[len];  // create a new array of same length as input array
    int j = 0;
    for(int i = 0; i < len; i++) {
        output[j] = input[i];
        j++;
        int count = 1;
        while(input[i] == input[i+1]) {
            count++;
            i++;
        }
        if(count > 1) {
            output[j] = '0' + count;  // assigning the char value of count
            j++;
        }
    }
    output[j] = '\0';  // append null character at last
    return output;
}

int main() {
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    cout << str << endl;
}