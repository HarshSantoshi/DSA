#include<iostream>
#include<climits>
using namespace std;
void Leaders(int* arr,int len)
{
    int i=0;
    int j;
    while(i<len)
    {
        j=i+1;
        while(j<len){
            if(arr[i]>=arr[j]){
                if(j == len-1){
                    cout<<arr[i]<<" ";
                }
            }
            else
                break;
      j++;      
        }
        i++;
    }
    cout<<arr[len-1]<<" ";
	
}
int main()
{
    int len;
    cin>>len;
	int *arr = new int[len + 1];
	
	for(int i=0;i<len;i++)
	{
		cin>>arr[i];
	}
	Leaders(arr,len);
}
