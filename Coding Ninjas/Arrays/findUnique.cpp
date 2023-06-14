#include <iostream>

using namespace std;
int findUnique(int a[], int n)
{
    for(int i=0;i<n;i++){
        int j=0;
        for(;j<n;j++){
        
            if(i!=j&&a[i]==a[j]){
                break;
            }
    	}
        
        if(j==n){
            return a[i];
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

		cout << findUnique(input, size) << endl;
	}

	return 0;
}