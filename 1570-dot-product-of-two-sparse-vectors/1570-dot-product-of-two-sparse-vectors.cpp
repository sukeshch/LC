class SparseVector {
    unordered_map<int, int> data_;
    int sz_;
public:
    
    SparseVector(vector<int> &nums) {
        sz_ = nums.size();
        for(int i=0; i < sz_; i++)
            if(nums[i])
                data_[i] = nums[i];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for(auto [k, v] : vec.data_) {
            if(data_.count(k) != 0)
                result += v * data_[k];
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);