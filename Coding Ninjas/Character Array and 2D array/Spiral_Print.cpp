#include <iostream>
using namespace std;

void spiralPrint(int **input, int m, int n)
{
  int i,k=0,l=0;
  int last_row=m-1, last_col=n-1;
  while(k<=last_row && l<= last_col){
      for(i=l ; i<=last_col;i++){
          cout<<input[k][i]<<" ";
      }
      k++;
      for(i=k;i<=last_row;i++){
          cout<<input[i][last_col]<<" ";
      }
      last_col--;
      if(k<=last_row){
          for(i=last_col;i>=l;i--){
              cout<<input[last_row][i]<<" ";
          }
          last_row--;
      }
      if(l<=last_col){
          for(i=last_row;i>=k;i--){
              cout<<input[i][l]<<" ";
          }
          l++;
      }
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
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}