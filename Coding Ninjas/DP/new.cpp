#include <iostream>
using namespace std;

void solve(int *arr, int *operationArray, int n, int m)
{
    int *result = new int[n];
    for (int k = 0; k < n; k++)
    {
        result[k] = arr[k];
    }
    // for(int k=0;k<n;k++){
    //     cout<<result[k]<<endl;
    // }
    for (int i = 0; i < m; i = i + 2)
    {
        int leftindex = operationArray[i];
        int rightindex = operationArray[i + 1];
        int count = 0;
        for (int j = leftindex; j <= rightindex; j++)
        {
            if (count % 2 == 0)
            {
                result[j-1]++;
                count++;
            }
            else
            {
                result[j-1]--;
                count++;
            }
        }
    }
    // for(int k=0;k<n;k++){
    //     cout<<result[k]<<endl;
    // }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + result[i];
    }
    cout<< sum;
}

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, operations;
        cin >> n >> operations;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int *operationArray = new int[2 * operations];
        for (int i = 0; i < 2 * operations; i++)
        {
            cin >> operationArray[i];
        }

        solve(arr, operationArray, n, 2 * operations);
        
    }
    return 0;
}
