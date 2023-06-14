
#include <iostream>
using namespace std;

#include<unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    // Write your code here
    unordered_map<int,int>map;
    int max=0;
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum==0){
            max=i+1;
        }
        else if(map.find(sum)!=map.end()){
            if(max<i-map[sum]){
            max=i-map[sum];
            }
        }
        else{
        map[sum]=i;
        }
        
    }
    return max;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}