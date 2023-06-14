#include <iostream>
#include<unordered_map>
using namespace std;

// int getPairsWithDifferenceK(int *arr, int n, int k) {
// 	// Write your code here
//     unordered_map<int,int>freq;
//      int count=0;
//     for(int i=0;i<n;i++){
//         freq[arr[i]]++;
//     }
   
//     for(int i=0;i<n;i++){
//          int search;
//         if(k<=arr[i])
//         search=(arr[i]-k);
//         else{
//        search = k+arr[i];
//         }
//         if(freq[search]>0){
//             if(k!=0)
//             {count=count+freq[search];
//             freq[arr[i]]=0;}
            
//             else{
//                 count=count+((freq[search])*(freq[search]-1))/2;
//                 freq[arr[i]]=0;
//             }
            
//         }
//     }
//     return count;
// }
#include<unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int>map;
    for(int i=0;i<n;i++){
        ++map[arr[i]];
    }
    int pairs=0;
       for(int i=0;i<n;i++){
           if(map[arr[i]-k]>0){
               --map[arr[i]];
               pairs+=map[arr[i]-k];
           }
           if(map[arr[i]+k]>0){
               --map[arr[i]];
               pairs+=map[arr[i]+k];
           }
           
       }
    return pairs;
}

int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}