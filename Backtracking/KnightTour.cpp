#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> &chess, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
}
void knightTour(vector<vector<int>> &chess, int r, int c, int move)
{
    if (r < 0 || c < 0 || r >= chess.size() || c >= chess.size() || chess[r][c] > 0)
    {
        return;
    }
    else if (move == chess.size() * chess.size())
    {
        chess[r][c] = chess.size() * chess.size();
        print(chess, chess.size());
        chess[r][c] = 0;
        return;
    }
    chess[r][c] = move;
    knightTour(chess, r - 2, c + 1, move + 1);
    knightTour(chess, r - 1, c + 2, move + 1);
    knightTour(chess, r + 1, c + 2, move + 1);
    knightTour(chess, r + 2, c + 1, move + 1);
    knightTour(chess, r + 2, c - 1, move + 1);
    knightTour(chess, r + 1, c - 2, move + 1);
    knightTour(chess, r - 1, c - 2, move + 1);
    knightTour(chess, r - 2, c - 1, move + 1);
    chess[r][c] = 0;
}
int main()
{
    int n = 5;
    vector<vector<int>> chess(n, vector<int>(n, 0));

    knightTour(chess, 2, 2, 1);
}