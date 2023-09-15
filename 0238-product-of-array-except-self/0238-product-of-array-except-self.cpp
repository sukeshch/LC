class Solution {
public:
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size() + 2, 1);
        vector<int> right(nums.size() + 2, 1);
        
        for(int i=0; i<nums.size(); i++)
            left[i+1] = left[i] * nums[i];
        
        for(int i=nums.size(); i>0; i--)
            right[i] = right[i+1] * nums[i-1];
        
        vector<int> result(nums.size(), 1);
        for(int i=0; i<nums.size(); i++) {
            result[i] = left[i] * right[i+2];
        }
        return result;
    }
    */
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N, 1);
        
        result[0] = nums[0];
        for(int i=1; i < N; i++) 
            result[i] = result[i-1] * nums[i];

        int curr = 1;
        for(int i = N-1; i>=1; i--) {
            result[i] = curr * result[i-1];
            curr = curr * nums[i];
        }
        result[0] = curr;
        return result;
    }
};