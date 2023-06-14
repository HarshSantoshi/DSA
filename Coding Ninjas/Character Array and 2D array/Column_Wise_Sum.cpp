#include<iostream>
using namespace std;


int main(){
      int m ,n;
    cin>>m>>n;
    int input[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
        }   
    }
    for(int t=0;t<n;t++){
        int sum=0;
        for(int k=0;k<m;k++){
            sum=sum+input[k][t];
        }
        cout<<sum<<" ";
    }
  
}
