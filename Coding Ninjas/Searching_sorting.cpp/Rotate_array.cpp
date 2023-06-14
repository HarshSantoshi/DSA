#include <iostream>
using namespace std;

void rotate(int a[], int d, int n)
{
    int temp[d];
    int m=d;
    int i=0;
    while(m>0)
    {
        temp[d-m]=a[i];
        m--;
        i++;
    }
    for(int i=0;i<n-d;i++){
        a[i]=a[i+d];
    }

    for(int i=0;i<d;i++)
        a[n-d+i]=temp[i];
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

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}