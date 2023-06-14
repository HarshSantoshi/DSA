#include<vector>
// Function to detect cycle in a directed graph.
bool detectCycle(vector<int>adj[] , int src , vector<bool>&vis , vector<bool>&pathVis){
    vis[src] =true;
    pathVis[src] = true;
    for(auto child : adj[src]){
        if(vis[child]==false){
            if(detectCycle(adj , child , vis , pathVis)){
                return true;
            }
        }
        if(pathVis[child]==true){
            return true;
        }
    }
    pathVis[src] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {

    vector<bool>vis(V,false);
    vector<bool>pathVis(V,false);
    
    for(int i=0;i<V;i++){
        if(vis[i]==false){
            if(detectCycle(adj , i  , vis , pathVis)){
                return true;
            }
        }
    }
    return false;
}

