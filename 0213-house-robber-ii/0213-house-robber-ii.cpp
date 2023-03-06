class Solution {
public:
    int recurse(vector<int>& nums, vector<vector<int>>& sum, int index, bool first = false) {
        // cout << "index " << index << " " << (first ? "true " : " false ") ;
        if(index >= nums.size()) {
            // cout << endl;
            return 0;
        }
        if(index == nums.size()-1 && first) {   
            // cout << endl;
            return 0;
        }
        
        sum[index][int(first)] = max(
            nums[index] + ((sum[index+2][int(first)] == -1) ? recurse(nums,sum, index+2, first) : sum[index+2][int(first)]),
            (sum[index+1][int(first)] == -1) ? recurse(nums, sum, index + 1, first) : sum[index+1][int(first)]
        );
        // cout << "sum " << sum[index] << endl;
        return sum[index][int(first)];
    }
    
    int rob(vector<int>& nums) {
        vector<vector<int>> sum(nums.size() + 2, {-1, -1});
        return max(
            recurse(nums, sum, 2, true) + nums[0],
            recurse(nums, sum, 1, false)
        );
    }
};