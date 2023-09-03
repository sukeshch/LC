class Solution {
public:
    int target = 0;
    int N = 0;
    // unordered_map<string, bool> memo;
    
//     bool recurse(string taken, string key, vector<int> &nums, int sum, int idx) { //  int N, int target
//         // cout << "recurse:: " << taken << memo.size() << endl;
//         if(memo.count(key) != 0) {
//             // cout << "recurse::yey dp" << endl;
//             return memo[key];
//         }
//         if(idx >= N) return memo[key] = false;
//         if(sum > target) return memo[key] = false;
//         if (sum == target) {
//             return memo[key] = true;
//         }
        
//         // taken case
//         taken[idx] = '-';
//         key[nums[idx]] = char( int(key[nums[idx]]-'0') + 1 + '0'); 
//         sum += nums[idx];
//         // cout << "recursion level +1" << endl;
//         if(recurse(taken, key, nums, sum, idx+1)) {
//             return memo[taken] = true;
//         }
//         // cout << "recursion level -1" << endl;
//         key[nums[idx]] = char( int(key[nums[idx]]-'0') - 1 + '0'); 
//         sum -= nums[idx];
//         taken[idx] = '*';
        
//         // not taken case
//         if(recurse(taken, key, nums, sum, idx+1)) {
//             return memo[taken] = true;
//         }
        

//         return memo[key] = false;
//     }
    vector<vector<optional<bool>>> memo;
    bool recurse(vector<int> &nums, int sum, int idx) {
        if(idx == N || sum > target) return false;
        if(sum == target) return true;
        if(memo[idx][sum] != nullopt)
            return (memo[idx][sum] == true);
        bool val = (recurse(nums, sum+nums[idx], idx + 1) || recurse(nums, sum, idx + 1));
        memo[idx][sum] = val;
        return  memo[idx][sum] == true;
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        target = sum / 2;
        N = nums.size();
        // * = not taken
        // - = taken
        // string taken(N, '*');
        // string key(101, '0');
        // cout << "canPartition::base taken " << taken << endl;
        memo = vector<vector<optional<bool>>>(N + 1, vector<optional<bool>>(target + 1, nullopt));
        return recurse(nums, 0, 0);
    }
};