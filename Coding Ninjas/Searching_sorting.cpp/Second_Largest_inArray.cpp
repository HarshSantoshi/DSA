#include <iostream>
using namespace std;

#include<climits>
int findSecondLargest(int arr[], int n){
int largest =INT_MIN ; int sec_largest = INT_MIN;
for(int i=0;i<n;i++){
    if(arr[i]>largest){
        sec_largest=largest;
        largest = arr[i];
    }
    else if(arr[i]> sec_largest && arr[i]< largest){
        sec_largest =arr[i];
    }
}
 return sec_largest;
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

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}