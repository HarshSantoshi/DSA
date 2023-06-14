#include <iostream>
using namespace std;
void print(int **edges , int v ,int sv , bool *visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<v;i++){
        if(i==sv){
            continue;
        }
        if(edges[sv][i]==1){
            if(visited[i]){
                continue;
            }
            print(edges, v , i , visited);
        }

    }
}
int main()
{
    int v;
    int e;
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

    for(int i=0;i<e;i++){
        int fv ,sv;
        cin>>fv>>sv;
        edges[fv][sv]=1;
        edges[sv][fv]=1;
    }
    bool*visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    print(edges ,v ,0 , visited);
    delete []visited;
    
}