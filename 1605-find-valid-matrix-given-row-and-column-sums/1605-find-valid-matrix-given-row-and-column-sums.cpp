class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size(), cols = colSum.size();
        vector<vector<int>> result(rows, vector<int>(cols, 0));
        
        int crow = 0, ccol = 0;
        while(crow < rows && ccol < cols) {
            result[crow][ccol] = min(rowSum[crow], colSum[ccol]);
            
            rowSum[crow] -= result[crow][ccol];
            colSum[ccol] -= result[crow][ccol];
            
            if(rowSum[crow] == 0) {
                crow++;
            } else {
                ccol++;
            }
        }
        
        return result;
    }
};