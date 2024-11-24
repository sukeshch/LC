class Solution {
public:
    bool isValid (int r, int c, vector<vector<int>>& grid)
    {
        if ( 0 <= r && r < grid.size() && 0 <= c && c < grid[0].size() )
        {
            return true;
        }
        return false;
    }
    
    vector<vector<int>> neighbors(int r, int c, vector<vector<int>>& grid)
    {
        static vector<vector<int>> DIRs{{0,1}, {0,-1}, {1,0}, {-1,0}};
        
        vector<vector<int>> res;;
        for (auto d : DIRs) 
        {
            if( isValid(r + d[0], c+d[1], grid) && 
                grid[r][c] > grid[r + d[0]][c + d[1]] )
            {
                res.push_back({r + d[0], c + d[1]});
            }
        }
        
        std::sort(res.begin(), res.end(), 
            [&grid](vector<int> const &left, vector<int> const& right) {
                return grid[left[0]][left[1]] > grid[right[0]][right[1]];
            });
        return res;
    }
    
    
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &vis) 
    {
        if(dp[r][c] != -1) 
        {
            return dp[r][c];
        }
        auto ns = neighbors(r, c, grid);
        
        int res = 1;
        
        for(auto n : ns)
        {
            if(!vis[n[0]][n[1]]) {
                vis[n[0]][n[1]] = true;
                dfs(n[0], n[1], grid, vis);
            }
            res += dp[n[0]][n[1]];
            res %= mod;
        }
        
        res %= mod;
        dp[r][c] = res;
        // printf("{%d, %d} : %lld\n", r, c, res);
        return dp[r][c];
    }
    
    int countPaths(vector<vector<int>>& grid) 
    {
        vector<vector<int>> visited (grid.size(), vector<int>(grid[0].size(), 0));
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));
        long long result = 0;
        
        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j=0; j < grid[0].size(); j++)
            {
                if(!visited[i][j]) {
                    dfs(i, j, grid, visited);
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                answer += dp[i][j];
                answer %= mod;
            }
        }
        return answer;
    }
    
    int mod = 1000000007;
    vector<vector<int>> dp;
};