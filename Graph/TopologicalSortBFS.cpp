
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<int>inorder(V,0);
	    for(int i=0;i<V;i++){
	       for(int j=0;j<adj[i].size();j++){
	           inorder[adj[i][j]]++;
	       }
	    }
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(inorder[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int size = q.size();
	        while(size--){
	            int curr = q.front();
	            q.pop();
	            ans.push_back(curr);
	            for(auto child : adj[curr]){
	                inorder[child]--;
	                if(inorder[child]==0){
	                    q.push(child);
	                }
	            }
	        }
	    }
	    return ans;
	}
};
