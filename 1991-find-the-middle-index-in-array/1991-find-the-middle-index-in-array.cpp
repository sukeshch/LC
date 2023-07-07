class Solution {
public:
    int findMiddleIndex(vector<int>& v) {
        int sum = std::reduce(v.begin(), v.end());
        int left = 0, right = sum;
        for(int i=0; i<v.size(); i++) {
            right -= v[i];
            if(left == right)
                return i;
            left += v[i];
        }
        return -1;
    }
};