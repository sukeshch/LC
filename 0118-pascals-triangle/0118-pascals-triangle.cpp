class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result; 
        result.push_back({1});
        if(numRows-- == 1) return result;
        result.push_back({1, 1,});
        if(numRows-- == 1) return result;
        
        while(numRows > 0) {
            vector<int> row = {1};
            
            for(int i = 0; i + 1 < result.back().size(); i++) {
                row.push_back(result.back()[i] + result.back()[i+1]);
            }
            
            row.push_back(1);
            result.push_back(row);
            numRows--;
        }
        return result;
    }
};