class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int curr = 0;
        priority_queue<int, vector<int>, greater<int>> mh;
        while(curr+1 < heights.size()) {
            if(heights[curr] < heights[curr+1]) {
                mh.push(heights[curr+1]-heights[curr]);
                if(ladders > 0) {
                    ladders--;
                }
                else {
                    if(bricks >= mh.top()) {
                        bricks -= mh.top();
                        mh.pop();
                    }
                    else 
                        return curr;
                }
            }
            curr++;
        }
        return curr;
    }
};