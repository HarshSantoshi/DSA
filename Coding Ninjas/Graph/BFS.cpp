#include<iostream>
#include<queue>
using namespace std;

void printBFS(int **edges , int v , int sv ){
    queue<int>pendingVertices;
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }
    pendingVertices.push(sv);
    visited[sv]=true;
    while(!pendingVertices.empty()){
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();
        cout<<currentVertex<<endl;
        visited[currentVertex]=true;
        for(int i=0;i<v;i++){
            if(i==currentVertex){
                continue;
            }
            if(edges[currentVertex][i]==1 && !visited[i]){
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
}

int main(){

    int v , e;
    cin>>v>>e;
    int **edges = new int *[v];

    for(int i=0;i<v;i++){
        edges[i] =new int[v];
        for(int j=0;j<v;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int fv , sv;
        cin>>fv>>sv;
        edges[fv][sv]=1;
        edges[sv][fv]=1;
    }
   
    printBFS(edges , v , 0 );
}