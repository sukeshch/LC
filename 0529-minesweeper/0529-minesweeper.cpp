class Solution {
    vector<vector<int>> DIRS{{0, 1}, {0, -1},  {1, 0},  {-1, 0},
                             {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};

public:
    // DFS to find connected empty cells
    void UpdateBlankNeighbors(vector<vector<char>>& board, int startRow,
                              int startCol, int M, int N) {
        stack<int> st;
        st.push(startRow * N + startCol);
        unordered_set<int> visited;
        visited.insert(st.top());

        board[startRow][startCol] = 'B';

        while (!st.empty()) {
            int top = st.top();
            st.pop();
            int col = top % N, row = top / N;
            int adj_mine_count = AdjMines(board, row, col, M, N);
            // std::cout << "adj_mine_count: " << adj_mine_count << " {"<< row << ", " << col << "}";

            if (adj_mine_count > 0) {
                board[row][col] = '0' + adj_mine_count;
                // std::cout << " HERE\n";
            } 
            else {
                // board[row][col] = 'B';
                std::cout << std::endl;
                for (auto dir : DIRS) {
                    row += dir[0];
                    col += dir[1];
                    if (0 <= row && row < M && 0 <= col && col < N &&
                        board[row][col] == 'E') {
                        board[row][col] = 'B';
                        st.push(row * N + col);
                        visited.insert(st.top());
                    }
                    row -= dir[0];
                    col -= dir[1];
                }
            }

        }
    }

    int AdjMines(vector<vector<char>>& board, int row, int col, int M, int N) {
        int adj_mine_count = 0;
        for (auto dir : DIRS) {
            row += dir[0];
            col += dir[1];
            if (0 <= row && row < M && 0 <= col && col < N &&
                board[row][col] == 'M') {
                adj_mine_count++;
            }
            row -= dir[0];
            col -= dir[1];
        }
        // std::cout << "adj_mine_count " << adj_mine_count << std::endl;
        return adj_mine_count;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board,
                                     vector<int>& click) {
        int row = click[0], col = click[1];
        int M = board.size(), N = board[0].size();

        if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } else if (board[row][col] == 'E') {
            UpdateBlankNeighbors(board, row, col, M, N);
        }
        return board;
    }
};