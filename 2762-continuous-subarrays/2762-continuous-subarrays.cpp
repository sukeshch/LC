class Solution {
public:
    bool isValid(map<int, int> &curr_elems) {
        return (curr_elems.rbegin()->first - curr_elems.begin()->first) <= 2;
    }
    
    /*
        Brute force: N * 1 + N/2*2 + N/3*3 + * (N^2)
        Cache brute force: (bottom up)
        ++ how to ignore sub array with max > 2 already
        - store size 1
        - store size 2
        - calculate i using (i-1) range = constant operations for min and max

        ++ maybe top down (largest contiguos sub array is faster?) 
     */
    long long continuousSubarrays(vector<int>& nums) {
        int N = nums.size();
        std::map<int, int> curr_elems;
        int left = 0, right = 0;
        long long result = 0;
        int curr_min = nums[right], curr_max = nums[right];
        
        for (right = 0; right < N; right++) {
            curr_min = min(curr_min, nums[right]);
            curr_max = max(curr_max, nums[right]);
            
            if (curr_max - curr_min > 2) {
                long long w_len = right - left;
                result += ((w_len * (w_len + 1)) / 2);
                
                left = right;
                curr_min = curr_max = nums[right];
                
                while (left > 0 && abs(nums[right] - nums[left-1]) <= 2) {
                    left--;
                    curr_min = min(curr_min, nums[left]);
                    curr_max = max(curr_max, nums[left]);
                }
                
                if (left < right) {
                    long long w_len = right - left;
                    result -= ((w_len * (w_len + 1)) / 2);
                }
            }
        }
        
        long long w_len = right - left;
        result += ((w_len * (w_len + 1)) / 2);
        
        return result;
    }
};

/** brute force
        for (int sz = 2; sz <= N; sz++) {
            bool found_valid_curr_sz = false;
            
            for (int start = 0; start <= N-sz; start++) {
                
                int min_value = INT_MAX, max_value = INT_MIN;
                for (int i = 0; i < sz; i++) {
                    // calculate in range [start + i, start + sz-1]
                    
                    min_value = min(min_value, nums[start + i]);
                    max_value = max(max_value, nums[start + i]);
                    
                    if (max_value - min_value > 2) break;
                }
                if (abs(max_value - min_value) <= 2) {
                    result++;
                    found_valid_curr_sz = true;
                }
            }
            if (!found_valid_curr_sz) break;
        }
optimized bf

// override arrays as we increment size of array
        vector<int> max_arr(nums);
        vector<int> min_arr(nums); 
        
        long long result = N; // one sized sub array
        
        for (int sz = 2; sz <= N; sz++) {
            bool found_valid_curr_sz = false;
            
            for (int start = 0; start <= N-sz; start++) {
                
                min_arr[start] = min(nums[start + sz-1], min_arr[start]);
                max_arr[start] = max(nums[start + sz-1], max_arr[start]);
                
                if (max_arr[start] - min_arr[start] <= 2) {
                    result++;
                    found_valid_curr_sz = true;
                }
            }
            if (!found_valid_curr_sz) break;
        }

// 
        while (right < N) {
            curr_elems[nums[right]]++;
            
            while (!isValid(curr_elems)) {
                curr_elems[nums[left]]--;
                if(curr_elems[nums[left]] == 0)
                    curr_elems.erase(nums[left]);
                left++;
            }
            result += (right - left + 1);
            right++;
        }
**/