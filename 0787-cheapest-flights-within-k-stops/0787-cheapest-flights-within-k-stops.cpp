class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        std::vector<int> dp(n, std::numeric_limits<int>::max()); 
        
        // src --> dst, wt
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto f : flights) 
        {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        // id, cur_price
        std::queue<pair<int,int>> q;
        q.push({src, 0});
        dp[src] = 0;
        int stops = 0;
        while(!q.empty() && stops < k+1)
        {
            for(int i=0, sz=q.size(); i<sz; i++)
            {
                const auto [node, cur_wt] = q.front();
                q.pop();
                
                for(const auto &[dst, wt] : adj[node]) {
                    if (wt + cur_wt >= dp[dst]) continue;
                    
                    q.push({dst, wt+cur_wt});
                    
                    dp[dst] = min(dp[dst], wt+cur_wt);
                }
            }
            stops++;
        }
        
        return dp[dst] == std::numeric_limits<int>::max() ? -1 : dp[dst];
    }
};