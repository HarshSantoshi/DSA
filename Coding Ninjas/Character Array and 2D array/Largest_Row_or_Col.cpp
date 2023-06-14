
#include <iostream>
using namespace std;
#include<climits>
void findLargest(int **input, int nRows, int mCols)
{
    //Write your code here
    int rowsum=0,colsum=0,maxr=INT_MIN,maxc=INT_MIN,maxridx=0,maxcidx=0;
    for(int i=0;i<nRows;i++)
    {
        rowsum=0;
        for(int j=0;j<mCols;j++)
        {
            rowsum+=input[i][j];
        }if(rowsum>maxr)
        {
            maxr=rowsum;
            maxridx=i;
        }
    }
    for(int i=0;i<mCols;i++)
    {
        colsum=0;
        for(int j=0;j<nRows;j++)
        {
            colsum+=input[j][i];
        }
        if(colsum>maxc)
        {
            maxc=colsum;
            maxcidx=i;
        }
    }
    if(maxc>maxr)
    {
        cout<<"column"<<" "<<maxcidx<<" "<<maxc<<endl;
    }else
        cout<<"row "<<maxridx<<" "<<maxr<<endl;
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

		findLargest(input, row, col);
		cout << endl;
	}
}