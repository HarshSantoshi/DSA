#include<iostream>
using namespace std;

bool checkMember(int n){
    int n1=0,n2=1;
     int n3;
     n3=n1+n2;
    if(n==0||n==1){
        true;
    }
   while(n3<n){
       n1=n2;
       n2=n3;
       n3=n1+n2;  
   }
    if(n3==n){
           true;
       }else {
        return false;
    }


}

int main(){

  int n; 
  cin >> n ;
  if(checkMember(n)){
    cout << "true" << endl;
  }else{
    cout << "false" << endl;
  }

}


