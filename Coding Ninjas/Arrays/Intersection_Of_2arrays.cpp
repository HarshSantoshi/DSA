#include <iostream>
#include <algorithm>
using namespace std;
#include<climits>
void intersection(int arra[], int arrb[], int a, int b)
{
  
    for(int i=0;i <a;i++){
        for(int j=0;j<b;j++){
            if(arra[i]==arrb[j]){
               cout<<  arra[i]<<" ";
                arrb[j] = INT_MAX;
                // arrb[j]=INT_MIN;
                
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

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}