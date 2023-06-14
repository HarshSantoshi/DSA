//https://leetcode.com/problems/min-cost-to-connect-all-points/description/
class Solution {
public:
    int find(int v , vector<int>&parent){
        if(v== parent[v]){
            return v;
        }
        return parent[v] = find(parent[v] , parent);
    }
    bool Union(int u  , int v , vector<int>&parent , vector<int>&size){
        u = find(u , parent);
        v = find(v , parent);
        if(u==v){
            return 0;
        }
        if(size[u]>size[v]){
            parent[v] = u;
            size[u]+=size[v];
        }
        else{
            parent[u] = v;
            size[v]+=size[u];
        }
        return 1;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<n;i++){
            for(int j=i+1 ;j<n;j++){
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({distance , {i , j}});
            }
        }
        sort(edges.begin() , edges.end());
        int numEdges =0;
        vector<int>parent(n);
        vector<int>size(n);
        for(int i=0;i<n;i++){
            parent[i] =i;
            size[i] =1;
        }
        int ans =0;
        for(int i=0;i<edges.size() && numEdges<n-1;i++){
            if(Union(edges[i].second.first , edges[i].second.second ,parent , size)){
                ans += edges[i].first;
                numEdges ++;
            }
        }
        return ans;


    }
};