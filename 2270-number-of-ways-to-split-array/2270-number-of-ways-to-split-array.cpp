class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> sums(n+1, 0);
        sums[0] = nums[0];        
        for(int i=1; i<n; i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        int result = 0;
        for(int i=0; i<(n-1); i++) {
            if(sums[i] >= sums[n-1]-sums[i])
                result++;
        }
        return result;
    }
};