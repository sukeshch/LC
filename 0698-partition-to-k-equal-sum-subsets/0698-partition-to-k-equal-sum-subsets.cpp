class Solution {
public:
    bool recurse(int nidx, bitset<16> b,  
                 int distribute, 
                 vector<int>& nums, 
                 int k, int bucket, int prev_index = 0)    {
        if(nidx == k - 1) {
            return true;
        }
        
        for(int i=prev_index; i < nums.size(); i++) {
            if(!b.test(i)) {
                if(distribute + nums[i] > bucket) continue;
               
                b.set(i);
                distribute += nums[i];
                if(recurse(
                    (distribute == bucket)
                        ? nidx + 1 : nidx, 
                    b, 
                    (distribute ==  bucket) ? 0 : distribute, 
                    nums, k, bucket, 
                (distribute ==  bucket) ? 0 : i))
                    return true;
                distribute -= nums[i];
                b.reset(i);
            }
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto n : nums) sum += n;
        if(sum % k != 0) return false;
        bitset<16> b(0);
        sort(nums.begin(), nums.end(), std::greater<int>());
        return recurse(0, b, 0, nums, k, sum/k);
    }
};