class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minv = INT_MAX, maxv = INT_MIN;
        for(auto n : nums)
        {
            minv = std::min(minv, n);
            maxv = std::max(maxv, n);
        }
        if(maxv - minv - 2 * k <= 0) return 0;
        return (maxv - minv - 2 * k);
        
    }
};