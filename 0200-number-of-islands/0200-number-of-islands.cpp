class Solution {
public:
    vector<pair<int,int>> dirs = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };
    
    int R, C;
    void mark_reachable(vector<vector<char>>& grid, int row, int col) {        
        stack<pair<int,int>> st; 
        grid[row][col] = '0';
        st.push({row, col});
        
        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            for(auto dir : dirs) {
                int row = dir.first + top.first;
                int col = dir.second + top.second;
                if( 0 <= row && row < R && 
                    0 <= col && col < C && grid[row][col] == '1') {
                    st.push({row, col});
                    grid[row][col] = '0';
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        R = grid.size();
        C = grid[0].size();
        int num_islands = 0;
        for(int row = 0; row < grid.size(); row++) {
            for(int col = 0; col < grid[0].size(); col++) {
                if(grid[row][col] == '1') {
                    num_islands++;
                    mark_reachable(grid, row, col);
                }
            }
        }
        return num_islands;
    }
};