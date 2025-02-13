class SubrectangleQueries {
    vector<vector<int>> rectangle_;
    vector<vector<int>> subr_;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        swap(rectangle_, rectangle);
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        subr_.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for (int itr = subr_.size()-1; itr >= 0; itr--) {
            if (subr_[itr][0] <= row && subr_[itr][1] <= col && row <= subr_[itr][2] && col <= subr_[itr][3]) {
                return subr_[itr][4];
            }
        }
        return rectangle_[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */