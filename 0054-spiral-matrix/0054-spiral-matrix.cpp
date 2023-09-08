class Solution {
public:
    vector<pair<int, int>> directions = {
        {0, 1}, {1,0}, {0, -1}, {-1, 0} 
    };
    int id;
    auto nextDirection() {
        return directions[id++ % 4];
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        id = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count_visited = 0;
        pair<int, int> pos = {0, 0};
        vector<int> result;
        
        auto dir = nextDirection();
        
        while(true) {
            // set visited and push to result
            count_visited++;
            visited[pos.first][pos.second] = true;
            result.push_back(matrix[pos.first][pos.second]);
            cout << "result: back " << dir.first << "," << dir.second << " --" << result.back() << " " << pos.first << "," << pos.second << endl;
            if(count_visited == rows * cols) break;
            
            while(pos.first + dir.first < 0 || 
                  pos.second + dir.second < 0 ||
                !(pos.first + dir.first < rows) || 
              !(pos.second + dir.second < cols) ||
              visited[pos.first + dir.first][pos.second + dir.second]) {
                dir = nextDirection();
                // cout << "nextDir" << endl;
            }
            pos.first += dir.first;
            pos.second += dir.second;
        }
        return result;
    }
};