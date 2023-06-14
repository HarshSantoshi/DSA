#include<iostream>

using namespace std;
int partition( int input[],int si, int ei){
     
     int pivot = input[si];
     int count =0;
    for(int i=si+1;i<=ei;i++){
        if(input[i]<=pivot){
            count++;
        }
    }
    int pivotindex =si+count;
    int temp = input[si];
    input[si]=input[pivotindex];
    input[pivotindex]=temp;
    int i=si, j= ei;
   while(i< pivotindex &&j> pivotindex){

        if(input[i]<=pivot){
            i++;
        }
        else if(input[j]>pivot){
            j--;
        }
       else{
                int temp = input[i];
                input[i]=input[j];
                input[j]=temp;
                j--;
                i++;
       }
    }
    return pivotindex;

}
void helper( int input [], int si , int ei){
    if(si>=ei){
        return;
    }
    int c = partition(input,si,ei);
    
    helper(input,si,c-1);
    helper(input,c+1,ei);

}
void quickSort(int input[], int size) {
    if(size<=1){
        return;
    }
    helper(input,0,size-1);
}




int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


