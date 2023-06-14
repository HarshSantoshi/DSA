#include <iostream>
using namespace std;

void wavePrint(int **input, int r, int c)
{
   int i=0;
   int j=0;
   while(j<c){
       if(j%2==0){
           i=0;
           while(i<r){
               cout<<input[i][j]<<" ";
               i++;
           }
       }
       else{
           i=r-1;
           while(i>=0){
               cout<<input[i][j]<<" ";
               i--;
           }

       }
       j++;
   }
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;
		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}
		wavePrint(input, row, col);
		cout << endl;
	}
}