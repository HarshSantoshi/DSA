#include <iostream>
using namespace std;


void mergetwo(int input[],int si, int mid ,int ei){
    int i = si;
    int j= mid+1;
    int k=0;
    int *output= new int[ei-si+1];
    while(i<=mid && j<=ei){
        if(input[i]<=input[j]){
            output[k++]=input[i++];
        }
        if(input[j]<=input[i]){
            output[k++]=input[j++];
        }
    }
    while(i<=mid){
        output[k++]=input[i++];
    }
    while(j<=ei){
        output[k++]=input[j++];
    }
    for(int i=0 ,j =si;i<ei-si+1;i++,j++){
        input[j]=output[i];
    }
}
void mergesmall(int input[],int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = si+(ei-si)/2;//si+ei)/2=mid = si+(ei-si)/2=en+(si-en)/2
    mergesmall(input,si,mid);
    mergesmall(input,mid+1,ei);
    mergetwo(input,si,mid,ei);
    
}
void mergeSort(int input[], int size){
	// Write your code here
    if(size<=1){
        return;
    }
   mergesmall(input , 0, size -1);     
}



// void merge(int input1[], int size1, int input2[], int size2, int output[]) 
// { 
//     int i = 0, j = 0, k = 0; 
    
//     while (i < size1 && j < size2) 
//     { 
//         if (input1[i] < input2[j]) 
//         {
//             output[k] = input1[i]; 
//             k++; 
//             i++;
//         } 
        
//         else 
//         { 
//             output[k] = input2[j]; 
//             j++; 
//             k++; 
//         } 
//     } 
    
//     while (i < size1) 
//     { 
//         output[k] = input1[i]; 
//         k++; 
//         i++; 
//     } 
    
//     while (j < size2) 
//     { 
//         output[k] = input2[j]; 
//         j++; 
//         k++; 
//     } 
// } 

// void mergeSort(int input[], int size) 
// { 
//     if (size <= 1) 
//     { 
//         return; 
//     } 
    
//     int mid = size / 2;

//     int part1[500], part2[500]; 
    
//     int size1 = mid, size2 = size - mid; 
    
//     for (int i = 0; i < mid; i++) 
//     { 
//         part1[i] = input[i]; 
//     } 

//     int k = 0; 

//     for (int i = mid; i < size; i++) 
//     { 
//         part2[k] = input[i]; 
//         k++; 
//     } 
    
//     mergeSort(part1, size1); 
//     mergeSort(part2, size2); 
    
//     merge(part1, size1, part2, size2, input); 
// }
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}