class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        int counter1 = 0, counter2 = 0;
        while(counter1 < A.size() && counter2 < B.size()) {
            if(min(A[counter1][1], B[counter2][1])-max(A[counter1][0], B[counter2][0]) >= 0) { // no overlap 
                // if(A[counter1][0] > B[counter2][0]) {
                //     counter2++;
                // }
                // else {
                //     counter1++;
                // }
                // continue;
                result.push_back({max(A[counter1][0], B[counter2][0]), min(A[counter1][1], B[counter2][1]), });
            }
            if(A[counter1][1] > B[counter2][1])
            {
                counter2++;
            }
            else counter1++;
        }
        
        return result;
    }
};