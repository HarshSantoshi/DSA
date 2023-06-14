#include <iostream>
using namespace std;

int tripletSum(int *input, int size, int x)
{   int count=0;
	for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            for(int k=j+1;k<size;k++){
                if(input[i]+input[j]+input[k]==x){
                    count++;
                }
            }
        }
    }
    if(count>0){
        return count;
    }
    else{
        return 0;
    }
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}