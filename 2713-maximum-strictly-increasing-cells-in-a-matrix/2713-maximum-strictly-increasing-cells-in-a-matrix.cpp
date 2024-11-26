class Solution {
public:
    struct node {
        int val;
        int r;
        int c;
    };
    /*
    1 2 0 3
    7 5 1 3
    4 6 9 4
    8 3 7 4
    */
    int maxIncreasingCells(vector<vector<int>>& mat) {
        vector<node> cells(mat.size() * mat[0].size());
        for (int i=0; i < mat.size(); i++)
        {
            for (int j=0; j < mat[0].size(); j++)
            {
                cells[i * mat[0].size() + j] = {mat[i][j], i, j};
            }
        }
        sort(cells.begin(), cells.end(), [](node const& l, node const& r) {
            return l.val > r.val;
        });
        vector<int> dp_rows(mat.size(), 0);
        vector<int> dp_cols(mat[0].size(), 0);
        int result = 1;
        
        for (int i = 0; i < cells.size(); ) {
            map<int, int> row_val; //(mat.size(), 0);
            map<int, int> col_val; //(mat[0].size(), 0);
            
            int curr_cell_val = cells[i].val;
            while (i < cells.size() && curr_cell_val == cells[i].val) {
                // process
                int r = cells[i].r, c = cells[i].c;
                
                result = max(result, 1 + max(dp_rows[r], dp_cols[c]));
                
                row_val[r] = max(1 + max(dp_rows[r], dp_cols[c]), row_val[r]);
                col_val[c] = max(1 + max(dp_rows[r], dp_cols[c]), col_val[c]);
                i++;
            }
            // update dp 
            for(auto v : row_val) dp_rows[v.first] = max(v.second, dp_rows[v.first]);
            for(auto v : col_val) dp_cols[v.first] = max(v.second, dp_cols[v.first]);
        }
        
        return result;
    }
};