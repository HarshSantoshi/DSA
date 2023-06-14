#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n,max,t,p=0,sec;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    if(n==0||n==1)
    {
       cout<<INT_MIN;
    }
    else
    {
     max=INT_MIN;
     int t;
     for(t=0;t<n;t++)
     {
        if(arr[t]>=max)
        {
            max=arr[t];
            p=t;
        }
     }
     for(int l=0;l<n;l++)
     {
        if(arr[l]==max)
        {
           arr[l]=INT_MIN;
        }
     }
     arr[p]=INT_MIN;
     sec=INT_MIN;
     for(int q=0;q<n;q++)
     {
         if(arr[q]>=sec)
         {
            sec=arr[q];
         }
     }
     cout<<sec;
    }
    return 0;
}