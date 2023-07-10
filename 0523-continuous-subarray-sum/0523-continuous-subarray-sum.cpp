
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    	// initialize the hash map with index 0 for sum 0
        unordered_map<int, int> hashMap;
        hashMap[0] = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (hashMap.find(sum % k) == hashMap.end())
                hashMap[sum % k] = i + 1;
            else if (hashMap[sum % k] < i)
                return true;
        }
        return false;
    }
};