class Solution {
public:
    int recurse(vector<int>& heights, vector<int> &dp, int curr_pos, int bricks, int ladders)
    {
        if (curr_pos+1 == dp.size()) {
            return curr_pos;
        }
        int ht_diff = heights[curr_pos + 1] - heights[curr_pos];
        
        if (ht_diff <= 0)
            return recurse(heights, dp, curr_pos+1, bricks, ladders);
        
        int max_with_ladder = curr_pos;
        if(ladders)
            max_with_ladder = recurse(heights, dp, curr_pos+1, bricks, ladders-1);
        int max_with_bricks = curr_pos;
        if(bricks >= ht_diff)
            max_with_bricks = recurse(heights, dp, curr_pos+1, bricks-ht_diff, ladders);
        
        return max(max_with_ladder, max_with_bricks);
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // return recurse(heights, dp, 0, bricks, ladders);
        
        std::priority_queue<int, vector<int>, greater<int>> pq;
        long long curr_tot_sum = 0;
        
        int pos = 0;
        for(; pos < (heights.size()-1); pos++) {
            if (heights[pos+1] <= heights[pos])
                continue;
            
            if (ladders < 0 && bricks <= 0) {
                break;
            }
            
            pq.push(heights[pos+1] - heights[pos]);
            ladders--;
            
            if(ladders < 0) {
                if (bricks < pq.top())
                    break;
                bricks -= pq.top();
                pq.pop();
            }
        }
        
        return pos;
    }
};