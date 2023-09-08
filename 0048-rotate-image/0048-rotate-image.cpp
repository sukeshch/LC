class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        int row_min = 0, col_min = 0, 
            row_max = matrix.size()-1, col_max = matrix.size()-1;
        int len = matrix.size();
        while(len > 1) {
            for(int index = 0; index < (len - 1); index++) {
                int temp = matrix[row_min][col_min + index];
                matrix[row_min][col_min + index] = matrix[row_max-index][col_min]; // LB->LT
                matrix[row_max-index][col_min] = matrix[row_max][col_max-index];
                matrix[row_max][col_max-index] = matrix[row_min + index][col_max];
                matrix[row_min + index][col_max] = temp;
            }
            len -= 2;
            row_min ++;
            col_min ++;
            row_max --;
            col_max --;
        }
    }
};