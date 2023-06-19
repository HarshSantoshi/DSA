void find(vector<vector<int>> &adj, int src, int parent, vector<int> &dis, vector<int> &low, vector<int> &vis, vector<vector<int>> &ans)
{
    vis[src] = true;
    static int time = 0;
    dis[src] = low[src] = ++time;
    for (auto neighbor : adj[src])
    {
        if (neighbor == parent)
        {
            continue;
        }
        else if (vis[neighbor] == true)
        {
            low[src] = min(low[src], dis[neighbor]);
        }
        else
        {
            find(adj, neighbor, src, dis, low, vis, ans);

            low[src] = min(low[src], low[neighbor]);

            if (low[neighbor] > dis[src])
            {
                ans.push_back({src, neighbor});
            }
        }
    }
}