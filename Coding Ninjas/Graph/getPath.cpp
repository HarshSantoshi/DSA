#include <iostream>
#include <queue>
using namespace std;
bool hasPath(int **edges, int v, int sv, int end, bool *visited) {
  if (edges[sv][end] == 1) {
    return true;
  }
  visited[sv] = true;
  bool result = false;
  for (int i = 0; i < v; i++) {
    if (!visited[i] && edges[sv][i] == 1) {
      result = hasPath(edges, v, i, end, visited);
    }
    if (result) {
      return true;
    }
  }
  return result;
}

bool getPath(int **edges, int v, bool *visited, int start, int end ,vector<int>res) {
  
  if (start == end) {
    res.push_back(end);
    return true;
  }


  visited[start] = true;

  bool ans = false;

  for (int i = 0; i < v; i++) {
    if (edges[start][i] == 1 && !visited[i]) 
      ans = getPath(edges, v, visited, i, end, res);
    if (ans == true) {
      res.push_back(start);
      return true;
    }
    }

  return ans;
}

int main() {
  // Write your code here
  int v, e;
  cin >> v >> e;
  int **edges = new int *[v];
  for (int i = 0; i < v; i++) {
    edges[i] = new int[v];
    for (int j = 0; j < v; j++) {
      edges[i][j] = 0;
    }
  }

  for (int i = 0; i < e; i++) {
    int fv, sv;
    cin >> fv >> sv;
    edges[fv][sv] = 1;
    edges[sv][fv] = 1;
  }
  int start, end;
  cin >> start >> end;

  bool *visited = new bool[v];
  for (int i = 0; i < v; i++) {
    visited[i] = false;
  }
  vector<int> res;

  if (getPath(edges, v, visited, start, end, res)){
    for (auto i : res)
      cout << i << " ";
  }
  
  delete[] visited;
  for (int i = 0; i < v; i++)
    delete[] edges[i];

  delete[] edges;

  return 0;
}