class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        vector<vector<int>> dirs{{1,0}, {-1,0}, {0,1}, {0,-1}};
        queue<pair<int, int>> q;
        int count = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
                if(grid[i][j] == 1) count++;
            }
        }
        if(count == 0) return 0;
        
        while(!q.empty()) {
            cout << q.size() << endl;
            for(int i=0, sz=q.size(); i<sz; i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto d : dirs) {
                    x += d[0], y += d[1];
                    if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1){
                        cout << x << "," << y << " : " << grid[x][y] << endl;
                        grid[x][y] = 0;
                        count--;
                        q.push({x,y});
                    }
                    x -= d[0], y -= d[1];
                }
            }
            res++;
        }
        if(count != 0) return -1;
        return res-1;
    }
};