    pair<int,int> operator+(pair<int,int> const &a, pair<int,int> const &b) 
    {
        return {a.first + b.first, a.second + b.second};
    }
class Solution {
public:
    
    inline bool isvalid(pair<int,int> const &pos, int &ct, vector<vector<int>>& grid, map<pair<int,int>, pair<int,int>> &mp) 
    {
        if ( 0 <= pos.first && pos.first < grid.size() && 
          0 <= pos.second && pos.second < grid[0].size() && 
          grid[pos.first][pos.second] == 0 && mp[pos].second == ct) {
            return true;
        }
        return false;
    }
    
    void BFS(pair<int,int> pos, int ct, 
            map<pair<int,int>, pair<int,int>> &mp, 
            vector<vector<int>>& grid) 
    {
        static vector<pair<int,int>> dirs{ {1,0}, {-1,0}, {0,1}, {0,-1} };
        int min_dist = INT_MAX;
        
        queue<pair<int,int>> Q;
        map<pair<int,int>, bool> visited;
        Q.push(pos);
        visited[pos] = true;
        
        int distance = 1;
        while(!Q.empty()) 
        {
            for(int sz = Q.size(), i=0; i<sz; i++) 
            {
                auto f = Q.front();
                Q.pop();
                for(auto d : dirs) 
                {
                    auto p = f + d;
                    if (isvalid(p, ct, grid, mp) && !visited[p]) 
                    {
                        mp[p] = mp[p] + std::pair<int,int>({distance, 1});
                        Q.push(p);
                    }
                }
            }
            distance ++;
        }
    }
    
    int shortestDistance(vector<vector<int>>& grid) 
    {        
        queue<pair<int,int>> Q;
        
        // pos --> {dist, count}
        map<pair<int,int>, pair<int,int>> mp;
        
        for (int i=0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++) 
            {
                if(grid[i][j] == 1) 
                {
                    Q.push({i,j});
                    mp[{i,j}] = {0,0};
                }
            }
        }
        int max_count = Q.size(), count = 0, res = INT_MAX;
        while(!Q.empty()) 
        {
            BFS(Q.front(), count, mp, grid);
            std::cout << "{" << Q.front().first << "," << Q.front().second << "} res : " << res << endl;
            Q.pop();
            count++;
            
        }
        
        for(auto [_, val] : mp) {
            if (val.second == max_count) {
                res = min(res, val.first);
            }
        }
        
        return res == INT_MAX ? -1 : res;
    }
};