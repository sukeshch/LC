class Solution {
public:
    vector<vector<int>> result;
    int R,C;
    vector<vector<bool>> crPc, crAt;
    
    vector<vector<int>> dirs = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };
    
    void dfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, int r, int c) {
        if(visited[r][c])
            return;
        visited[r][c] = true;
        if(crPc[r][c] && crAt[r][c]) result.push_back({r, c});
        
        for(auto dir : dirs) {
            int r1 = r + dir[0], c1 = c + dir[1];
            
            if(0 <= r1 && r1 < R && 0 <= c1 && c1 < C 
               && heights[r][c] <= heights[r1][c1]) 
                dfs(heights, visited, r1, c1);
        }
        
    }
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        R = heights.size();
        C = heights[0].size();
        
        crPc = vector<vector<bool>>(R, vector<bool>(C, false));
        crAt = vector<vector<bool>>(R, vector<bool>(C, false));
        
        for(int col = 0; col < C; col++) {
            dfs(heights, crPc, 0, col);
            dfs(heights, crAt, R-1, col);
        }
        
        for(int row = 0; row < R; row++) {
            dfs(heights, crPc, row, 0);
            dfs(heights, crAt, row, C-1);
        }
        
        return result;
    }
};