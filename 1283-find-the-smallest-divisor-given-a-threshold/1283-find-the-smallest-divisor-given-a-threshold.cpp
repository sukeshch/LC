class Solution {
public:
    int getDivisorSum(vector<int>& nums, int divisor) {
        int sum = 0;
        for(auto n : nums) {
            sum += ceil((float) n / (float) divisor);
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int res = -1;
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while(low <= high) {
            int mid = (low + high) / 2;
            int ct = getDivisorSum(nums, mid);
            if (ct <= threshold) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};