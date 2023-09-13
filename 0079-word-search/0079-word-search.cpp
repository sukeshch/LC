class Solution {
public:
    vector<vector<int>> dirs{{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<bool>> visited;
    string target;
    int R, C;
    
    bool recurse(vector<vector<char>>& board, int tindex, vector<int> pos) {
        // printf("index : %d @ (%d, %d)\n", tindex, pos[0], pos[1]);
        if(tindex == target.size())
            return true;
        visited[pos[0]][pos[1]] = true;
        
        for(auto d : dirs) {
            vector<int> p ={pos[0]+d[0],pos[1]+d[1]};
            if ( 0 <= p[0] && p[0] < R && 0 <= p[1] && p[1] < C && 
                 !visited[p[0]][p[1]] && board[p[0]][p[1]] == target[tindex]
               ) {
                if(recurse(board, tindex+1, p))
                    return true;
            }
        }
        visited[pos[0]][pos[1]] = false;
        return false;
    }
    
    bool isWordOnBoard(vector<vector<char>>& board, string word) {
        int counts[60]{0};
        for(auto c : word)
            counts[c-'A']++;
        int bcounts[60]{0};
        for(auto row : board) {
            for(auto element : row) {
                bcounts[element-'A']++;
            }
        }
        for(int i=0; i<60; i++) {
            if(counts[i] !=0 && counts[i] > bcounts[i])
                return false; 
        }
        return true;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(!isWordOnBoard(board, word))
            return false;
        
        R = board.size();
        C = board[0].size();
        target = word;
        vector<pair<int,int>> pos;
        
        visited = vector<vector<bool>>(board.size(), vector<bool>(board[0].size(), false));
        
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(board[row][col] == word[0]) {
                    pos.push_back({row, col});
                }
            }
        }
        
        int index = word[0] - 'A';
        for(int i = 0; i < pos.size(); i++) {
            int r = pos[i].first, c = pos[i].second;
            visited[r][c] = true;
            if(recurse(board, 1, {r, c})) {
                return true;
            }
            visited[r][c] = false;
        }
        
        return false;
    }
};