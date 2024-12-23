class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        int num_swaps = 0, pos = 0;
        long long prefix_sum = 0;
        
        std::priority_queue<int, vector<int>, greater<int>> pq;
        
        while (pos < nums.size()) {
            if (nums[pos] < 0)
                pq.push(nums[pos]);
            
            prefix_sum += nums[pos];
            
            if (prefix_sum < 0) {
                num_swaps++;
                nums.push_back(pq.top());
                prefix_sum -= pq.top();
                pq.pop();
            }
            pos++;
        }
        
        return num_swaps;
    }
};