#include <iostream>
#include<unordered_map>
using namespace std;

#include<unordered_map>

int pairSum(int *arr, int n) {
    int count = 0;
    unordered_map<int, int> ump;
    for (int i = 0; i < n; i++){
        if (ump.count(-1 * arr[i]) > 0){
            count += ump[-1 * arr[i]];
        }
        ump[arr[i]]++;
    }
    
    return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}