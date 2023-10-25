class Solution {
    vector<vector<bool>> visited;
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int M, N;
    int dfs(vector<vector<int>>& grid, int r, int c) {
        stack<pair<int,int>> st;
        int count = 0;
        visited[r][c] = true;
        st.push({r,c});
        while(!st.empty()) {
            auto t = st.top();
            st.pop();
            count++;
            for (auto d : dirs) {
                int r1 = t.first+d[0], c1 = t.second+d[1];
                if( 0 <= r1 && r1 < M && 
                    0 <= c1 && c1 < N && 
                   grid[r1][c1] == 1 && !visited[r1][c1]
                  ) {
                    visited[r1][c1] = true;
                    st.push({r1,c1});
                }
            }
        }
        return count;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result = 0;
        M = grid.size();
        N = grid[0].size();
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for(int row = 0; row < M; row++) {
            for(int col = 0; col < N; col++) {
                if(grid[row][col] == 1 && !visited[row][col]) {
                    result = max(result, dfs(grid, row, col));
                }
            }
        }
        return result;
    }
};