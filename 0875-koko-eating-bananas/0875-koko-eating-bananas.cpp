class Solution {
public:
    long long gethours(vector<int>& piles, int k) {
        long long sum = 0;
        for(auto pile : piles) {
            sum += ceil(pile * 1.0 / k);
        }
        return sum;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        int res = (left + right) / 2;
        while(left <= right) {
            int mid = (left + right) / 2;
            long long val = gethours(piles, mid);
            if(val <= h) {
                res = mid;
                right = mid - 1;
            } else { // val > h
                left = mid + 1;
            }
        }
        return res;
    }
};