class Solution {
public:
    #define INF 2147483647
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        vector<vector<bool>> visited(rooms.size(), vector<bool>(rooms[0].size()));
        queue<pair<int,int>> q;
        
        for(int row=0; row<rooms.size(); row++) {
            for (int col=0; col<rooms[0].size(); col++) {
                if(rooms[row][col] == 0) {
                    q.push({row, col});
                    visited[row][col] = true;
                }
            }
        }
        vector<vector<int>> dirs{{-1,0}, {1,0}, {0,-1}, {0,1}};
        int depth = 1;
        while(!q.empty()) {
            for(int i=0, sz = q.size(); i < sz; i++) {
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto dir: dirs) {
                    x += dir[0], y+= dir[1];
                    if( x >=0 && x < rooms.size() && 
                        y >=0 && y < rooms[0].size() &&
                        rooms[x][y] == INF && 
                        !visited[x][y]) {
                        rooms[x][y] = depth;
                        visited[x][y] = true;
                        q.push({x,y});
                    }
                    x -= dir[0], y-= dir[1];
                }
            }
            depth++;
        }
    }
};