#include <iostream>
#include <algorithm>
using namespace std;
void sortZeroesAndOne(int *a, int size)
{
    int i=0,j=size-1;
    while(i<j){
        if(a[i]==0 && a[j]==1){i++;j--;}
       
        if(a[i]==1 && a[j]==1){j--;}
          
         if(a[i]==1 && a[j]==0){
                int temp =a[i];
                a[i]=a[j];
                a[j]=temp;
                j--;i++;
            
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
		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		sortZeroesAndOne(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}