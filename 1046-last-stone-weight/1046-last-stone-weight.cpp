class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq_; // max heap
        for(auto stone : stones)
            pq_.push(stone);
        
        while(pq_.size() > 1) {
            auto s1 = pq_.top();
            pq_.pop();
            auto s2 = pq_.top();
            pq_.pop();
            
            if(s1 != s2)
                pq_.push(abs(s1-s2));
        }
        
        return pq_.size() ? pq_.top() : 0;
    }
};