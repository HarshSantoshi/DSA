#include <iostream>
using namespace std;
int duplicateNumber(int a[], int n)
{
    int count=0;
    for(int i=0;i<n;i++){
        count=0;
        for(int j=0;j<n;j++){
            if(i !=j && a[i]==a[j]){
                 return a[i];
                break;
            }
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

		cout << duplicateNumber(input, size) << endl;
	}

	return 0;
}