class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        vector<vector<int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    // cout << i << "," << j << endl;
                    stack<pair<int,int>> st;
                    st.push({i,j});
                    visited[i][j] = true;
                    while(!st.empty()) {
                        int x = st.top().first, y = st.top().second;
                        st.pop();
                        for(auto d : dirs) {
                            x += d[0], y += d[1];
                            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {} 
                            else if(grid[x][y] == '1' && !visited[x][y]) {
                                st.push({x, y});
                                visited[x][y] = true;
                            }
                            x -= d[0], y -= d[1];
                        }
                    }
                    res++;
                    // cout << "res\n";
                }
            }
        }
        return res;
    }
};