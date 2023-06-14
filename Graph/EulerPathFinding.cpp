//https://leetcode.com/problems/reconstruct-itinerary/description/
class Solution {
public:
 unordered_map<string, priority_queue<string, vector<string> , greater <string>>>adj ;
    void dfs( string src , vector<string>&ans ){
        auto & dst = adj[src];

        while(!dst.empty()){
            string airport = dst.top();
            dst.pop();
            dfs( airport , ans);
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        // for (auto& route : adj) {
        //     sort(route.second.begin(), route.second.end());
        //     cout<<route.first<<":";
        //     for(auto i:route.second){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<string>ans;
        
        dfs("JFK"  , ans);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};