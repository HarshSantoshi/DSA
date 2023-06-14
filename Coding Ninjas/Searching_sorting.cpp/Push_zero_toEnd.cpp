#include <iostream>
using namespace std;

void pushZeroesEnd(int a[], int size)
{   int k=0;
   for(int i=0;i<size;i++){
       if(a[i]!=0){
           int temp = a[i];
           a[i]=a[k];
           a[k]=temp;
           k++;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}