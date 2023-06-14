#include <iostream>
#include <queue>
using namespace std;

bool isConnected(int **edges, int v, int sv, bool *visited)
{
  queue<int> pendingVertices;
  pendingVertices.push(sv);
  visited[sv] = true;

  while (!pendingVertices.empty())
  {
    int currentVertex = pendingVertices.front();
    pendingVertices.pop();
    visited[currentVertex] = true;
    for (int i = 0; i < v; i++)
    {
      if (i == currentVertex)
      {
        continue;
      }
      if (edges[currentVertex][i] == 1 && !visited[i])
      {
        pendingVertices.push(i);
        visited[i] = true;
      }
    }
  }
  for (int i = 0; i < v; i++)
  {
    if (visited[i] == false)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  // Write your code here
  int v, e;
  cin >> v >> e;
  int **edges = new int *[v];
  for (int i = 0; i < v; i++)
  {
    edges[i] = new int[v];
    for (int j = 0; j < v; j++)
    {
      edges[i][j] = 0;
    }
  }

  for (int i = 0; i < e; i++)
  {
    int fv, sv;
    cin >> fv >> sv;
    edges[fv][sv] = 1;
    edges[sv][fv] = 1;
  }
  bool *visited = new bool[v];
  for (int i = 0; i < v; i++)
  {
    visited[i] = false;
  }

  if (isConnected(edges, v, 0, visited))
  {
    cout << "true" << endl;
  }
  else
  {
    cout << "false" << endl;
  }
}