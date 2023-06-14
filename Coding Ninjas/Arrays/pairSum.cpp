#include <iostream>
using namespace std;

int pairSum(int *a, int size, int x)
{int count =0;
	for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(j>i){
                if(a[i]+a[j]==x){
                  count++;
                }
            }
        }
    }
    if(count>0){
        return count;
    }
    else{return 0;}
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

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}