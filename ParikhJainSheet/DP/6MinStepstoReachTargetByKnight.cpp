#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, int tx, int ty, int size , int steps)
{
    static int k = 0;
    if (i == tx && j == ty)
    {
        return steps;
    }

    if (i > 0 && j > 0 && i <= size && j <= size)
    {
        return 1 + min({solve(i - 2, j + 1, tx, ty, size , steps+1),
                        solve(i - 2, j - 1, tx, ty, size , steps+1),
                        solve(i - 1, j + 2, tx, ty, size , steps+1),
                        solve(i - 1, j - 2, tx, ty, size , steps+1),
                        solve(i + 2, j - 1, tx, ty, size , steps+1),
                        solve(i + 2, j + 1, tx, ty, size , steps+1),
                        solve(i + 1, j + 2, tx, ty, size , steps+1),
                        solve(i + 1, j - 2, tx, ty, size , steps+1)});
    }
    return INT_MAX-1;
}
int minSteps(pair<int, int> knightPosition, pair<int, int> targetPosition, int size)
{
    // Write your code here.
    int i = knightPosition.first;
    int j = knightPosition.second;
    int tx = targetPosition.first;
    int ty = targetPosition.second;

    int ans = solve(i, j, tx, ty, size , 0);
    if (ans == INT_MAX - 1)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int main()
{
    pair<int, int> knightPosition, targetPosition;
    knightPosition.first = 2;
    knightPosition.second = 1;
    targetPosition.first = 8;
    targetPosition.second = 5;
    int size = 8;
    cout << minSteps(knightPosition, targetPosition, size);
}