class Solution {
public:
    bool isValid(pair<int,int> &point, vector<vector<int>>& grid) {
        return ( point.first >= 0 && point.first < grid.size() && 
                 point.second >= 0 && point.second < grid[0].size() &&
                 grid[point.first][point.second] == 0
               );
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        vector<pair<int,int>> DIR{{1,1}, {1,0}, {0,1}, {1,-1}, {-1,1}, {-1,-1},{-1,0}, {0,-1}};
    
        if (grid[0][0] != 0 || grid[grid.size()-1][grid[0].size()-1] != 0) {
            return -1;
        }
        
        queue<pair<int,int>> st;
        bool visited[101][101] = {false};
        
        st.push({0,0});
        visited[0][0] = true;
        
        int depth = 1;
        while(!st.empty()) {
            // std::cout << "visited[2][2]: " << std::boolalpha << visited[2][2] << endl;
            for(int i = 0, sz = st.size(); i < sz; i++) {
                auto t = st.front();
                st.pop();

                if(t.first == grid.size()-1 && t.second == grid[0].size()-1) {
                    return depth;
                }
                
                for (auto d : DIR) {
                    pair<int,int> new_point = {t.first + d.first, t.second + d.second};

                    if(isValid(new_point, grid) && !visited[new_point.first][new_point.second]) {
                        visited[new_point.first][new_point.second] = true;
                        st.push(new_point);
                    }
                }
            }
            depth++;
        }
        
        return -1;
    }
};