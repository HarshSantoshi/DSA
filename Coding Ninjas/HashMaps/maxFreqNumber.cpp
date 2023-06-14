#include <iostream>
#include <unordered_map>
using namespace std;

int highestFrequency(int *input, int n)
{

    unordered_map<int, int> count;
    int maxFreq = 0;
    int maxAns = 0;
    for (int i = 0; i < n; i++)
    {
        count[input[i]]++;
        maxFreq = max(maxFreq, count[input[i]]);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxFreq == count[input[i]])
        {

            maxAns = input[i];
            break;
        }
    }
    return maxAns;
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}