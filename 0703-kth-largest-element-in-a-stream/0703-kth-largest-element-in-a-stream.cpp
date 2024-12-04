class KthLargest {
    priority_queue<int, std::vector<int>, std::greater<int>> pq_;
    int k_;
public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        for(auto num : nums) {
            pq_.push(num);
            if(pq_.size() > k)
                pq_.pop();
        }
    }
    
    int add(int val) {
        pq_.push(val);
        if(pq_.size() > k_) pq_.pop();
        return pq_.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */