#include <iostream>
using namespace std;
#include<string>

void printSubsetsOfArrayUtility(int input[], int i, int size, string output){
    if(i == size){
        cout << output << endl;
        return;
    }
    printSubsetsOfArrayUtility(input, i + 1, size, output);
    string firstInteger = to_string(input[i]);
    printSubsetsOfArrayUtility(input, i + 1, size, output + firstInteger + " ");
    return;
}
void printSubsetsOfArray(int input[], int size) {
    string output;
    int i = 0;
    printSubsetsOfArrayUtility(input, i, size, output);
    return;
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
