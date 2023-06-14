#include <iostream>
using namespace std;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int size;
	    cin>>size;
	    char *arr = new char[size];
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
        int count =0;
        for(int i=0;i<size;i++){
            if(arr[i] == 'a' ||arr[i] =='e' ||arr[i] =='i' || arr[i] =='o' ||arr[i] =='u'){
                count =0;          
            }
            else{
                count++;
                if(count>=4){
            cout<<"NO";
            break;
        }
            }
        }
        if(count<=4){
            cout<<"YES";
        }
        
	}
	return 0;
}
