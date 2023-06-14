#include <iostream>
#include <algorithm>
using namespace std;

void sort012(int a[], int n)
{
    int m,l,h;
    m=0;l=0;h=n-1;
    while(m<=h){
        if(a[m]==0){
            int temp =a[l];
            a[l]=a[m];
            a[m]=temp;
            m++;
            l++;
        }
        else if(a[m]==1){
            m++;
        }
        else if(a[m]==2){
            int temp =a[h];
            a[h]=a[m];
            a[m]=temp;
            
            h--;
        }
    }
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;

		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}